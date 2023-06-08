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

//same as striver
bool leafnode(Node* node)
{
    if(node->left==NULL && node->right==NULL)
        return true;
    //cout<<"1";
    return false;
}


void reverse(vector<int> &v)
{
    int size=v.size();
    //cout<<size<<endl;
    for(int i=0;i<size/2;i++)
    {
        int temp=v[i];
        v[i]=v[size-i-1];
        v[size-i-1]=temp;
    }
   return;
}

//to get left nodes, the one written by me..idk why its not working
// void left_nodes(Node* node,vector<int> &v)
// {
//     if(leafnode(node))
//         return;
//     v.push_back(node->data);
//     if(node->left==NULL)
//         left_nodes(node->right,v);
//     else
//         left_nodes(node->left,v);
//     return;
// }

//code by striver
void left_nodes(Node* node, vector<int> &v)
{
    Node* curr=node;
    while(curr)
    {
        if(!leafnode(curr))
            v.push_back(curr->data);
        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}


//to get  right nodes, the one written by me...idk why its not working
// void right_nodes(Node* node,vector<int> &v)
// {
//     if(leafnode(node) || node==NULL)
//         return ;
//     v.push_back(node->data);
//     if(node->right==NULL)
//         right_nodes(node->left,v);
//     else
//         right_nodes(node->right,v);
//     return;
// }

//the one by striver
void right_nodes(Node* node, vector<int> &v)
{
    Node* curr=node;
    while(curr)
    {
        if(!leafnode(curr))
            v.push_back(curr->data);
        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
}

//to get leaf nodes
void leaf_nodes(Node* node,vector<int> &v)
{
    if(leafnode(node))
    {
        v.push_back(node->data);
        return;
    }

    if(node->left)
        leaf_nodes(node->left,v);
    if(node->right)
        leaf_nodes(node->right,v);
    return;
}




//same as striver
vector<vector<int>> boundary(Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;

    vector<int> left;
    left_nodes(root->left,left);

    vector<int> right;
    right_nodes(root->right,right);

    vector<int> leaf;
    leaf_nodes(root,leaf);
    
    reverse(right); //because right nodes go from bottom to top
    // for(auto value: left)
    //     cout<<value<<" ";
    //     for(auto value: leaf)
    //     cout<<value<<" ";
    //     for(auto value: right)
    //     cout<<value<<" ";
    ans.push_back({root->data});
    ans.push_back(left);
    ans.push_back(leaf);
    ans.push_back(right);
    return ans;
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
  
  vector<vector<int>> b=boundary(root);
  for(auto row: b)
  {
    for(auto value: row)
        cout<<value<<" ";
  }
    
	return 0;
}
