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
                cout << " end = " << *e << endl;
                auto bp = i;
                string t;
                while(bp <= e)
                {
                    t+= *bp;
                    bp++;
                }
                cout <<"target : "<< t << endl;
                sort(t.begin(), t.end());
                bp = i;
                while(bp <= e)
                {
                    cout << "i : " << *bp <<endl;
                    if(t[ctr] == s1[ctr]){
                        cout << "equals : " << t[ctr]<< " "  <<s1[ctr] << endl;
                        ctr++;
                    }
                    bp++;
                }
                cout << "sz-1 : " << s1.size() <<endl;
                cout << "check ctr : " << ctr <<endl;
                if(ctr == s1.size())
                    return true;
                i++;
            } else




  cout << "i : " << *bp <<endl;
                    if(t[ctr] == s1[ctr]){
                        cout << "equals : " << t[ctr]<< " "  <<s1[ctr] << endl;
                        ctr++;
                    \}
                    bp++;
                \}
                cout << "sz-1 : " << s1.size() <<endl;
                cout << "check ctr : " << ctr <<endl;
                if(ctr == s1.size())
                    return true;
                i++;
            \} else
                return false;
        \}
        return false;
    \}
\};

































$0
                return false;
        }
        return false;
    }
};
