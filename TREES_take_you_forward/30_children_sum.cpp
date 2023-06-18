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

void children_sum(Node* root)
{
    //cout<<"call"<<endl;
    if(root==NULL)
        return;
    int childsum=0;
    if(root->left!=NULL)
        childsum+=root->left->data;
    if(root->right!=NULL)
        childsum+=root->right->data;
    if(childsum<root->data && root->left!=NULL)
        root->left->data=root->data;
    else if(childsum<root->data && root->right!=NULL)
        root->right->data=root->data;
    children_sum(root->left);
    children_sum(root->right);
    int newchildsum=0;
    if(root->left!=NULL)
        newchildsum+=root->left->data;
    if(root->right!=NULL)
        newchildsum+=root->right->data;
    if(root->left!=NULL || root->right!=NULL)
        root->data=newchildsum;
    return;
    
}

int main()
{
	Node* root = new Node(100);

	root->left = new Node(2);
	root->right = new Node(30);
	root->left->left = new Node(45);
    root->left->left->left=new Node(55);
    root->left->left->right=new Node(6);
    root->right->left = new Node(7);
    /*       100
            /  \
            2   30
           / \  / \
          45    7
         / \  
         55  6 */ 
    children_sum(root);
    
    //level order traversal
    queue<Node*> node;
    node.push(root);
    while(!node.empty())
    {
        int size=node.size();
        //vector<int> level;
        for(int i=0;i<size;i++)
        {
            Node* temp=node.front();
            node.pop();
            cout<<temp->data<<" ";
            //level.push_back(temp->data);
            if(temp->left!=NULL)
                node.push(temp->left);
            if(temp->right!=NULL)
                node.push(temp->right);
        }
        //v.push_back(level);
        cout<<endl;
    }
	return 0;
}
