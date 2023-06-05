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

vector<int> postorder_2stack(Node* root)
{
	stack<Node*> s1;
	stack<int> s2;
	vector<int> v;

	if(root==NULL)
		return v;
	
	s1.push(root);
	while(!s1.empty())
	{
		Node* temp=s1.top();
		s1.pop();
		s2.push(temp->data);
		if(temp->left!=NULL)
			s1.push(temp->left);
		if(temp->right!=NULL)
			s1.push(temp->right);
	}
	while(!s2.empty())
	{
		int value = s2.top();
		s2.pop();
		v.push_back(value);
	}
	return v;
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
	vector<int> ans= postorder_2stack(root);
	for(auto it: ans)
		cout<<it<<" ";
	return 0;
}
