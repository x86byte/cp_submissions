class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        size_t sz = s1.size();
        int ctr = 0;
        for(auto i = s2.begin(); i < s2.end();++i)
        {
            if(distance(i, s2.end()) >= sz)
            {
                auto e = next(i, sz);
                while(i < e)
                {
                    if(*i == s1[ctr])
                        ctr++;
                    i++;
                }
                if(ctr == sz)
                    return true;
            }
        }
        return false;
    }
};
