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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        int cnt=1;
        ListNode* temp=head;
        while(temp->next)
        {
            cnt++;
            temp=temp->next;
        }
        k%=cnt;
        if(k==0)
        {
            return head;
        }
        temp->next=head;
        k=cnt-k-1;
        temp=head;
        while(k)
        {
            temp=temp->next;
            k--;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};
