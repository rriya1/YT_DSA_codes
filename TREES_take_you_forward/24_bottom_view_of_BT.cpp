
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


/*   GFG solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) 
       {
                        vector<int>top;
        map<int,map<int,vector<int>>> m; // x value int, y value int, vector for values.
        queue<pair<Node*,pair<int,int>>> q;
        vector<vector<int>> ans;
        if(root==NULL)
            return top;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto curr=q.front();
                q.pop();
                Node* node=curr.first;
                int x=curr.second.first;
                int y=curr.second.second;
                if(node->left!=NULL)
                    q.push({node->left,{x-1,y+1}});
                if(node->right!=NULL)
                    q.push({node->right,{x+1,y+1}});
                int data=node->data;
                m[x][y].push_back(data); //very important
                }

            }


            for(auto a:m) 
                  {
                    vector<int>v;
                    //cout<<a.first<<"x: ";
                    for(auto b:a.second) 
                    {
                        //cout<<b.first<<"y: ";
                        vector<int> m = b.second; 
                        for(auto it : m) 
                        {   //cout<<it<<" ";
                            v.push_back(it);
                        }
                        //cout<<"..";

                        // multiset<int> mm = b.second; 
                        // auto it=mm.begin();
                        // int dat=*it;
                        // v.push_back(dat);
                    }
                    //cout<<endl;
                    ans.push_back(v);
                }
        for(auto it: ans)
        {
            auto end=it.end();
            end--;
            int dat=*end;
            top.push_back(dat);
        }
                        
        return top;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends
*/
