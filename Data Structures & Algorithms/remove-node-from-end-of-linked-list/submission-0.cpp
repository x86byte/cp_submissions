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
    int f= 0;
    int ctr =0;
public:
    ListNode* removeNthFromEnd(ListNode* h, int n)
    {
        if(!h || n <= 1)
            return nullptr;
        if(f)
            return h;
        if(ctr+1 == n && !f)
        {
            cout << h->val << endl;
            if(h->next && h->next->next)
                h->next = h->next->next;
            else
                h->next = nullptr;
            f = 1;
            return h;
        }
        ctr++;
        removeNthFromEnd(h->next, n);
        return h;
    }
};
