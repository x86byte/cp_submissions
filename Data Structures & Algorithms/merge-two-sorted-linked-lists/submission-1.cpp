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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* h = l1;
        ListNode* h2 = l2;
        vector<int> re;
        while(h)
        {
            re.push_back(h->val);
            h = h->next;
        }
        while(h2)
        {
            re.push_back(h2->val);
            h2 = h2->next;
        }
        if(re.empty())
            return nullptr;
        sort(re.begin(), re.end());
        ListNode* no = new ListNode(re[0]);
        ListNode* h_no = no;
        for(int i = 1; i <re.size(); i++)
        {
            cout << re[i];
            no->next = new ListNode(re[i]);
            no = no->next;
        }
        return h_no;
    }
};
