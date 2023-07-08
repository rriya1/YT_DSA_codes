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

    Node()
	{
		left = NULL;
		right = NULL;
	}
};

string serialize(Node* root)
{
    if(root==NULL)
        return "";
    string s;
    queue<Node*> node;
    node.push(root);
    Node* dummy=new Node(-1);
    while(!node.empty())
    {
        int size=node.size();
        for(int i=0;i<size;i++)
        {
            Node* temp=node.front();
            node.pop();
            if(temp->data==-1)
                {
                    s.push_back('#');
                    continue;
                }
            else{
                char ss=(temp->data+48);
                s.push_back(ss);
            }
            // if(temp->left==NULL && temp->right==NULL)
            //     continue;
            if(temp->left!=NULL)
                node.push(temp->left);
            else
                node.push(dummy);
            if(temp->right!=NULL)
                node.push(temp->right);
            else
                node.push(dummy);
            }
    }
    return s;
}

Node* deserialize(string s)
{
    if(s.size()==0)
        return NULL;
    Node* head=new Node(int(s[0])-48);
    queue<Node*> q;
    q.push(head);
    int i=0;
    while( q.empty()!=true || i!=s.size()-1)
    {
        Node* temp=q.front();
        q.pop();
        i++;
        if(s[i]!='#')
        {
            Node* left=new Node(int(s[i])-48);
            temp->left=left;
            q.push(left);
        }
        i++;
        if(s[i]!='#')
        {
            Node* right=new Node(int(s[i])-48);
            temp->right=right;
            q.push(right);
        }
    }
    return head;
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

    string ser=serialize(root);
    for(auto it:ser)
    {
        cout<<it<<" ";
    }

    Node* head=deserialize(ser);
    cout<<endl;
    string ser2=serialize(head);
    for(auto it:ser2)
    {
        cout<<it<<" ";
    }
	return 0;
}
