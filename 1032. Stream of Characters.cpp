#include <iostream>
#include <algorithm>
using namespace std;

class StreamChecker
{
    
private:
    struct node
    {
        node* child[26];
        bool tag;
        
        node() { memset(child, 0, sizeof(child)); tag = false; }
    };
    
    int n;
    node* root;
    string s;
    
    void insert(const string& s)
    {
        node* temp = root;
        for (const char& c : s)
        {
            if (temp->child[c - 'a'] == nullptr)
            {
                temp->child[c - 'a'] = new node();
            }
            temp = temp->child[c - 'a'];
        }
        temp->tag = true;
    }
    
public:
    StreamChecker(vector<string>& words)
    {
        n = 0;
        root = new node();
        for (auto& s : words)
        {
            reverse(s.begin(), s.end());
            insert(s);
        }
    }
    
    bool query(char letter)
    {
        s.push_back(letter);
        n++;
        node* temp = root;
        for (int i = n - 1; i >= 0; i--)
        {
            char c = s[i];
            if (temp->child[c - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->child[c - 'a'];
            if (temp->tag)
            {
                return true;
            }
        }
        return false;
    }
};
