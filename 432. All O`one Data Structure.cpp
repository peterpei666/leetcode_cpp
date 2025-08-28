#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class node
{
public:
    int cnt;
    unordered_set<string> list;
    node* prev;
    node* next;
    
    node(int cnt)
    {
        this->cnt = cnt;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class AllOne
{
private:
    node* head;
    node* tail;
    unordered_map<string, node*> mp;
    
    static inline void remove(node* temp)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
    
public:
    AllOne()
    {
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(const string& key)
    {
        if (mp.count(key))
        {
            node* temp = mp[key];
            temp->list.erase(key);
            if (temp->next->cnt == temp->cnt + 1)
            {
                mp[key] = temp->next;
                temp->next->list.insert(key);
            }
            else
            {
                node* newnode = new node(temp->cnt + 1);
                temp->next->prev = newnode;
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next = newnode;
                newnode->list.insert(key);
                mp[key] = newnode;
            }
            if (temp->list.empty())
            {
                remove(temp);
            }
        }
        else
        {
            if (head->next->cnt == 1)
            {
                head->next->list.insert(key);
                mp[key] = head->next;
            }
            else
            {
                node* newnode = new node(1);
                head->next->prev = newnode;
                newnode->next = head->next;
                newnode->prev = head;
                head->next = newnode;
                newnode->list.insert(key);
                mp[key] = newnode;
            }
        }
    }
    
    void dec(const string& key)
    {
        node* temp = mp[key];
        temp->list.erase(key);
        if (temp->cnt == 1)
        {
            mp.erase(key);
        }
        else if (temp->prev->cnt == temp->cnt - 1)
        {
            temp->prev->list.insert(key);
            mp[key] = temp->prev;
        }
        else
        {
            node* newnode = new node(temp->cnt - 1);
            temp->prev->next = newnode;
            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev = newnode;
            newnode->list.insert(key);
            mp[key] = newnode;
        }
        if (temp->list.empty())
        {
            remove(temp);
        }
    }
    
    string getMaxKey()
    {
        if (tail->prev == head)
        {
            return "";
        }
        return *(tail->prev->list.begin());
    }
    
    string getMinKey()
    {
        if (head->next == tail)
        {
            return "";
        }
        return *(head->next->list.begin());
    }
};
