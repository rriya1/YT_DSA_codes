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

int height(Node* root)
{
    //cout<<"start of height";
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}

int count_nodes(Node* root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    cout<<"lh :"<<lh<<" rh: "<<rh<<endl;
    if(lh==rh)
    {
        return pow(2,lh+1)-1;
    }
    int nodes;
    if(lh!=rh)
    {
        int lt=count_nodes(root->left);
        int rt=count_nodes(root->right);
        nodes=lt+rt;
    }
    return nodes+1;
}
int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
    //root->left->left->left=new Node(5);
    //root->left->left->right=new Node(6);
    //root->right->left = new Node(7);
    /*       1
            /  \
            2   3
           / \  / \
          4     */ 
    int nodenum=count_nodes(root);
    cout<<nodenum;
	return 0;
}
