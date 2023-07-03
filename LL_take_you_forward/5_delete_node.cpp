#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x)
    {
        this->val=x;
        this->next=NULL;
    }
};
void delnode(Node* node)
{
    node->val=node->next->val;
    Node* curr=node->next;
    node->next=node->next->next;
    delete(curr);
}
int main()
{
    int n;
    cout<<"Enter number of elements in frist linked list: ";
    cin>>n;
    Node* dummy=new Node(1);
    Node* head=dummy;
    Node* temp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        Node* node=new Node(x);
        dummy->next=node;
        if(node->val==3)
            temp=node;
        dummy=dummy->next;
    }
    delnode(temp);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;

}