//not able to solve do again in some time
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

int sum=0;
int max_sum_path_help(Node* root)
{
    if(root==NULL)
        return 0;
    int lsum=max_sum_path_help(root->left);
    int rsum=max_sum_path_help(root->right);
    int s=max(lsum,rsum)+root->data;
    sum=max(sum,s);
    return s;
}

int maxx_sum_path(Node* node)
{
    int l=max_sum_path_help(root->left);
    int r=max_sum_path_help(root->right);
    
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
    
    int height = length_and_sum(root);
    cout<<height<<endl;
    cout<<sum;//this is the answer
	return 0;
}
