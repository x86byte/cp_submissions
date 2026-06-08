class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        size_t sz = s1.size() - 1;
        int ctr = 0;
        for(auto i = s2.begin(); i < s2.end();)
        {
            if(distance(i, s2.end()) >= sz)
            {
                ctr = 0;
                auto e = next(i, sz);
                auto bp = i;
                string t;
                while(bp <= e)
                {
                    t+= *bp;
                    bp++;
                }
                sort(t.begin(), t.end());
                bp = i;
                while(bp <= e)
                {
                    if(t[ctr] == s1[ctr]){
                        ctr++;
                    }
                    bp++;
                }
                if(ctr == s1.size())
                    return true;
                i++;
            } else
                return false;
        }
        return false;
    }
};
