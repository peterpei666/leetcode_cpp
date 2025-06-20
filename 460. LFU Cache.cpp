#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache
{
private:
    int capacity,minf;
    unordered_map<int,list<pair<int,int>>> freq;
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> cache;
    
    inline void insert(int key,int f,int val)
    {
        freq[f].push_back({key,val});
        cache[key]={f,--freq[f].end()};
    }
    
public:
    LFUCache(int _capacity)
    {
        capacity=_capacity;
        minf=0;
    }
    
    int get(int key)
    {
        auto iter=cache.find(key);
        if(iter==cache.end())
        {
            return -1;
        }
        int f=iter->second.first;
        auto list_iter=iter->second.second;
        int val=list_iter->second;
        freq[f].erase(list_iter);
        if(freq[f].size()==0)
        {
            freq.erase(f);
            if(f==minf)
            {
                minf++;
            }
        }
        insert(key,f+1,val);
        return val;
    }
    
    void put(int key, int val)
    {
        if(capacity<=0)
        {
            return;
        }
        auto iter=cache.find(key);
        if(iter!=cache.end())
        {
            iter->second.second->second=val;
            get(key);
        }
        else
        {
            if(cache.size()==capacity)
            {
                cache.erase(freq[minf].front().first);
                freq[minf].pop_front();
                if(freq[minf].size()==0)
                {
                    freq.erase(minf);
                }
            }
            minf=1;
            insert(key,1,val);
        }
    }
};
