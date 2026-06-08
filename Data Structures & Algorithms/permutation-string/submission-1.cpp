class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        size_t sz = s1.size() - 1;
        int ctr = 0;
        for(auto i = s2.begin(); i < s2.end();++i)
        {
            if(distance(i, s2.end()) >= sz)
            {
                auto e = next(i, sz);
                cout << " end = " << *e << endl;
                auto bp = i;
                string t;
                while(bp < e)
                {
                    t+= *bp;
                    bp++;
                }
                bp = i;
                while(bp < e)
                {
                    if(t[ctr] == s1[ctr])
                        ctr++;
                    bp++;
                }
                i++;
                if(ctr == sz-1)
                    return true;
            }
        }
        return false;
    }
};
