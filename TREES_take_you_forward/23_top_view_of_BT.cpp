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


vector<int> top_view(Node* root)
{
    vector<int>v;
    //vector<vector<int>> ans;
    if(root==NULL)
        return v;
    queue<pair<Node*,pair<int,int>>> q; //stores node then its x and y coordinates
    q.push({root,{0,0}});
    map<int,map<int,multiset<int>>> level;
     //store map< xcoordinate, map< ycoordinate, if multiple values at y coordinate, multiset to store them>>>

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            pair<Node*,pair<int,int>> curr= q.front();
            q.pop();
            Node* node=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            //saw how to do this insertaion from the internet, normal 2D array [][] insertion can be donr like this only
            level[x][y].insert(node->data);
            if(node->left!=NULL)
                q.push({node->left,{x-1,y+1}});
            if(node->right!=NULL)
                q.push({node->right,{x+1,y+1}});
        }
    }
   
   for(auto a:level) //refers to one pair of the map ie {xcorr,{ycorr,vector}}
   {
    
    //cout<<a.first<<"x: "; // x coordinates
    for(auto b:a.second) //refers to y value and the vectors at that y
    {
        //cout<<"B start";
        multiset<int> m = b.second;
        auto it = m.begin();
        int val=*it;
        v.push_back(val);
        break;

    }
    //cout<<endl;
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
  
  vector<int> b=top_view(root);
  for(auto row: b)
    cout<<row<<" ";
    
	return 0;
}
