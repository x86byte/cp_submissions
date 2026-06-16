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
    vector<int>re;
public:
    vector<int> preorderTraversal(TreeNode* r) {
        if(!r)
            return re;
        re.push_back(r->val);
        preorderTraversal(r->left);
        preorderTraversal(r->right);
        return re;
    }
};