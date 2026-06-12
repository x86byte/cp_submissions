class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n)
    {
        // [2,1,5,1,5,3]
        // 8, 7, 11, 9
        if(count(n.begin(), n.end(), target))
            return 1;
        vector<int> v;
        int l =0, r =0, sum  = 0;
        int m = INT_MAX;
        for(int i = l; i < n.size(); i++)
        {
            sum += n[l];
            if(sum >= target)
                return 1;
            for(int d= l+1; d<n.size(); d++)
            {
                sum+= n[d];
                r++;
                if(sum >= target){
                    if(m > r - l + 1)
                        m = r - l + 1;
                    v.push_back(r - l + 1);
                    r = l +1;
                    break;
                }
            }
            l++;
            sum = 0;
        }
        if(!v.size())
            return 0;
        return m;
    }
};