#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(const string& beginWord,const string& endWord, vector<string>& wordList)
    {
        unordered_set<string> mp(wordList.begin(),wordList.end());
        if(!mp.count(endWord))
        {
            return 0;
        }
        unordered_set<string> begin{beginWord};
        unordered_set<string> end{endWord};
        unordered_set<string> visited;
        int step=1;
        while(!begin.empty()&&!end.empty())
        {
            if(begin.size()>end.size())
            {
                swap(begin,end);
            }
            unordered_set<string> next;
            for(auto& word:begin)
            {
                string cur=word;
                for(int i=0;i<cur.size();i++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        if(c==word[i])
                        {
                            continue;
                        }
                        cur[i]=c;
                        if(end.count(cur))
                        {
                            return step+1;
                        }
                        if(mp.count(cur)&&!visited.count(cur))
                        {
                            visited.insert(cur);
                            next.insert(cur);
                        }
                    }
                    cur[i]=word[i];
                }
            }
            begin=next;
            step++;
        }
        return 0;
    }
};
