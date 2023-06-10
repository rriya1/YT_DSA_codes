
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


vector<int> bottom_view(Node* root)
{
    vector<int>v;
    //vector<vector<int>> ans;
    if(root==NULL)
        return v;
    queue<pair<Node*,int>> q; //node and x axis
    q.push({root,0});
    map<int,int> level; // x corrdinate and value

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto curr= q.front();
            q.pop();
            Node* node=curr.first;
            int x=curr.second;
            level[x]=node->data;
            if(node->left!=NULL)
                q.push({node->left,x-1});
            if(node->right!=NULL)
                q.push({node->right,x+1});
        }

    }
   
   for(auto it: level)
   {
        int val=it.second;
        v.push_back(val);
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
    /*        1
            /   \
           2     3
         /   \ /   \
        4     7
      /   \  
     5     6 */ 
  
  vector<int> b=bottom_view(root);
  for(auto row: b)
    cout<<row<<" ";
    
	return 0;
}
