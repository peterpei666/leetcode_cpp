#include <iostream>
#include <algorithm>
#include <bitset>
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
    ListNode* detectCycle(ListNode *head)
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                ListNode* p1=head;
                ListNode* p2=slow;
                while(p1!=p2)
                {
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};
