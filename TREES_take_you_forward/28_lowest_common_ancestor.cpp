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

int lcanode=100;

int lca(Node* root, int target1,int target2)
{
    if(root==NULL)
        return -1;

    if(root->data==target1)
        return target1;
    if(root->data==target2)
        return target2;

    int lh=lca(root->left,target1,target2);
    int rh=lca(root->right,target1,target2);

     if(lh!=-1 && rh!=-1)
        {
            lcanode=root->data;
            return root->data;
        }

    if(lh!=-1 && lh!=target1 && lh!=target2)
        {
            lcanode=root->data;
            return lh;
        }

    if(rh!=-1 && rh!=target1 && rh!=target2)
        {
            lcanode=root->data;
            return rh;
        }
    
    

    if(lh==target1 || rh==target1)
        return target1;
    
    if(lh==target2 || rh==target2)
        return target2;

   

        return -1;
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
    
    int ans =lca(root,2,6);
    cout<<ans<<endl;
    //cout<<lcanode<<"."<<endl;
	return 0;
}
