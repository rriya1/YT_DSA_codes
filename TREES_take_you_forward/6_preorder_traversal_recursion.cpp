#include <bits/stdc++.h>
using namespace std;

class Node 
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

vector<int> pre_r(Node* root, vector<int>&v)
{
    if(root==NULL)
        return v;
    v.push_back(root->data);
    pre_r(root->left,v);
    pre_r(root->right,v);
    return v;
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->right=new Node(6);
    root->right->left = new Node(7);
    /*       1
            /  \
            2   3
           / \  / \
          4     7
         / \  
         5  6 */ 
    vector<int> preorder;
    pre_r(root,preorder);
    for(auto it: preorder)
    {
        cout<<it<<" ";
    }
	return 0;
}
