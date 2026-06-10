class Solution {
public:
    int is_token(string tn)
    {
        if(tn == "+" || tn == "-" || tn == "/" || tn == "*")
            return 1;
        return 0;
    }
    int evalRPN(vector<string>& t) {
        stack<int> stck;
        for(auto e : t)
        {
            if(is_token(e))
            {
                int f = stck.top(); stck.pop();
                int s = stck.top(); stck.pop();
                    cout << f << " " << s << endl;
                if(e == "-")
                {
                    stck.push(s - f);
                    continue;
                }
                if(e == "+")
                {
                    stck.push(s + f);
                    continue;
                }
                if(e == "/")
                {
                    stck.push(s / f);
                    continue;
                }
                if(e == "*")
                {
                    stck.push(f * s);
                    continue;
                }
            }
            else
            {
                stck.push(stoi(e));
            }
        }
        return abs(stck.top());
    }
};
