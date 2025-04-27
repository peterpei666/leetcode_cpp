#include <iostream>
#include <algorithm>
using namespace std;

class Bitset
{
public:
    vector<unsigned char> mp;
    int sz;
    int c=0;
    
    Bitset(int size)
    {
        sz=size;
        if(size%8)
        {
            mp=vector<unsigned char>(size/8+1);
        }
        else
        {
            mp=vector<unsigned char>(size/8);
        }
    }
    
    void fix(int idx)
    {
        if((mp[idx>>3]&(1<<(idx&7)))==0)
        {
            mp[idx>>3]|=(1<<(idx&7));
            c++;
        }
    }
    
    void unfix(int idx)
    {
        if(mp[idx>>3]&(1<<(idx&7)))
        {
            mp[idx>>3]&=~(1<<(idx&7));
            c--;
        }
    }
    
    void flip()
    {
        for(auto& b:mp)
        {
            b=~b;
        }
        c=sz-c;
    }
    
    bool all()
    {
        for(int i=0;i<sz/8;i++)
        {
            if(mp[i]!=255)
            {
                return false;
            }
        }
        for(int i=0;i<sz%8;i++)
        {
            if((mp[sz/8]&(1<<i))==0)
            {
                return false;
            }
        }
        return true;
    }
    
    bool one()
    {
        for(int i=0;i<sz/8;i++)
        {
            if(mp[i])
            {
                return true;
            }
        }
        if(sz%8&&mp[sz/8])
        {
            return true;
        }
        return false;
    }
    
    int count()
    {
        return c;
    }
    
    string toString()
    {
        string ret;
        for(int i=0;i<sz;i++)
        {
            if(mp[i>>3]&(1<<(i&7)))
            {
                ret.push_back('1');
            }
            else
            {
                ret.push_back('0');
            }
        }
        return ret;
    }
};
