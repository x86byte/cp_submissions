class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n)
    {
        // [2,1,5,1,5,3]
        // 8, 7, 11, 9
        if(count(n.begin(), n.end(), target))
            return 1;
        int l =0, r =0, sum  = 0;
        int m = INT_MAX;
        int v = 0;
        for(int i = l; i < n.size(); i++)
        {
            sum += n[r];
            cout << n[r] << " "; 
            while(sum >= target)
            {
                m = min(m, r - l +1);
                sum -= n[l];
                l++;
                cout << endl;
            }
            r++;
        }
        if(m == INT_MAX)
            return 0;
        return m;
    }
};