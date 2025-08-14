#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode* root)
    {
        if(!root)
        {
            return "null";
        }
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node)
            {
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                s+="null,";
            }
        }
        return s;
    }

    TreeNode* deserialize(const string& data)
    {
        if(data=="null")
        {
            return nullptr;
        }
        stringstream ss(data);
        string part;
        getline(ss,part,',');
        TreeNode* root=new TreeNode(stoi(part));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(!getline(ss,part,','))
            {
                break;
            }
            if(part!="null")
            {
                node->left=new TreeNode(stoi(part));
                q.push(node->left);
            }
            if(!getline(ss,part,','))
            {
                break;
            }
            if(part!="null")
            {
                node->right=new TreeNode(stoi(part));
                q.push(node->right);
            }
        }
        return root;
    }
};
