class Solution {
public:
    string gcdOfStrings(string s1, string s2)
    {
        int  ret = 0;
        string sol = "";
        for(int i = 0; i < s1.size(); i++)
        {
            sol += (char)(gcd(s1[i], s2[i]));
            if(i == 1)
                return sol;
        }
        return "";
    }
};