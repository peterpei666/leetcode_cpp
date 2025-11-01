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
        ListNode dummy = ListNode();
        ListNode* tail = &dummy;
        ListNode* t = head;
        while (t != nullptr)
        {
            int val = t->val;
            ListNode* node = t->next;
            int cnt = 1;
            while (node != nullptr && node->val == val)
            {
                cnt++;
                node = node->next;
            }
            if (cnt == 1)
            {
                t->next = nullptr;
                tail->next = t;
                tail = t;
            }
            t = node;
        }
        return dummy.next;
    }
};
