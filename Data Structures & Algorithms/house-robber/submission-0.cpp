using vi = vector<int>;
using s = string;
















using  namespace std;
#include <bits/stdc++.h>

    int solve(vector<int>& n)
    {
        int res{};
        int freq[5000]{};
        int mx{};
        for(int i = 1; i < n.size(); i+=2)
        {
            if(i >= n.size())
                break;
            if(!freq[n[i - 1]])
            {
                    mx = n[i-1];
                    freq[n[i - 1]] = 1;
                    if(i + 1 < n.size())
                    {
                            if(!freq[n[i + 1]])
                    {
                            mx += n[i+1];
                        freq[n[i + 1]] = 1;	
                    }
                    else
                        continue;
            }
            } else
            {
                    if(i + 1 < n.size())
                    {
                        if(!freq[n[i + 1]]){
                            mx += n[i+1];
                            freq[n[i + 1]] = 1;
                        }
                    }
            }
            res = max(mx, res);
        }
        return res;
    };

class Solution {
public:
    int rob(vector<int>& n)
    {
        return solve(n);
    }

};
