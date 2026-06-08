class Solution {
public:
    int checker(string v, string t)
    {
        sort(t.begin(), t.end());
        string re;
        for(int i = 0;i < v.size(); i++)
        {
            char c = v[i];
            for(int d = 0; d<t.size(); d++)
            {
                cout << c << endl;
                if(c == t[d]){
                    re+= c;
                    cout << "char : " << c << " string : " <<re << endl;
                    break;
                }
                if(d == t.size())
                    return false; 
            }
            sort(re.begin(), re.end());
            if(re == t)
                return true;
        }

        return false;
    }
    string minWindow(string s, string t)
    {
        string re;
        if(s.size() < t.size())
            return re;
        if(s == t)
            return s;
        int l = 0;
        int k = t.size();
        vector<string> ss;
        int ctr =0;
        for(int i = l; i < s.size();)
        {
            re+=s[i];
            if(ctr== k-1)
            {
                if(i+1 < s.size())
                    re+= s[i+1];
                l++;
                i = l;
                ctr=0;
                ss.push_back(re);
                re.clear();
                continue;
            } else
                i++;
            ctr++;
        }
        set<char> se;
        for(auto v : ss)
        {
            if(checker(v, t))
                return v;
            cout << v << endl;
        }
        return "";
    }
};
