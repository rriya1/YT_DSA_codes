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

Node* mergelists(Node* head1,Node* head2)
{
    //cout<<"in function"<<endl;
    Node* l1;
    Node* l2;
    Node* merhead;
    if(head1->val<=head2->val)
        {
            //cout<<"if"<<endl;
            l1=head1;
            l2=head2;
        }
    else    
        {
            cout<<"else"<<endl;;
            l1=head2;
            l2=head1;
        }
    merhead=l1;
    Node* prev;//=new Node(-1);
    while(l1!=NULL && l2!=NULL)
    {
        //cout<<"loop"<<endl;
        // if(l2==NULL)
        //     break;
        // if(l1==NULL)
        //     {
        //         cout<<"l1 NULL"<<endl;
        //         prev->next=l2;
        //     }
        
        if(l1->val<=l2->val || l2==NULL)
        {
            //cout<<"l1<l2"<<" "<<l1->val<<endl;
            //cout<<l1->next->val<<endl;
            prev=l1;
            l1=l1->next;
            if(l1==NULL)
                prev->next=l2;
            //cout<<l1->val<<endl;
        }
        else
        {
            //cout<<"exchange"<<endl;
            Node* temp;
            temp=l1;
            l1=l2;
            l2=temp;
            prev->next=l1;
        }
       
    }
    //cout<<"end";
    return merhead;
}

int main()
{
    int n;
    cout<<"Enter number of elements in frist linked list: ";
    cin>>n;
    Node* dummy=new Node(-1);
    Node* head1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        Node* node=new Node(x);
        dummy->next=node;
        if(i==0)
            head1=dummy->next;
        dummy=dummy->next;
    }


    cout<<"Enter the number of elements in second linked list: ";
    cin>>n;
    Node* head2;
    Node* dumm=new Node(-1);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        Node* node=new Node(x);
        dumm->next=node;
        if(i==0)
            head2=dumm->next;
        dumm=dumm->next;
    }
    Node* head=mergelists(head1,head2);
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}