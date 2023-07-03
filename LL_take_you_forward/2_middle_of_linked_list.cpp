#include<bits/stdc++.h>
using namespace std;

//structure of the node in LL
struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* middleNode(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* slowptr=head;
        ListNode* fastptr=head->next;
        while(fastptr!=NULL)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next;
            if(fastptr==NULL)
                break;
            fastptr=fastptr->next;
        }
        return slowptr;
    }