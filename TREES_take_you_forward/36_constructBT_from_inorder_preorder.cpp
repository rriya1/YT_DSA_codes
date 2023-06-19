#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};


vector<int> level_order(Node* root)
{
    vector<int> v;
    if(root==NULL)
        return v;
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
            v.push_back(temp->data);
            if(temp->left!=NULL)
                node.push(temp->left);
            if(temp->right!=NULL)
                node.push(temp->right);
        }
        //v.push_back(level);
    }
    return v;
}

void to_hash(vector<int>vec, map<int,int> &vec_map)
    {
        int i=0;
        for(auto it: vec)
        {
            vec_map[it]=i;
            i++;
        }
        return;
    }

Node* construct_tree(map<int,int> inorder,vector<int> postorder,int insize,int postend,int instart,int poststart)
{ //inorder vector, preorder vector, inorder size, preorder size, inorder start, preorder start
    if(inorder.size()!=postorder.size())
        return NULL;
    if(instart>insize || poststart<postend)
        return NULL;
    if(inorder.size()==0 || postorder.size()==0)
        return NULL;
    Node* root=new Node(postorder[poststart]);
    int root_inorder=inorder[postorder[poststart]]; // where is root in inorder
    int ls_ele_count=root_inorder-instart; //no fo elements in left subtree
    int rs_ele_count=insize-root_inorder;//no of elements in right subtree
    Node* ls=construct_tree(inorder,postorder,root_inorder-1,postend,instart,poststart-rs_ele_count-1);
    Node* rs=construct_tree(inorder,postorder,insize,poststart-rs_ele_count,root_inorder+1,poststart-1);
    root->left=ls;
    root->right=rs;
    return root;

}

int main()
{
    vector<int> inorder,postorder;
    int insize,postsize;
    cout<<"enter the inorder and preorder vectors"<<endl;
    cout<<"inorder size: ";
    cin>>insize;
    for(int i=0;i<insize;i++)
    {
        int x;
        cin>>x;
        inorder.push_back(x);
        //insize--;
    }
    cout<<endl<<"postorder size: ";
    cin>>postsize;
    for(int i=0;i<postsize;i++)
    {
        int x;
        cin>>x;
        postorder.push_back(x);
        //presize--;
    }

    map<int,int> inorder_map;
    to_hash(inorder,inorder_map);
    Node* root = construct_tree(inorder_map,postorder,insize-1,0,0,postsize-1);
    if(root==NULL)
        {
            cout<<"no tree";
            return 0;
        }
    vector<int> tree;
    tree=level_order(root);
    //cout<<tree.size();
    for(auto it: tree)
        cout<<it<<" ";
    return 0;
}