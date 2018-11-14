#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;


struct Node {
        int data;
        struct Node *left, *right;
};

void buildTree(Node* node, vector<vector<int> > & result, int level) {
        if (node == NULL)
           return;
        if (level == result.size()) {
           result.push_back(vector<int>());
        }
        result[level].push_back(node->data);
        buildTree(node->left, result, level + 1);
        buildTree(node->right, result, level + 1);
    }

vector<vector<int> > zigzagLevelOrder(Node* root) {
        vector<vector<int> > result;
        buildTree(root, result, 0);
        for (int i = 1; i < result.size(); i += 2) reverse(result[i].begin(), result[i].end());
        return result;
    }


// A utility function to create a new node
struct Node* newNode(int data)
{
        struct Node* node = new struct Node;
        node->data = data;
        node->left = node->right = NULL;
        return (node);
}


int main()
{
        // create tree
        struct Node* root = newNode(13);
        root->left = newNode(9);
        root->right = newNode(15);
        root->left->left = newNode(7);
        root->left->left->left = newNode(4);
        root->left->right = newNode(10);
        root->left->right->right = newNode(11);
        root->right->left = newNode(14);
        root->right->right = newNode(16);
        cout << "ZigZag Order traversal of binary tree is \n";

        vector<vector<int> > result = zigzagLevelOrder(root);
       for (int i = 0; i < result.size(); i++)
          for (std::vector<int>::const_iterator iter = result[i].begin(); iter != result[i].end(); ++iter) {
             cout << *iter << " ";
         }

        return 0;
}
