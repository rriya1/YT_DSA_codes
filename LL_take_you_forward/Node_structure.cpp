#include<bits/stdc++.h>
using namespace std;

//structure of the node in LL
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

//a linked list
int main()
{
    Node* head=new Node(0);
    Node* first=new Node(1);
    //head->val=0;
    head->next=first;
    //first->val=1;
    first->next=NULL;
    //0->1->NULL
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
    }
    return 0;
}