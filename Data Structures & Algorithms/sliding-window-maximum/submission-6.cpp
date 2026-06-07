class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& n, int k)
    {
        if(n.size() == 1)
            return {n};
        if(k == 1)
            return n;
        if(n.size() == 2){
            return {*max_element(n.begin(), n.end())};
        }
        vector<int> re;
        vector<vector<int>> t;
        int l, r; 
        l = 0;r = 0;
        int ctr= 0;
            while(1)
            {
                if(r == n.size())
                    break;
                cout << "ctr " << ctr << endl;
                cout << "right " << n[r] << endl;
                re.push_back(n[r]);
                ctr++;
                if(ctr == k){
                    l++;
                    cout << "left " << n[l] << endl;
                    t.push_back(re);
                    re.clear();
                    cout << "yay push the head : " << n[l] << endl;
                    re.push_back(n[l]);
                    re.push_back(n[r]);
                    ctr = 0;
                    ctr+=2;
                }
                r++;
            }
        vector<int> f;
        for(auto i : t){
            for(auto ii : i)
                cout << ii ;
            cout << endl;
            f.push_back(*max_element(i.begin(), i.end()));
        }
        return f;
    }
};
