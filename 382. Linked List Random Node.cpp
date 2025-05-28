#include <iostream>
#include <algorithm>
#include <random>
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
private:
    int randomInt(int l,int r)
    {
        static mt19937 gen(random_device{}());
        uniform_int_distribution<> dist(l,r);
        return dist(gen);
    }
    
public:
    vector<int> list;
    int n;
    
    Solution(ListNode* head)
    {
        while(head)
        {
            list.push_back(head->val);
            head=head->next;
        }
        n=(int)list.size();
    }
    
    
    int getRandom()
    {
        return list[randomInt(0,n-1)];
    }
};
