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

//int ans;

int max_width(Node* root)
{
    int ans=0;
    if(root==NULL)
        return ans;
    queue<Node*> q;
    //ans=1;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        int min=q.front()->data;
        int lastnode=0;
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            curr->data=(curr->data)-min;
            if(curr->left!=NULL)
                {
                    q.push(curr->left);
                    curr->left->data=(curr->data*2);
                }
            if(curr->right!=NULL)
                {
                    q.push(curr->right);
                    curr->right->data=(curr->data*2)+1;
                }
            if(i==size-1)
                lastnode=curr->data;
        }
        //cout<<lastnode<<endl;
        ans=max(lastnode-min+1,ans);
        //ans=ans-min+1;
    }
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
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    int width=max_width(root);
    cout<<width;
    /*       1
            /  \
            2   3
           / \  / \
          4     7  8
         / \        \
         5  6         9*/ 
	return 0;
}
