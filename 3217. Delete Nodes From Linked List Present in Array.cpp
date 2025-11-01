#include <iostream>
#include <algorithm>
#include <unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> mp(nums.begin(), nums.end());
        ListNode ans = ListNode();
        ListNode* t = &ans;
        while (head != nullptr)
        {
            if (!mp.count(head->val))
            {
                t->next = head;
                t = t->next;
            }
            head = head->next;
        }
        t->next = nullptr;
        return ans.next;
    }
};
