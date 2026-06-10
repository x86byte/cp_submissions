

class Solution {
public:
    int checker(string s, set<char> se)
    {
        for(auto c : s)
            for(auto i : se)
                if(c == i)
                    return true;
        return false;
    }
    int cf(char f, set<char> se)
    {
        for(auto i : se)
        {
            if(i == f)
                return 1;
        }
        return 0;
    }
    int validator(string s, set<char> se, string r_t)
    {
        set<char> sss;
        for(auto c : s)
            sss.insert(c);
        string rep;
        for(auto c : sss)
            rep += c;
        string r_s;
        for(int i = 0; i < rep.size(); i++)
        {
            if(cf(rep[i], se))
            {
                r_s += rep[i];
            }
        }
        size_t ctr  = 0;
        for(auto c : r_s)
            for(auto i : se)
                if(c == i){
                    ctr++;
                }
        if(ctr == se.size() && cf(s[0], se))
            return true;
        return false;
    }
    string minWindow(string s, string t)
    {
        if(s==t)
            return s;
        if(s.size() < t.size())
            return "";
        set<char> r_t;
        for(auto c : t)
            r_t.insert(c);
        vector<string> rr;
        int l = 0;
        int rs = s.size();
        for(int i = 0; i < s.size(); i++)
        {
            string re;
            for(int d = l; d<rs; d++)
            {
                re+= s[d];
            }
            if(re.size())
                if(checker(re, r_t) && cf(s[rs-1], r_t))
                    rr.push_back(re);
                else{
                    l = -1;
                    rs--;
                }
            l++;
        }
        int min = INT_MAX;
        string retme;
        for(auto ch : rr)
            if(validator(ch, r_t, t))
            {
                if(min > ch.size())
                {
                    min  = ch.size();
                    retme = ch;
                }
            }
        return retme;
    }
};