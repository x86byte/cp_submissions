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
    vector<vector<int>> re;
    vector<int> rr;
    int ctr = 0;
    int m= 0;
public:
    int dfs(TreeNode* r, int& d)
    {
        if(!r)
            return 0;
        int l = dfs(r->left, d);
        int rr= dfs(r->right, d);
        d = max(d, l+rr);
        return max(rr, l)+1;
    }
    int diameterOfBinaryTree(TreeNode* r)
    {
        if(!r)
            return 0;
        int d= 0;

        dfs(r, d);
        return d;
    }
};
