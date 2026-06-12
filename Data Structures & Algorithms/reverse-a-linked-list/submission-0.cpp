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
    ListNode* reverseList(ListNode* head)
    {
        vector<int> re;
        ListNode* h = head;
        while(h)
        {
            re.push_back(h->val);
            h = h->next;
            if(!h)
            {
                h = head;
                reverse(re.begin(), re.end());
                int ctr = 0;
                while(h)
                {
                    h->val = re[ctr];
                    ctr++;
                    h = h->next;
                }
                return head;
            }
        }

        return nullptr;
    }
};
