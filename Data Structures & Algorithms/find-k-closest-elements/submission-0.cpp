class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> re;
        vector<int> v;
        if(x == 1)
            return arr;
        int l = 0;
        for(auto i : arr)
            re.push_back(i);
        re.push_back(x);
        sort(re.begin(), re.end());
        for(int r = 0; r < re.size(); r++)
        {
            if(re[r] == x)
            {
                int t = r - k;
                for(int j = t; j <= k; j++)
                {
                    if(j >= re.size())
                        break;
                    v.push_back(re[j]);
                }
            }
        }
        return v;
    }
};