class Solution {
public:
    int check(string s)
    {
        if (s.empty()) return 0;
        vector<int> re;
        for(int i = 0; i <s.size(); i++)
        {
            int ctr = 1;
            char t = s[i];
            for(int d = i+1; d<s.size(); d++)
            {
                if(s[d] == t)
                    ctr++;
                else
                    break;
            }
            re.push_back(ctr);
        }
        return *(max_element(re.begin(), re.end()));
    }
    int characterReplacement(string s, int k)
    {
        if(s.empty())
            return 0;
        set<char> ss;
        for(auto c : s)
            ss.insert(c);
        if(ss.size() == 1)
            return s.size();
        if(!k)
            return check(s);
        
        int max_len = 0;
        for(char target : ss)
        {
            int left = 0, count = 0;
            for(int right = 0; right < s.size(); right++)
            {
                if(s[right] != target) count++;
                while(count > k)
                {
                    if(s[left] != target) count--;
                    left++;
                }
                max_len = max(max_len, right - left + 1);
            }
        }
        return max_len;
    }
};