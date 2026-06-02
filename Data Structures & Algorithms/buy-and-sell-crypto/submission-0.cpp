class Solution {
public:
    int maxProfit(vector<int>& p)
    {
        int m = 0;
        int b = 0;
        const int psz  = p.size();
        for(int i = 0; i< psz; i++)
        {
            if(p[b] < p[i])
            {
                m = max(m, p[i] - p[b]);
            } else
                b = i;
        }
        return m;
    }
};
