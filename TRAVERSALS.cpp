#include <iostream>
using namespace std;

struct Node 
{
  int key;
  struct Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) 
{
  if (root != nullptr)
  {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

//Preorder traversal
void traverseInOrder(struct Node *root) 
{
  if (root != nullptr)
  {
    cout << root->key << " ";
    traverseInOrder(root->left);
    traverseInOrder(root->right);
  }
}

//Postorder traversal
void traverseInOrder(struct Node *root) 
{
  if (root != nullptr)
  {
    traverseInOrder(root->left);
    traverseInOrder(root->right);
    cout << root->key << " ";
    }
}