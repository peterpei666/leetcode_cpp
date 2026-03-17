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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode dummy;
        ListNode* temp = &dummy;
        while (head)
        {
            if (head->val != val)
            {
                temp->next = head;
                temp= head;
            }
            head = head->next;
        }
        temp->next = nullptr;
        return dummy.next;
    }
};
