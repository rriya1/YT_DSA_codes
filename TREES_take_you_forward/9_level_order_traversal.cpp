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

vector<vector<int>> level_order(Node* root, vector<vector<int>>&v)
{
    //vector<int> level;
    if(root==NULL)
        return v;
    queue<Node*> node;
    node.push(root);
    while(!node.empty())
    {
        int size=node.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node* temp=node.front();
            node.pop();
            level.push_back(temp->data);
            if(temp->left!=NULL)
                node.push(temp->left);
            if(temp->right!=NULL)
                node.push(temp->right);
        }
        v.push_back(level);
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
    vector<vector<int>> level;
    level_order(root,level);
    for(auto it: level)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
	return 0;
}
