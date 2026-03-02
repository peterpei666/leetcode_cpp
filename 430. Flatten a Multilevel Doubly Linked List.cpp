#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution
{
public:
    Node* flatten(Node* head)
    {
        if (!head)
        {
            return head;
        }
        stack<Node*> stk;
        Node dummy;
        Node* tail = &dummy;
        Node* temp = head;
        while (temp || !stk.empty())
        {
            if (temp == nullptr)
            {
                temp = stk.top();
                stk.pop();
            }
            temp->prev = tail;
            tail->child = nullptr;
            tail->next = temp;
            tail = temp;
            if (temp->child)
            {
                if (temp->next)
                {
                    stk.push(temp->next);
                }
                temp = temp->child;
            }
            else
            {
                temp = temp->next;
            }
        }
        tail->next = nullptr;
        tail->child = nullptr;
        dummy.next->prev = nullptr;
        return dummy.next;
    }
};
