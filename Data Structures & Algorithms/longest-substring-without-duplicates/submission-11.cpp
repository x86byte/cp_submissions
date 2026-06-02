class Solution {
public:
    int fq[256] = {};
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        int max_len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int ctr = 0;
            fill(begin(fq), end(fq), 0);
            for(int j = i; j < s.size(); j++)
            {
                unsigned char idx = static_cast<unsigned char>(s[j]);
                if(fq[idx]){
                    break;
                }
                ctr++;
                fq[idx]++;
            }
            max_len = max(max_len, ctr);
        }
        return max_len;
    }
};