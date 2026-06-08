class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        for(int i = 0; i <n.size(); i++)
        {
            if(i == k)
                return false;
            int t = n[i];
            for(int d = i+1; d <n.size(); d++)
            {
                if(abs(i - d) > k)
                    return false;
                cout << t << " " << n[d] << endl;
                if(t == n[d])
                    return true;
                if(d == k)
                    return false;
            }
        }
        return false;
    }
};