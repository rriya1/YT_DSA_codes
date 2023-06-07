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

int dia =0;


// int length(Node* root)
// {
//     if(root==NULL)
//         return 0;
//     int lh=length(root->left);
//     int rh=length(root->right);
//     return max(lh,rh)+1;
// }

// void diameter(Node* root)
// {
//     if(root==NULL)
//         return ;
//     int lh=length(root->left);
//     int rh=length(root->right);
//     dia=max(dia,lh+rh);
//     diameter(root->left);
//     diameter(root->right);
// }

//combining the working of the above 2 function into only 1 function
int diameter(Node* root)
{
    if(root==NULL)
        return 0  ;
    int lh=diameter(root->left);
    int rh=diameter(root->right);
    dia=max(dia,lh+rh); //this time the diameter consists of the number of paths, if diameter is number of nodes then justdo lh+rh+1;
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
    
    int height = diameter(root);
    cout<<height<<endl;
    cout<<dia;//this is the answer
	return 0;
}
