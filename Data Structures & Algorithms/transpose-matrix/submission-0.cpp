class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m)
    {
        vector<vector<int>> re;
            vector<int> rr;
            vector<int> r2;
            size_t ms = m[0].size() * m.size();
        int j = 0;
        for(int i = 0; i < m[0].size(); i++)
        {
            for(int d = 0; d < m.size(); d++)
            {
                rr.push_back(m[d][j]);
                if(rr.size()==2)
                {
                    re.push_back(rr);
                    rr.clear();
                }
            }
            j++;
        }
        return re;
    }
};