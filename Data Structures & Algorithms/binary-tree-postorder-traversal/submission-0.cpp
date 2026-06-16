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
    vector<int> re;
public:
    vector<int> postorderTraversal(TreeNode* r)
    {
        if(!r)
            return re;
        postorderTraversal(r->left);
        postorderTraversal(r->right);
        re.push_back(r->val);
        return re;
    }
};