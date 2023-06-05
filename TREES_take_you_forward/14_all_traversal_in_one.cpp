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

vector<vector<int>> traversal_in_one(Node* root)
{
    vector<vector<int>> v;
    vector<int> pre;
    vector<int>in;
    vector<int> post;
    if(root==NULL)
        return v;
    stack<pair<Node*,int>>  s;
    s.push({root,1});
    while(!s.empty())
    {
        pair<Node*,int> curr=s.top();
        s.pop();
        //cout<<curr.first->data;
        if(curr.second==1)
        {
            pre.push_back(curr.first->data);
            curr.second++;
            //cout<<curr.second;
            s.push({curr.first,curr.second});
            if(curr.first->left!=NULL)
                s.push({curr.first->left,1});
        }
        else if(curr.second==2)
        {
            in.push_back(curr.first->data);
            curr.second++;
            s.push({curr.first,curr.second});
            if(curr.first->right!=NULL)
                s.push({curr.first->right,1});
        }
        else if(curr.second==3)
        {
            post.push_back(curr.first->data);
            //s.pop();
        }
    }

    v.push_back(pre);
    v.push_back(in);
    v.push_back(post);
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
    vector<vector<int>> ans=traversal_in_one(root);
    for(auto it: ans)
    {
        for(auto value : it)
            {cout<<value<<" ";}
        cout<<endl;
    }
	return 0;
}
