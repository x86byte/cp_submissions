

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
    int cf(char f, string se)
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
        string str;
        for(auto i : se)
            str+=i;
        for(int i = 0; i < rep.size(); i++)
        {
            if(cf(rep[i], str))
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
        if(ctr == se.size() && cf(s[0], str))
            return true;
        return false;
    }
    int vv(string s, string t)
    {
        string r_s;
        for(int i = 0; i < s.size(); i++)
        {
            if(cf(s[i], t))
            {
                r_s += s[i];
            }
        }
        int fq[256] = {};
        int fq2[256] = {};
        for(auto c : t)
            fq[c]++;
        for(auto i : r_s)
            fq2[i]++;
        size_t ctr = 0;
        for(int i = 0; i < 256; i++)
        {
            if(ctr == t.size())
                break;
            char c = t[ctr];
            if(fq2[c] < fq[c])
                return false;
            ctr++;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        const size_t s_z = s.size();
        const size_t t_z = t.size();
        if(s==t)
            return s;
        if(s.size() < t.size())
            return "";
        if(s.contains(t))
            return t;
        set<char> r_t;
        for(auto c : t)
            r_t.insert(c);
        size_t req = r_t.size();
        vector<string> rr;
        int l = 0;
        int rs = s.size();
        int rs_b = rs;
        string str;
        for(auto i : t)
            str+=i;
        for(int i = 0; i < s_z; i++)
        {
            string re;
            for(int i = 0; i < s_z; i++)
            {
                for(int d = l; d<rs; d++)
                {
                    re+= s[d];
                }
                if(re.empty())
                {
                    rs--;
                    continue;
                }
                if(re.size())
                    if(checker(re, r_t) && cf(s[rs-1], str))
                    {
                        rr.push_back(re);
                    }
                rs--;
                re.clear();
            }
            l++;
            rs = rs_b;
        }
        int min = INT_MAX;
        string retme;
        for(auto ch : rr)
            if(validator(ch, r_t, t))
            {
                if(min > ch.size() && vv(ch, t))
                {
                    min  = ch.size();
                    retme = ch;
                }
            }
        rr.clear();
        if(s_z == t_z)
        {
            if(retme.size() < t_z)
                return "";
        }
        return retme;
    }
};