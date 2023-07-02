#include<bits/stdc++.h>
using namespace std;

//structure of the node in LL
struct Node
{
    int val;
    Node* next;
};

//a linked list
int main()
{
    Node* head=new Node();
    Node* first=new Node();
    head->val=0;
    head->next=first;
    first->val=1;
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