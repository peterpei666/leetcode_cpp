#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class TextEditor
{
private:
    deque<char> q1;
    deque<char> q2;
    
public:
    void addText(const string& text)
    {
        for (const char& c : text)
        {
            q1.push_back(c);
        }
    }
    
    int deleteText(int k)
    {
        int ans = min(k, (int)q1.size());
        for (int i = 0; i < ans; i++)
        {
            q1.pop_back();
        }
        return ans;
    }
    
    string cursorLeft(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (q1.empty())
            {
                break;
            }
            char c = q1.back();
            q2.push_front(c);
            q1.pop_back();
        }
        int l = min(10, (int)q1.size());
        string s(l, 'a');
        for (int i = l - 1; i >= 0; i--)
        {
            s[i] = q1.back();
            q1.pop_back();
        }
        for (int i = 0; i < l; i++)
        {
            q1.push_back(s[i]);
        }
        return s;
    }
    
    string cursorRight(int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (q2.empty())
            {
                break;
            }
            char c = q2.front();
            q1.push_back(c);
            q2.pop_front();
        }
        int l = min(10, (int)q1.size());
        string s(l, 'a');
        for (int i = l - 1; i >= 0; i--)
        {
            s[i] = q1.back();
            q1.pop_back();
        }
        for (int i = 0; i < l; i++)
        {
            q1.push_back(s[i]);
        }
        return s;
    }
};
