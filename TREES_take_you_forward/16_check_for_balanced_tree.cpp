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

int flag=1;
// can also use flag and can also use return -1, use any method out of the 2, will give the correct answer.

int balanced(Node* root)
{
    if(flag==0)
        return 0; //no need for futher calculation when even one node is unbalanced
    if(root==NULL)
        return 0;
    int lh=balanced(root->left);
    int rh=balanced(root->right);
    //if(lh==-1 && rh==-1) 
        //return -1; //only when we are using return -1 method, no need to use this condition in flag method.
    if(abs(lh-rh)>1)
    {
        flag=0; 
        //return -1;
    }
       
    return max(lh,rh)+1;
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
    int d=balanced(root);
    //cout<<d<<endl;
    cout<<flag;
	return 0;
}
