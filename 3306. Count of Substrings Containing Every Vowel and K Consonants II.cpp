#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int cnt[5];
    
    inline bool valid()
    {
        return cnt[0]&&cnt[1]&&cnt[2]&&cnt[3]&&cnt[4];
    }
    
    inline int vowel(char c)
    {
        switch(c)
        {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
            default:
                return -1;
        }
    }
    
public:
    long long countOfSubstrings(const string& word, int k)
    {
        int n=(int)word.size();
        memset(cnt,0,sizeof(cnt));
        int next[n];
        for(int i=n-1,temp=n;i>=0;i--)
        {
            next[i]=temp;
            if(vowel(word[i])==-1)
            {
                temp=i;
            }
        }
        int l=0,r=0,con=0;
        long long ans=0;
        while(r<n)
        {
            int pr=vowel(word[r]);
            if(pr==-1)
            {
                con++;
            }
            else
            {
                cnt[pr]++;
            }
            while(con>k)
            {
                int pl=vowel(word[l]);
                if(pl==-1)
                {
                    con--;
                }
                else
                {
                    cnt[pl]--;
                }
                l++;
            }
            while(l<n&&valid()&&con==k)
            {
                ans+=next[r]-r;
                int pl=vowel(word[l]);
                if(pl==-1)
                {
                    con--;
                }
                else
                {
                    cnt[pl]--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
