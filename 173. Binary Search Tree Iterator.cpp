#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* p;
    
    BSTIterator(TreeNode* root)
    {
        p=root;
    }
    
    int next()
    {
        while(p)
        {
            s.push(p);
            p=p->left;
        }
        TreeNode* t=s.top();
        p=t->right;
        s.pop();
        return t->val;
    }
    
    bool hasNext()
    {
        return !(s.empty()&&p==nullptr);
    }
};
