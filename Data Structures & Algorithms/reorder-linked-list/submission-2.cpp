/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<ListNode*> _get_v(ListNode* rh)
    {
        vector<ListNode*> re;
        while(rh)
        {
            re.push_back(rh);
            rh = rh->next;
        }
        return re;
    }
    void reorderList(ListNode* h)
    {
        if(!h)
            return ;
        vector<ListNode*> re = _get_v(h);
        int r = re.size()-1;
        int l =0;
        while(l < r)
        {
            re[l]->next = re[r];
            l++;
            if(l>=r)
                break;
            re[r]->next = re[l];
            r--;
        }
        re[l]->next = nullptr;
    }
};
