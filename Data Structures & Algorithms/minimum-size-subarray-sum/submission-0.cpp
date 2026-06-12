class Solution {
public:
    int minSubArrayLen(int target, vector<int>& n)
    {
        // [2,1,5,1,5,3]
        // 8, 7, 11, 9
        vector<int> v;
        int l =0, r =0, sum  = 0;
        for(int i = l; i < n.size(); i++)
        {
            sum += n[l];
            cout << n[l]<< " ";
            for(int d= l+1; d<n.size(); d++)
            {
                sum+= n[d];
                cout << n[d]<< " ";
                if(sum >= target){
                    v.push_back(r - l + 2);
                    r = l +1;
                    break;
                }
                r++;
            }
            cout << endl;
            l++;
            sum = 0;
        }
        if(!v.size())
            return 0;
        return *min_element(v.begin(), v.end());
    }
};