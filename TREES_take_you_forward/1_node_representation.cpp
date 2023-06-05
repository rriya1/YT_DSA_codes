#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

int main()
{
    struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    cout<<root->data<<endl<<root->left->data<<" "<<root->right->data;
    return 0;
    
}