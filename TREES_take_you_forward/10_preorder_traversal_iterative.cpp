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

vector<int> preorder_it(Node* root)
{
    vector<int> v;
    if(root==NULL)
        return v;
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* node;
        node=s.top();
        s.pop();
        v.push_back(node->data);
        if(node->right!=NULL)
            s.push(node->right);
        if(node->left!=NULL)
            s.push(node->left);
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

    vector<int> ans=preorder_it(root);
    for(auto it: ans)
        cout<<it<<" ";
	return 0;
}
