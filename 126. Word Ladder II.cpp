#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(const string& beginWord,const string& endWord, vector<string>& wordList)
    {
        unordered_set<string> mp(wordList.begin(),wordList.end());
        vector<vector<string>> res;
        if(!mp.count(endWord))
        {
            return res;
        }
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> depth;
        queue<string> q;
        q.push(beginWord);
        depth[beginWord]=1;
        mp.erase(beginWord);
        while(!q.empty())
        {
            int sz=(int)q.size();
            string word=q.front();
            q.pop();
            if(word==endWord)
            {
                break;
            }
            int step=depth[word];
            int n=(int)word.size();
            string cur=word;
            for(int i=0;i<n;i++)
            {
                for(char c='a';c<='z';c++)
                {
                    if(c==word[i])
                    {
                        continue;
                    }
                    cur[i]=c;
                    if(mp.count(cur))
                    {
                        if(!depth.count(cur))
                        {
                            depth[cur]=step+1;
                            q.push(cur);
                        }
                        if(depth[cur] == step + 1)
                        {
                            graph[word].push_back(cur);
                        }
                    }
                }
                cur[i]=word[i];
            }
        }
        vector<string> path={endWord};
        
        function<void(const string&)> dfs=[&](string word)
        {
            if(word==beginWord)
            {
                reverse(path.begin(),path.end());
                res.push_back(path);
                reverse(path.begin(),path.end());
            }
            int step=depth[word];
            for(int i=0;i<word.size();i++)
            {
                char ori=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(depth.count(word)&&depth[word]==step-1)
                    {
                        path.push_back(word);
                        dfs(word);
                        path.pop_back();
                    }
                }
                word[i]=ori;
            }
        };
        
        dfs(endWord);
        return res;
    }
};
