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

int depth=0;

int max_depth(Node* root)
{
    if(root==NULL)
        return 0;
    int lh=max_depth(root->left);
    int rh=max_depth(root->right);
    depth=1+max(lh,rh);
    return depth;
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
    int d=max_depth(root);
    cout<<d;
	return 0;
}
