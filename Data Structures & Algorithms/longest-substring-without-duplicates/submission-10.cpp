class Solution {
public:
    int fq[256] = {};
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        vector<int> re;
        int ctr = 0;
        for(int i = 0; i < s.size();)
        {
            unsigned char idx = static_cast<unsigned char>(s[i]);
            if(fq[idx]){
                re.push_back(ctr);
                break;
            }
            ctr++;
            fq[idx]++;
            if(i == s.size()-1)
            {
                re.push_back(ctr);
                break;
            }
            i++;
        }
        ctr=0;
        fill(begin(fq), end(fq), 0);
        for(int i = s.size() - 1; i >= 0; i--)
        {
            unsigned char idx = static_cast<unsigned char>(s[i]);
            if(fq[idx]){
                re.push_back(ctr);
                break;
            }
            ctr++;
            fq[idx]++;
            if(i == 0)
            {
                re.push_back(ctr);
                break;
            }
        }
        return *(max_element(re.begin(), re.end()));
    }
};
