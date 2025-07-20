#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct trie
{
    string serial;
    unordered_map<string,trie*> child;
};

class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths)
    {
        trie* root=new trie();
        for(auto& path:paths)
        {
            trie* cur=root;
            for(auto& node:path)
            {
                if(!cur->child.count(node))
                {
                    cur->child[node]=new trie();
                }
                cur=cur->child[node];
            }
        }
        unordered_map<string,int> freq;
        function<void(trie*)> construct=[&](trie* node)
        {
            if(node->child.empty())
            {
                return;
            }
            vector<string> v;
            for(auto& [f,c]:node->child)
            {
                construct(c);
                v.push_back(f+"("+c->serial+")");
            }
            sort(v.begin(),v.end());
            for(auto& s:v)
            {
                node->serial+=std::move(s);
            }
            freq[node->serial]++;
        };
        
        construct(root);
        vector<vector<string>> ans;
        vector<string> path;
        function<void(trie*)> make=[&](trie* node)
        {
            if(freq[node->serial]>1)
            {
                return;
            }
            if(!path.empty())
            {
                ans.push_back(path);
            }
            for(auto& [f,c]:node->child)
            {
                path.push_back(f);
                make(c);
                path.pop_back();
            }
        };
        
        make(root);
        return ans;
    }
};
