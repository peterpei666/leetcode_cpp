#include <iostream>
#include <algorithm>
#include <deque>
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
    ListNode* mergeSort(ListNode* head, int sz)
    {
        if (sz == 1)
        {
            return head;
        }
        int mid = sz / 2;
        ListNode* t = head;
        for (int i = 0; i < mid - 1; i++)
        {
            t = t->next;
        }
        ListNode* t2 = mergeSort(t->next, sz - mid);
        t->next = nullptr;
        ListNode* t1 = mergeSort(head, mid);
        ListNode dummy;
        ListNode* temp = &dummy;
        while (t1 && t2)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        temp->next = t1 ? t1 : t2;
        return dummy.next;
    }
    
public:
    ListNode* sortList(ListNode* head)
    {
        int sz = 0;
        ListNode* temp = head;
        while (temp)
        {
            sz++;
            temp = temp->next;
        }
        if (sz == 0)
        {
            return nullptr;
        }
        return mergeSort(head, sz);
    }
};
