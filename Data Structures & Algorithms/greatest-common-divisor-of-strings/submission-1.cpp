class Solution {
public:
    string gcdOfStrings(string s1, string s2)
    {
        string sol = "";
        set<char> s;
        for(int i = 0; i < s1.size(); i++)
        {
            char rrr = (char)(gcd(s1[i], s2[i]));
           if(s.insert(rrr).second)
                sol+= rrr;
        }
        return sol;
    }
};