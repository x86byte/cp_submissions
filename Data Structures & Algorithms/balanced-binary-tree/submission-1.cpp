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
    int ll = 0;
    int rr =0;
    int mi = 0;
    int ma  = 0;
public:
    int rec(TreeNode* r)
    {
        if(!r)
            return 0;
        int  l = rec(r->left);
        int ri = rec(r->right);
        ma = max(ri, l);
        mi = min(ri, l);
        return max(l, ri)+1;
    }
    bool isBalanced(TreeNode* r)
    {
        if(!r)
            return true;
        cout << rec(r) << endl;
        if(ma == mi+1 || ma == mi)
            return true;
        return false;
    }
};
