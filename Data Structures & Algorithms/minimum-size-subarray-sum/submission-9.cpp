class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n)
    {
        int l =0, sum  = 0;
        int m = INT_MAX;
        int v = 0;
        for(int r = 0; r < n.size(); r++)
        {
            sum += n[r];
            while(sum >= target)
            {
                m = min(m, r - l +1);
                sum -= n[l];
                l++;
            }
        }
        if(m == INT_MAX)
            return 0;
        return m;
    }
};