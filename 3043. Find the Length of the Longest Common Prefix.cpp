#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        TrieNode* children[10];

        TrieNode()
        {
            memset(this->children, 0, sizeof(children));
        }
    };
    
    TrieNode* root;
    vector<int> arr = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
    
    void add(int x)
    {
        TrieNode* node = root;
        for (int i = count(x); i < 9; i++)
        {
            if (node->children[x / arr[i]] == nullptr)
            {
                node->children[x / arr[i]] = new TrieNode();
            }
            node = node->children[x / arr[i]];
            x %= arr[i];
        }
    }
    
    int find(int x)
    {
        TrieNode* node = root;
        int ans = 0;
        for (int i = count(x); i < 9; i++)
        {
            if (node->children[x / arr[i]] == nullptr)
            {
                break;
            }
            node = node->children[x / arr[i]];
            x %= arr[i];
            ans++;
        }
        return ans;
    }
    
    int count(int x)
    {
        for (int i = 0; i < 9; i++)
        {
            if (x >= arr[i])
            {
                return i;
            }
        }
        return -1;
    }
    
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        root = new TrieNode();
        for (int i : arr1)
        {
            add(i);
        }
        int ans = 0;
        for (int i : arr2)
        {
            ans = max(ans, find(i));
        }
        return ans;
    }
};
