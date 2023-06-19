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

Node* construct_tree(map<int,int> inorder,vector<int> preorder,int insize,int presize,int instart,int prestart)
{ //inorder vector, preorder vector, inorder size, preorder size, inorder start, preorder start
    if(inorder.size()!=preorder.size())
        return NULL;
    if(instart>insize || prestart>presize)
        return NULL;
    if(inorder.size()==0 || preorder.size()==0)
        return NULL;
    Node* root=new Node(preorder[prestart]);
    int root_inorder=inorder[preorder[prestart]]; // where is root in inorder
    int ls_ele_count=root_inorder-instart;
    Node* ls=construct_tree(inorder,preorder,root_inorder,prestart+ls_ele_count,instart,prestart+1);
    Node* rs=construct_tree(inorder,preorder,insize,presize,root_inorder+1,prestart+ls_ele_count+1);
    root->left=ls;
    root->right=rs;
    return root;

}

int main()
{
    vector<int> inorder,preorder;
    int insize,presize;
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
    cout<<endl<<"preorder size: ";
    cin>>presize;
    for(int i=0;i<presize;i++)
    {
        int x;
        cin>>x;
        preorder.push_back(x);
        //presize--;
    }

    map<int,int> inorder_map;
    to_hash(inorder,inorder_map);
    Node* root = construct_tree(inorder_map,preorder,insize-1,presize-1,0,0);
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