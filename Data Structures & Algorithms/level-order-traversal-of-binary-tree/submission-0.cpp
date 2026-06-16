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
    vector<vector<int>> levelOrder(TreeNode* r)
    {
        if(!r)
            return {};
        vector<vector<int>> re;
        queue<TreeNode*> q;
        q.push(r);
        re.push_back({r->val});
        while(!q.empty())
        {
            size_t qs = q.size();
            vector<int> rr;
            for(int i = 0; i < qs; i++)
            {
                TreeNode* h = q.front();
                q.pop();
                if(h->left){
                    q.push(h->left);
                    rr.push_back(h->left->val);
                }
                if(h->right){
                    q.push(h->right);
                    rr.push_back(h->right->val);
                }
            }
            if(rr.size())
                re.push_back(rr);
        }
        return re;
    }
};
