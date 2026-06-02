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
                cout <<"repeted : " << s[i] << endl;
                s.erase(i, 1);
                cout << "ctr : " << ctr << endl;
                re.push_back(ctr);
                ctr=0;
                fill(std::begin(fq), std::end(fq), 0);
                continue;
            }
            ctr++;
            cout << "fresh : " << s[i] << endl;
                cout << "ctr : " << ctr << endl;
            fq[idx]++;
            if(i == s.size()-1)
            {
                re.push_back(ctr);
                break;
            }
            i++;
        }
        return *(max_element(re.begin(), re.end()));
    }
};
