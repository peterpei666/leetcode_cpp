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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* stk = nullptr;
        while (head)
        {
            ListNode* temp = head->next;
            head->next = stk;
            stk = head;
            head = temp;
        }
        return stk;
    }
};
