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

int BST_floor(Node* root, int val)
{
   if(root==NULL)
    return -1;
   Node* curr=root;
   int f=INT_MIN;
   while(curr!=NULL)
   {
    if(curr->data>=val)
        curr=curr->left;
    else{
        f=max(f,curr->data);
        curr=curr->right;
    }
   }
   if(f==INT_MAX)
    return -1;
   return f;
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

    int ans=BST_floor(root,10);
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