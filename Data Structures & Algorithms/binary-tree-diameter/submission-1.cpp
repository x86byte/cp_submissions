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
    int diameterOfBinaryTree(TreeNode* r)
    {
        if(!r)
            return 0;
        queue<TreeNode*> q;
        q.push(r);
        int m = 0;
        int ctr = 0;
        int l = 0, ri = 0;
        while(!q.empty())
        {
            size_t c  = q.size();
            for(int i = 0; i < c; i++)
            {
                TreeNode* h = q.front();
                cout << h->val << endl;
                q.pop();
                if(h->left)
                {
                    q.push(h->left);
                    l++;
                }
                if(h->right)
                {
                    q.push(h->right);
                    ri++;
                }
                if(!h->right && !h->left)
                {
                    m = max(ri, l);
                }
            }
        }
        return m+1;
    }
};
