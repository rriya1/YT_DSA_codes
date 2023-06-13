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

int sum=INT_MIN;

int maxpathsum(Node* root)
{
	if(root==NULL)
		return 0;
	maxpath(root,sum);
	return sum;
}

int maxpath(Node* root, int &sum)
{
	if(root==NULL)
		return 0;
	int left=max(0,maxpath(node->left,sum));
	int right=max(0,maxpath(node->right,sum));
	sum=max(sum,right+left+root->val);
	return max(left,right)+root->val;
}

/*
my code--------------->>>>>>>>>>>>>>>>>>>>mycode--------------------->>>>>>>>>>>>>my code
int sum=INT_MIN;
    int maxPathSum(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int h=height(root);
        return sum;
    }

    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        //if(!((lh>1 && rh==0) || (rh>1 && lh==0)))
        int sum1=lh+rh+root->val;
        sum=max(sum,sum1);
        if(root->val<0)
            return max(0,max(root->val+lh,rh+root->val));
        //int sum1=lh+rh+root->val;
        return max(root->val+lh,rh+root->val);
    }*/


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
    
    int sum = maxpathsum(root);
    //cout<<height<<endl;
    cout<<sum;//this is the answer
	return 0;
}
