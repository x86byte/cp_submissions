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
    void solve(ListNode* h, ListNode* hl, int ctr)
    {
        if(!h)
            return;
        if((ctr % 2) != 0)
            if(h->next == hl)
                return ;
        cout << h->val << " " << hl->val << endl;
        swap(h->val, hl->val);
        solve(h->next, hl, ctr);
    }

    void reorderList(ListNode* h)
    {
        ListNode* ch=h;
        ListNode* last = nullptr;
        /*
        [2,10,6,8,4]
        [2,10,4,8,6]
        ============
        [2,8,6,4]
        
        */
        int ctr =0;
        while(ch)
        {
            ctr++;
            last = ch;
            ch = ch->next;
        }
        if(last)
        {
            if(!h->next)
                return;
            h = h->next;
            if(ctr == 3)
            {
                swap(h->val, last->val);
                return;
            }
            solve(h, last, ctr);
        }
    }
};
