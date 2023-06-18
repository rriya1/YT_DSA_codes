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

Node*  mark_parent(Node* root,int target,map<Node*,Node*> &m)
{
    //doing one whole BFS traversal and finding out target too
    queue<Node*> q;
    q.push(root);
    Node* targetnode;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(curr->data==target)
                targetnode=curr;
            if(curr->left!=NULL)
            {
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    return targetnode;
}

void k_distance(Node* root,int target, int k,vector<int>&ans)
{
    if(root==NULL)
        return;
    if(k==0)
        return;
    map<Node*,Node*> parent;
    set<int>visited;
    Node* targetnode=mark_parent(root,target,parent);
    //converted the tree into graph like structure after marking parent pointers;
    visited.insert(targetnode->data);
    queue<Node*> q;
    q.push(targetnode);
    while(!q.empty() && k!=0)
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(curr->left!=NULL && visited.find(curr->left->data)==visited.end())
            {
                q.push(curr->left);
                visited.insert(curr->left->data);
            }
            if(curr->right!=NULL && visited.find(curr->right->data)==visited.end())
            {
                q.push(curr->right);
                visited.insert(curr->right->data);
            }
            if(parent.find(curr)!=parent.end() && visited.find(parent[curr]->data)==visited.end())//no visited and parent present
            {
                q.push(parent[curr]);
                visited.insert(parent[curr]->data);
            }
        }
        k--;
    }

    while(!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
   return; 
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

    vector<int> kdistance;
    k_distance(root,3,3,kdistance);
    for(auto it:kdistance)
        cout<<it<<endl;
	return 0;
}
