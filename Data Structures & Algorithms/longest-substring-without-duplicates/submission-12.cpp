class Solution {
public:
    int fq[256] = {};
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        const int sz =  s.size();
        int max_len = 0;
        for(int i = 0; i < sz; i++)
        {
            int ctr = 0;
            fill(begin(fq), end(fq), 0);
            for(int j = i; j <sz; j++)
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