#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* stk = nullptr;
        ListNode* temp = slow->next;
        slow->next = nullptr;
        while (temp)
        {
            ListNode* t = temp->next;
            temp->next = stk;
            stk = temp;
            temp = t;
        }
        temp = head;
        while (stk)
        {
            ListNode* t = temp->next;
            temp->next = stk;
            stk = stk->next;
            temp->next->next = t;
            temp = t;
        }
    }
};
