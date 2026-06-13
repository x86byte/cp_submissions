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
    bool hasCycle(ListNode* h)
    {
        ListNode* f = h;
        ListNode* s = h;
        while(f && f->next)
        {
            cout << f->val << endl;
            cout << s->val << endl;
            f = f->next->next;
            s = s->next;
            if(f == s){
                //cout << f->val << " " << s->val << endl;
                return 1;
            }
        }
        return 0;
    }
};
