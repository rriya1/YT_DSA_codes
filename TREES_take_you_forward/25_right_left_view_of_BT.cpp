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

void right_view(vector<vector<int>> v, vector<int> &r)
{
    int i;
    for(auto val: v)
    {
        i=0;
        int size=val.size();
        for(auto it: val)
        {
            if(i==size-1)
                r.push_back(it);
            i++;
        }
    }
}

void left_view(vector<vector<int>> v, vector<int> &r)
{
    int i;
    for(auto val: v)
    {
        r.push_back(val[0]);
    }
}




//idk i dont find recursice intutive here, and this code has some bugs
// void left_travel(Node* node, vector<int> &lt)
// {
//     if(node==NULL)
//         return;
//     lt.push_back(node->data);
//     if(node->left!=NULL)
//         left_travel(node->left,lt);
//     else
//         left_travel(node->right,lt);
// }

// void left_view(Node* root,vector<int> &left)
// {
//     if(root==NULL)
//         return;
//     left.push_back(root->data);
//     left_travel(root->left,left);
// }


// void right_travel(Node* node, vector<int> &rt)
// {
//     if(node==NULL)
//         return;
//     rt.push_back(node->data);
//     if(node->right!=NULL)
//         right_travel(node->right,rt);
//     else
//         right_travel(node->left,rt);
// }

// void right_view(Node* root,vector<int> &right)
// {
//     if(root==NULL)
//         return;
//     right.push_back(root->data);
//     right_travel(root->right,right);
// }




int main()
{
	Node* root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
    root->left->left->left=new Node(5);
    root->left->left->right=new Node(6);
    root->right->left = new Node(7);
    /*        1
            /   \
           2     3
         /   \ /   \
        4     7
      /   \  
     5     6 */ 
  
  vector<int> rightv,leftv;
  vector<vector<int>> v;
   level_order(root,v);
  right_view(v,rightv);
  left_view(v,leftv);

  cout<<"right view: "<<endl;
  for( auto val:rightv)
    cout<<val<<" ";
  cout<<endl;
  cout<<"left view: "<<endl;
  for(auto val: leftv)
    cout<<val<<" ";
    
	return 0;
}
