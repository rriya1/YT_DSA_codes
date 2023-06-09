#include<bits/stdc++.h>
using namespace std;

//structure of the node in LL
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        this->val=x;
        this->next=NULL;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* fast=dummy;
        ListNode* slow=dummy;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }