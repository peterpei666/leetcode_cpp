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
    int numComponents(ListNode* head, vector<int>& nums)
    {
        bitset<10000> found;
        for(int i:nums)
        {
            found.set(i);
        }
        int ans=0;
        while(head)
        {
            if(found.test(head->val)&&(head->next==nullptr||found.test(head->next->val)==false))
            {
                ans++;
            }
            head=head->next;
        }
        return ans;
    }
};
