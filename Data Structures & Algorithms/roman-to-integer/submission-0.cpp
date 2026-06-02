class Solution {
public:
    unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},

    };
    int romanToInt(string s) {
        const short sz = s.size();
        int res = 0;
        for(int i = 0; i < sz; i++){
            if(i + 1 < s.size())
                if(mp[s[i]] < mp[s[i+1]]){
                    res += mp[s[i +1]] - mp[s[i]];
                    i = i + 1;
                }
                else
                    res += mp[s[i]];
            else
                res += mp[s[i]];
        }
        return res;
    }
};