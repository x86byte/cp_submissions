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
public:
    int cmp(TreeNode* r, TreeNode* sb)
    {
        if(!sb && !r)
        {
            return 1;
        }
        if(!r || !sb)
            return 0;
        if(r->val != sb->val)
            return 0;
        return cmp(r->left, sb->left) && cmp(r->right, sb->right);
    }
    bool isSubtree(TreeNode* r, TreeNode* sb)
    {
        if(!r)
            return 0;
        if(cmp(r, sb))
            return 1;
        return isSubtree(r->left, sb) || isSubtree(r->right, sb);
    }
};
