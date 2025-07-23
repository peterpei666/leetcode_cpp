#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static inline void replace(string& s,const string& from,const string& to)
    {
        size_t p=0;
        while((p=s.find(from,p))!=string::npos)
        {
            s.replace(p,from.length(),to);
            p+=to.length();
        }
    }
    
public:
    string entityParser(string text)
    {
        replace(text,"&quot;", "\"");
        replace(text,"&apos;", "'");
        replace(text,"&frasl;", "/");
        replace(text,"&lt;", "<");
        replace(text,"&gt;", ">");
        replace(text,"&amp;", "&");
        return text;
    }
};
