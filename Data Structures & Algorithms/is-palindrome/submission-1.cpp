class Solution {
public:
    bool isPalindrome(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        set<char> se;
        for(auto c : s)
            if(isalnum(c))
            {
                cout << c << endl;
                if(!se.insert(c).second)
                    se.erase(c);
            }
        int sez = se.size();
        if(sez == 0 || sez == 1)
            return 1;
        return 0;
    }
};
