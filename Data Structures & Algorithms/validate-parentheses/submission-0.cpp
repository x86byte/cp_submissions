class Solution {
public:
    int to_rem(string &t, const char a, const char b)
    {
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == a)
                if(i + 1 < t.size())
                    if(t[i + 1] == b){
                        while(t[i] == a && i + 1 < t.size() && t[i + 1] == b)
                        {
                            t.erase(i, 2);
                            if(!t.size())
                                return -1;
                        }
                        return 1;
                    }
        }
        return 0;
    }
    bool isValid(string s) {
        const short sz = s.size();
            int i = 0;
        while(i < s.size()){
            int sp = s.size();
            if((to_rem(s, '(', ')') == -1))
                return true;
            if((to_rem(s, '[', ']') == -1))
                return true;
            if((to_rem(s, '{', '}') == -1))
                return true;
            i++;
            if(sp != s.size())
                i = 0;
        }
        return false;
    }
};