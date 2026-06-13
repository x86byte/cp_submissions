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
    bool isPalindrome(ListNode* h)
    {
        vector<int> re;
        ListNode* rh = h;
        while(rh)
        {
            re.push_back(rh->val);
            rh = rh->next;
        }
        int l = 0;
        for(int r = re.size() - 1; r >= 0;)
        {
            if(l == r)
                return true;
            if(re[l] == re[r])
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};