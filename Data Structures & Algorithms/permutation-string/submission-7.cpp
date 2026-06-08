class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        size_t sz = s1.size() - 1;
        int ctr = 0;
        int l = 0;
        int r = 0;
        int fqb[256] = {};
        for(int i = 0; i < s2.size(); i++)
        {
            ctr  =0;
            fqb[s2[l]- 'a']++;
            ctr++;
            if(ctr == sz)
            {
                for(int d =0; d<s1.size(); d++)
                {
                    if(fqb[s1[d]-'a'])
                        d++;
                    else
                    {
                        fqb[s2[l]- 'a']--;
                        l++;
                        break;
                    }
                    return true;
                }

            }
        }
        return false;
    }
};
