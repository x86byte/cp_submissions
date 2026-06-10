

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
    int validator(string s, set<char> se)
    {
        cout << s << endl;
        size_t ctr  = 0;
        for(auto c : s)
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
        set<char> r_t;
        for(auto c : t)
            r_t.insert(c);
        for(auto c : r_t)
            cout << c;
        cout << endl;
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
        for(auto ch : rr)
            if(validator(ch, r_t))
                return ch;
        return "";
    }
};