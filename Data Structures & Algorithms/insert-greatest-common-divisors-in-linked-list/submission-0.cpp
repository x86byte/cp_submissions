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
    ListNode* insertGreatestCommonDivisors(ListNode* h)
    {
        //  [12,3,4,6]
        //  13 OUT(3), 3 OUT(1), 4 OUT(2), 6
        //  [13, 3, 3, 1, 4, 2, 6]
        ListNode* l= new ListNode(h->val);
        cout << l->val << endl;
        vector<int> re;
        while(h->next)
        {
            h = h->next;
            re.push_back(h->val);
        }
        for(auto i : re)
            cout << i << endl;
        return l;
    }
};