/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int re = 0;
public:
    bool isSubtree(TreeNode* r, TreeNode* sb)
    {
        if(!sb && !r && !r)
        {
            re = 1;
            return 1;
        }
        if(!r)
            return 0;
        if(!sb)
            return 0;
        if(r->val == sb->val)
        {
            if(!isSubtree(r->left, sb->left) || !isSubtree(r->right, sb->right))
                return 0;
        } else
        {
            isSubtree(r->left, sb);
            isSubtree(r->right, sb);
        }
        return re;
    }
};
