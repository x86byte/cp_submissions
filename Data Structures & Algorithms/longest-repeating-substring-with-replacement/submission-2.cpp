class Solution {
public:
    int characterReplacement(string s, int k)
    {
        if(s.empty())
            return 0;
        set<char> ss;
        for(auto c : s)
            ss.insert(c);
        if(ss.size() == 1)
            return s.size();
        int st = 0;
        int en = s.size() - 1;
        vector<int> re;
        
        for(int i = 0; i < s.size(); i++)
        {
            int v = 0;
            int ctr = 0;
            string t = s;
            st = i;
            char c = s[st];

            for(int d = en; d >= 0;)
            {
                if(s[d] == c)
                {
                    ctr = 1;
                    while(st <= d)
                    {
                        ctr++;
                        if(t[st] != c)
                        {
                            t[st] = c;
                            v++;
                        }
                        st++;
                        if(v == k)
                            break;
                    }
                    re.push_back(ctr);
                    break;
                }
                d--;
            }
        }
        return *(max_element(re.begin(), re.end()));
    }
};
