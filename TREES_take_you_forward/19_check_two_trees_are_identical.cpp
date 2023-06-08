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

bool help(Node* tree1, Node* tree2)
{
    if(tree1==NULL && tree2==NULL)
        return 1;
    if((tree1==NULL && tree2!=NULL) || (tree1!=NULL && tree2==NULL) )
        return 0;
    bool l = help(tree1->left,tree2->left);
    bool r = help(tree1->right,tree2->right);
    if(tree1->data==tree2->data && l && r)
        return 1;
    return 0;
}

bool identical(Node* tree1, Node* tree2)
{
    if(tree1==NULL && tree2==NULL)
        return 1;
    if((tree1==NULL && tree2!=NULL) || (tree1!=NULL && tree2==NULL) )
        return 0;
    bool check = help(tree1,tree2);
    return check;
}

int main()
{
    //tree 1
	Node* root1 = new Node(1);

	root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->left = new Node(4);
    root1->left->left->left=new Node(5);
    root1->left->left->right=new Node(6);
    root1->right->left = new Node(7);

    //tree 2
    Node* root2 = new Node(1);

	root2->left = new Node(2);
	root2->right = new Node(3);
	root2->left->left = new Node(4);
    root2->left->left->left=new Node(5);
    root2->left->left->right=new Node(6);
    //root2->right->left = new Node(7);
    /*       1
            /  \
            2   3
           / \  / \
          4     7
         / \  
         5  6 */ 
    
    bool val= identical(root1,root2);
    cout<<val;
	return 0;
}
