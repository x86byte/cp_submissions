class Solution {
public:
    int search(vector<int>& n, int t)
    {
        int l = 0;
        int r = n.size();
        int m = l+r/2;;

        for(int i = 0;i < n.size(); i++)
        {
            if(t > m)
            {
                l = m;
                m = r;
                while(l <m)
                {
                    if(t == n[l])
                        return l;
                    l++;
                }
            } else
                while(l <m)
                {
                    if(t == n[l])
                        return l;
                    l++;
                }
        }
        return -1;
    }
};
