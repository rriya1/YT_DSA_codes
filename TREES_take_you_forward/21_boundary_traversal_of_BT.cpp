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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
    vector<int> ans;
    if(root==NULL)
        return ans;

    vector<int> left;
    if(root->left!=NULL)
        left_nodes(root->left,left);

    vector<int> right;
    if(root->right!=NULL)
    {
        right_nodes(root->right,right);
        reverse(right.begin(),right.end());
    }
        

    vector<int> leaf;
    leaf_nodes(root,leaf);
    
    
    ans.push_back(root->data);
    for(auto it: left)
        ans.push_back(it);
    if(!(root->left==NULL && root->right==NULL))
        {
            for(auto it: leaf)
            ans.push_back(it);
        }
    for(auto it: right)
        ans.push_back(it);
    return ans;
    }
    
    void leaf_nodes(Node* node,vector<int> &v)
{
    if(leafnode(node))
    {
        v.push_back(node->data);
        return;
    }

    if(node->left)
        leaf_nodes(node->left,v);
    if(node->right)
        leaf_nodes(node->right,v);
    return;
}

void right_nodes(Node* node, vector<int> &v)
{
    Node* curr=node;
    while(curr)
    {
        if(!leafnode(curr))
            v.push_back(curr->data);
        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
    return;
}

void left_nodes(Node* node, vector<int> &v)
{
    Node* curr=node;
    while(curr)
    {
        if(!leafnode(curr))
            v.push_back(curr->data);
        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
    return;
}

bool leafnode(Node* node)
{
    if(node->left==NULL && node->right==NULL)
        return true;
    //cout<<"1";
    return false;
}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

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
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends