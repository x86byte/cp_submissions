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
        //  12 OUT(3), 3 OUT(1), 4 OUT(2), 6
        //  [12, 3, 3, 1, 4, 2, 6]
        ListNode* l= new ListNode();
        ListNode *l_h = l;
        vector<int> re;
        while(h)
        {
            re.push_back(h->val);
            if(h->next){
                re.push_back(gcd(h->val, h->next->val));
                h = h->next;
            }
            else
                break;
        }
        for(int i = 0; i < re.size(); i++){
            cout << re[i] << endl;
            l->val = re[i];
            if(i == re.size() - 1)
                break;
            l->next = new ListNode();
            l = l->next;
        }
        return l_h;
    }
};