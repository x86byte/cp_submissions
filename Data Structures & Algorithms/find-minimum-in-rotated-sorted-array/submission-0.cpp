class Solution {
public:
    int findMin(vector<int>&n)
    {
        return *min_element(n.begin(), n.end());
    }
};
