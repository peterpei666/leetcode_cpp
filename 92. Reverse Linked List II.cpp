#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* stack=NULL;
    
    inline void push(ListNode* temp)
    {
        temp->next=stack;
        stack=temp;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left==right)
        {
            return head;
        }
        ListNode start;
        start.next=head;
        ListNode* prev=&start;
        for(int i=1;i<left;i++)
        {
            prev=prev->next;
        }
        ListNode* temp=prev->next;
        ListNode* next=nullptr;
        for(int i=left;i<=right;i++)
        {
            next=temp->next;
            push(temp);
            temp=next;
        }
        prev->next=stack;
        temp=stack;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=next;
        return start.next;
    }
};
