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
    vector<int> inorderTraversal(TreeNode* r) {
        if(!r)
            return re;
        inorderTraversal(r->left);
        re.push_back(r->val);
        inorderTraversal(r->right);
        return re;
    }
};