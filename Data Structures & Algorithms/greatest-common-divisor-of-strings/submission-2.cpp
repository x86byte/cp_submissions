class Solution {
public:
    string gcdOfStrings(string s1, string s2)
    {
        if(s1.size() && s2.size() && s1[0] != s2[0])
            return "";
        string sol = "";
        set<char> s;
        for(int i = 0; i < s1.size(); i++)
        {
            char rrr = (char)(gcd(s1[i], s2[i]));
           if(s.insert(rrr).second)
                sol+= rrr;
        }
        if(!sol.size())
            return "";
        return sol;
    }
};