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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode dummy(0, head);
        ListNode ans = ListNode();
        ListNode* pre = &dummy;
        ListNode* cur = head;
        ListNode* temp = &ans;
        while (cur != nullptr)
        {
            if (cur->val < x)
            {
                pre->next = cur->next;
                temp->next = cur;
                temp = cur;
            }
            else
            {
                pre = cur;
            }
            cur = cur->next;
        }
        temp->next = dummy.next;
        return ans.next;
    }
};
