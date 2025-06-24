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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* ret=list1;
        for(int i=1;i<a;i++)
        {
            list1=list1->next;
        }
        ListNode* temp=list1->next;
        ListNode* prev;
        for(int i=a;i<=b;i++)
        {
            prev=temp;
            temp=temp->next;
            delete prev;
        }
        list1->next=list2;
        while(list2->next)
        {
            list2=list2->next;
        }
        list2->next=temp;
        return ret;
    }
};
