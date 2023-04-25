#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->key <<" ";
        traverseInOrder(root->right);
    }

}

struct node* new_node(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insertNode(struct node *node, int key) {
  if (node == NULL)
        return new_node(key);
 
    
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
 
    
    return node;


}
struct node* min_value_node(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)
        return root;
 
    if (key <= root->key)
        root->left = deleteNode(root->left, key);
 
    
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    
    else {
        
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        
        else if (root->left == NULL) {
            struct node* tempory = root->right;
            free(root);
            return tempory;
        }
        else if (root->right == NULL) {
            struct node* tempory = root->left;
            free(root);
            return tempory;
        }
 
        
        struct node* tempory = min_value_node(root->right);
        root->key = tempory->key;
 
        root->right = deleteNode(root->right, tempory->key);
    }
    return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}