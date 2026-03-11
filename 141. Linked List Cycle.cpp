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
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (1)
        {
            if (fast->next == nullptr || fast->next->next == nullptr)
            {
                break;
            }
            fast = fast->next->next;
            if (fast == slow)
            {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
