/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> re;
    int ctr = 0;
public:
    void dfs(Node* r)
    {
        for(auto i : r->children)
        {
            dfs(i);
        }
        re.push_back(r->val);
    }
    vector<int> postorder(Node* r)
    {
        if(!r)
            return re;
        dfs(r);
        return re;
    }
};