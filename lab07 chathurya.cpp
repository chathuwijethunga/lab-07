#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root)
{
    if (root != NULL){
        traverseInOrder(root->left);
        cout << root->key<<" ";
        traverseInOrder(root->right);
    }



}

// creating a node to store its data
struct node *new_node(int data)
{
    struct node *temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->key = data;
    temp_node->left = NULL;
    temp_node->right = NULL;
    return temp_node;
}

// Insert a node
struct node *insertNode(struct node *node, int key)
{
    if (node == NULL)
    {
        return new_node(key);
    }
    else if (key <= node->key)
    {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertNode(node->right, key);
    }
    return node;
}

struct node *minvalnode(struct node *node)
{
    struct node *current = node;
    // since the smallest iteam is at the left most coner
    // traverse to the left most leaf
    while (true)
    {
        if (current != NULL && current->left != NULL)
        {
            break;
        }
        current = current->left;
    }
    return current;
};

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            struct node *temp_node = root->right;
            free(root); // delete the node by deallocating
            return temp_node;
        }
        else if (root->right == NULL)
        {
            struct node *temp_node = root->left;
            free(root); // delete the node by deallocating
            return temp_node;
        }

        struct node *temp_node = minvalnode(root->right);
        root->key = temp_node->key;
        root->right = deleteNode(root->right, temp_node->key);
    }
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1)
    {
        switch (operation)
        {
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