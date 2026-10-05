using vi = vector<int>;
using s = string;
















using  namespace std;
#include <bits/stdc++.h>

     int solve(vector<int>& n)
    {
        int res{};
        int freq[5000]{};
        int mx{};
        if(n.size() == 1)
            return n[0];
        else if(n.size() == 2)
            return (max(n[0], n[1]));
        for(int i = 1; i < n.size(); i+=2)
        {
            if(i >= n.size())
                break;
            if(!freq[i - 1])
            {
                    mx = n[i-1];
                    cout << "mx 1 : " << mx<<endl;
                    freq[i - 1] = 1;
                    if(i + 1 < n.size())
                    {
                            if(!freq[i + 1])
		            {
		                    mx += n[i+1];
		                    cout << "mx 2 : " <<  mx<<endl;
		                freq[i + 1] = 1;	
		            }
            }
            } else
            {
                    if(i + 1 < n.size())
                    {
                        if(!freq[i + 1]){
                            mx += n[i+1];
                            cout << "mx 3 : " <<mx<<endl;
                            freq[i + 1] = 1;
                        }
                    }
            }
            res = max(mx, res);
        }
        int d{};
        for(auto i : n)
        	d = max(d, i);
        return (max(res,d));
        return res;
    };

class Solution {
public:
    int rob(vector<int>& n)
    {
        return solve(n);
    }

};
