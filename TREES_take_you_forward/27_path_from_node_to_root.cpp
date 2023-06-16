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

bool printpath(Node* node, int val, vector<int> &path)
{
    //cout<<node->data;
    if(node==NULL)
        return false;
    
    cout<<node->data<<endl;

    if(node->data==val)
        {
             path.push_back(node->data);
             return true;
        }

    path.push_back(node->data);
    int pos=path.size()-1;
   
    bool l=printpath(node->left,val,path);
    bool r=printpath(node->right,val,path);
        

    if(l==false && r==false)
        {
            //int k=i-2;
            path.erase(path.begin()+pos);
            return false;
        }

    if(l==true || r==true)
        return true;

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
    bool h=printpath(root,7,ans);
    for(auto it: ans)
        cout<<it<<" ";
	return 0;
}
