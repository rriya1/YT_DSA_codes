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

bool BST_search(Node* root,int val)
{
    bool flag;
    if(root==NULL)
        return NULL;
    if(root->data==val)
        return true;
    else
    {
        if(val>root->data)
            flag=BST_search(root->right,val);
        else
            flag=BST_search(root->left,val);
    }
    return flag;
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

    bool ans=BST_search(root,1);
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
