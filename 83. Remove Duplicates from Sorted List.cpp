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
    ListNode* deleteDuplicates(ListNode* head)
    {
        int temp=1000;
        ListNode* cur=head;
        while(cur)
        {
            if(temp!=cur->val)
            {
                temp=cur->val;
            }
            ListNode* t=cur->next;
            while(t&&t->val==temp)
            {
                t=t->next;
            }
            cur->next=t;
            cur=t;
        }
        return head;
    }
};
