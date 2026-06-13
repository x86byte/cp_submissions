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
    int ctr = 0;
public:
    int maxDepth(TreeNode* r)
    {
        if(!r)
            return 0;
        maxDepth(r->right);
        maxDepth(r->left);
        if(r->right || r->left)
            ctr++;
        return ctr+1;
    }
};
