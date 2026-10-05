using vi = vector<int>;
using s = string;
















using  namespace std;
#include <bits/stdc++.h>

int solve(vector<int>& n)
{
    vi dp(n.size(), 0);
    vi o;
    int ctr = 0;
    int re{};
    for(int i = 0; i < n.size(); i++)
    {
        //  low iq typeshit 1,3,1
        dp[i] = n[i];
        re = max(dp[i], re);
        for(int d=i+2; d<n.size();)
        {
            if(d+ctr >= n.size() )
                break;
            dp[i]+= n[d+ctr];
            if(d+2 < n.size())
            {
                ctr+=2;
            } else if(d+1 < n.size())
            {
                cout << dp[i] << endl;
                re = max(dp[i], re);
                dp[i] = n[i];
                ctr++;
            } else
            {
                cout << dp[i] << endl;
                break;
            }
            re = max(dp[i], re);
        }
    };
    return re;
}

class Solution {
public:
    int rob(vector<int>& n)
    {
        return solve(n);
    }

};
