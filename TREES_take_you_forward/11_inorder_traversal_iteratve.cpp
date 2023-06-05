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

vector<int> inorder_it(Node* root)
{
    stack<Node*> s;
    vector<int> v;
    if(root==NULL)
        return v;
    Node* node=root;
    //v.push_back(0);
    int flag=1;
    while(flag)
    {
        //cout<<node->data;
        if(node!=NULL)
        {
            s.push(node);
            node=node->left;
        }
        else 
        {
            if(s.empty())
            {
                flag=0;
                break;
            }
            node=s.top();
            s.pop();
            v.push_back(node->data);
            node=node->right;
        }
        //cout<<node->data<<endl;
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
    vector<int> ans;
    ans = inorder_it(root);
    for(auto it: ans)
        cout<<it<<" ";
	return 0;
}
