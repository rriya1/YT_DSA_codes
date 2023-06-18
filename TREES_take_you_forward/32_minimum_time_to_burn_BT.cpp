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

Node*  mark_parent(Node* root,map<Node*,Node*> &m,int target)
{
    //doing one whole BFS traversal and finding out target too
    //cout<<"call to mark parent"<<endl;
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
    //cout<<"end to mark parent"<<endl;
    return targetnode;
}

int burn_time(Node* root,int start)
{
    //cout<<"call to burn"<<endl;
    if(root==NULL)
        return 0;
    int time=0;
    map<Node*,Node*> parentnode;
    Node* startnode=mark_parent(root,parentnode,start);
    cout<<startnode->data;
    queue<Node*> q;
    q.push(startnode);
    set<Node*>visited;

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(curr->left!=NULL && visited.find(curr->left)==visited.end())
                {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
            if(curr->right!=NULL && visited.find(curr->right)==visited.end())
                {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
            if(parentnode.find(curr)!=parentnode.end() && visited.find(parentnode[curr])==visited.end())
                {
                    q.push(parentnode[curr]);
                    visited.insert(parentnode[curr]);
                }
        }
        time++;
    }
    //cout<<"time: "<<time;
    //cout<<endl<<"end to burn parent"<<endl;
    return time-1;
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

    int time=burn_time(root,3);
    //cout<<"we get here";
    cout<<time;
	return 0;
}
