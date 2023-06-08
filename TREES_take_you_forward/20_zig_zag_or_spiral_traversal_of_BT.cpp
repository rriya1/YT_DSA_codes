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

int flag=0;

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
   
}

//through iteration
vector<vector<int>> zigzag_spiral(Node* root)
{
    queue <Node*> q;
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    q.push(root);
    while(!q.empty())
    {
        vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* node=q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        //cout<<flag;
        if(flag%2!=0)
            reverse(level);
        flag++;
        ans.push_back(level);
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
    /*       1
            /  \
            2   3
           / \  / \
          4     7
         / \  
         5  6 */ 
    vector<vector<int>> zig=zigzag_spiral(root);
    for(auto level: zig)
    {
        for(auto value: level)
        {
            cout<<value<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}
