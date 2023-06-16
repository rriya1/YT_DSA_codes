#include<bits/stdc++.h>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return false;
        else
         return mirror(root->left,root->right);   
    }

    bool mirror(TreeNode* left,TreeNode* right)
    {
        bool ans;
        if(right==NULL && left==NULL)
            return true;
        if((right==NULL && left!=NULL) || (left==NULL && right!=NULL))
            return false;
        else
            return (mirror(left->left,right->right) && mirror(left->right,right->left) &&(right->val==left->val) );
    }
};