  #include<bits/stdc++.h>
using namespace std;

//structure of the node in LL
struct ListNode
{
    int val;
    ListNode* next;
};

  ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL) 
        {
        return NULL;
        }
        ListNode* n=head->next;
        ListNode* temp=NULL;
        while(n!=NULL)
        {
            head->next=temp;
            temp=head;
            head=n;
            n=n->next;
        }  
        head->next=temp;
        return head; 
    }