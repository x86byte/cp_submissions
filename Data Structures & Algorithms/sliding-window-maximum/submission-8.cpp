class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& n, int k)
    {
        if(n.size() == 1)
            return {n};
        if(k == 1)
            return n;
        if(n.size() == 2){
            return {*max_element(n.begin(), n.end())};
        }
        vector<int> re;
        for(auto i = n.begin(); i<n.end(); ++i)
        {
            if(distance(i, n.end()) >= k)
            {
                auto e = next(i, k);
                re.push_back(*max_element(i, e));
            }
        }
        return re;
    }
};
