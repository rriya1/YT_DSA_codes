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

int BST_ceil(Node* root, int val)
{
    if(root==NULL)
        return -1;
    Node* curr=root;
    int c=INT_MAX;
    while(curr!=NULL)
    {
        if(curr->data<=val)
        {
            curr=curr->right;
        }
        else{
            c=min(curr->data,c);
            curr=curr->left;
        }
    }
    if(c==INT_MAX)
        return -1;    
    return c;
}

int main()
{
	Node* root = new Node(8);

	root->left = new Node(5);
	root->right = new Node(12);
	root->left->left = new Node(4);
    root->left->right=new Node(7);
    root->left->right->left=new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    int ans=BST_ceil(root,14);
    cout<<ans;
    /*       8
            /  \
            5   12
           / \  /  \
          4  7  10  14
            /       /
           6       13   */ 
	return 0;
}
