#include <iostream>
#include <algorithm>
using namespace std;

class MyLinkedList
{
public:
    struct node
    {
        int val;
        node* prev;
        node* next;
        
        node(int v): val(v),prev(nullptr),next(nullptr) {}
    };
    
    int sz=0;
    node* head;
    node* tail;
    
    MyLinkedList()
    {
        head=new node(0);
        tail=new node(0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int index)
    {
        if(index<0||index>=sz)
        {
            return -1;
        }
        node* temp=head->next;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val)
    {
        node* temp=new node(val);
        temp->next=head->next;
        temp->prev=head;
        head->next->prev=temp;
        head->next=temp;
        sz++;
    }
    
    void addAtTail(int val)
    {
        node* temp=new node(val);
        temp->next=tail;
        temp->prev=tail->prev;
        tail->prev->next=temp;
        tail->prev=temp;
        sz++;
    }
    
    void addAtIndex(int index, int val)
    {
        if(index<0||index>sz)
        {
            return;
        }
        node* temp=head;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        node* m=new node(val);
        m->next=temp->next;
        m->prev=temp;
        m->next->prev=m;
        temp->next=m;
        sz++;
    }
    
    void deleteAtIndex(int index)
    {
        if(index<0||index>=sz)
        {
            return;
        }
        node* temp=head->next;
        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        delete temp;
        sz--;
    }
};
