

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
    int cf2(char f, string se)
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
    int vv(string s, string t)
    {
        string r_s;
    
        for(int i = 0; i < s.size(); i++)
        {
            if(cf2(s[i], t))
            {
                r_s += s[i];
            }
        }
        cout << "r_s : "<< r_s  << endl;
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
        if(s==t)
            return s;
        if(s.size() < t.size())
            return "";
        set<char> r_t;
        for(auto c : t)
            r_t.insert(c);
        size_t req = r_t.size();
        vector<string> rr;
        int l = 0;
        int rs = s.size();
        int rs_b = rs;
        for(int i = 0; i < s.size(); i++)
        {
            string re;
            for(int i = 0; i < s.size(); i++)
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
                    if(checker(re, r_t) && cf(s[rs-1], r_t))
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
                cout << "trying :  " << ch << endl;
                if(min > ch.size() && vv(ch, t))
                {
                    min  = ch.size();
                    retme = ch;
                }
            }
        if(s.size() == t.size())
        {
            if(retme.size() < t.size())
                return "";
        }
        return retme;
    }
};