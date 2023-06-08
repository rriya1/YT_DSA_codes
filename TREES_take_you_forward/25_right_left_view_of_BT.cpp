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



void left_travel(Node* node, vector<int> &lt)
{
    if(node==NULL)
        return;
    lt.push_back(node->data);
    if(node->left!=NULL)
        left_travel(node->left,lt);
    else
        left_travel(node->right,lt);
}

void left_view(Node* root,vector<int> &left)
{
    if(root==NULL)
        return;
    left.push_back(root->data);
    left_travel(root->left,left);
}


void right_travel(Node* node, vector<int> &rt)
{
    if(node==NULL)
        return;
    rt.push_back(node->data);
    if(node->right!=NULL)
        right_travel(node->right,rt);
    else
        right_travel(node->left,rt);
}

void right_view(Node* root,vector<int> &right)
{
    if(root==NULL)
        return;
    right.push_back(root->data);
    right_travel(root->right,right);
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
    /*        1
            /   \
           2     3
         /   \ /   \
        4     7
      /   \  
     5     6 */ 
  
  vector<int> rightv,leftv;
  right_view(root,rightv);
  left_view(root,leftv);

  cout<<"right view: "<<endl;
  for( auto val:rightv)
    cout<<val<<" ";
  cout<<endl;
  cout<<"left view: "<<endl;
  for(auto val: leftv)
    cout<<val<<" ";
    
	return 0;
}
