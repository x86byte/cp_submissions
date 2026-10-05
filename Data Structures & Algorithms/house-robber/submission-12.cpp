using vi = vector<int>;
using s = string;
















using  namespace std;
#include <bits/stdc++.h>

int solve(vector<int>& n)
{
    if(n.empty())
        return 0;
    if(n.size() == 1)
        return n[0];
    if(n.size() == 2)
        return (max(n[0], n[1]));
    vi dp(n.size(), 0);
    vi o;
    int re{};
    int ff = 2;
    dp[0] = n[0];
    dp[1] = n[1];
    for(int i = 2; i < n.size(); i++)
    {
        dp[i]=max(dp[i-1], n[i]+dp[i-2]);
        re = dp[i];
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
