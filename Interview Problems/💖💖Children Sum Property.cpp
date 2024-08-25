#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int helper(BinaryTreeNode < int >* &root){
    if(root == NULL){
        return 0; 
    }  
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int x = (root->left != NULL) ? root->left->data : 0;
    int y = (root->right != NULL) ? root->right->data : 0;

    if(root->data > (x+y)){
      if(root->left != NULL){
        root->left->data = root->data;
      }
      if(root->right != NULL){
        root->right->data = root->data;
      }
    }

    int l = helper(root->left);
    int r = helper(root->right);

    int a = (root->left != NULL) ? root->left->data : 0;
    int b = (root->right != NULL) ? root->right->data : 0;    

    root->data = (a+b);

    return root->data;
}


void changeTree(BinaryTreeNode < int >* root) {
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    helper(root);

    return;
}  