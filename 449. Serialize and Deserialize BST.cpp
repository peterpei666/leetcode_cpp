#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec
{
private:
    void preorder(string& s,TreeNode* node)
    {
        char temp[4];
        memcpy(temp,&node->val,sizeof(int));
        for(int i=0;i<4;i++)
        {
            s.push_back(temp[i]);
        }
        if(node->left)
        {
            preorder(s,node->left);
        }
        if(node->right)
        {
            preorder(s,node->right);
        }
    }
    
    TreeNode* construct(const string& s,int& idx,int mini,int maxi)
    {
        if(idx==s.size())
        {
            return nullptr;
        }
        int val;
        memcpy(&val,&s[idx],sizeof(int));
        if(val<mini||val>maxi)
        {
            return nullptr;
        }
        TreeNode* node=new TreeNode(val);
        idx+=sizeof(int);
        node->left=construct(s,idx,mini,val);
        node->right=construct(s,idx,val,maxi);
        return node;
    }
    
public:
    string serialize(TreeNode* root)
    {
        if(root==nullptr)
        {
            return "";
        }
        string s="";
        preorder(s,root);
        return s;
    }

    TreeNode* deserialize(const string& data)
    {
        int idx=0;
        return construct(data,idx,INT_MIN,INT_MAX);
    }
};
