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
    ListNode* insertionSortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = head;
        while (cur && cur->next)
        {
            if (cur->next->val >= cur->val)
            {
                cur = cur->next;
            }
            else
            {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                ListNode* pre = &dummy;
                while (pre->next->val < temp->val)
                {
                    pre = pre->next;
                }
                temp->next = pre->next;
                pre->next = temp;
            }
        }
        return dummy.next;
    }
};
