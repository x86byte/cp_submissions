class Solution {
public:
    bool isPalindrome(string str)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        string s;
        for(auto c : str)
        {
            if(isalnum(c))
                s += c;
        }
        if(!s.size())
            return 1;
        int st = 0;
        int en = s.size() - 1;
        while(s[st] == s[en])
        {
            cout << s[st] << " " << s[en];
            st++;
            en--;
            if(st == en)
                return 1;
            if(st == s.size())
                return 1;
        }

        return 0;
    }
};
