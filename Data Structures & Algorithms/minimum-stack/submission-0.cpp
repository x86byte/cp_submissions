class MinStack {
    stack<pair<int, int>>stck;
    vector< int> v;
public:
    
    MinStack() {

    }
    void v_emp(stack<int> sss)
    {
        while(!sss.empty())
        {
            v.push_back(sss.top());
            sss.pop();
        }
    }
    void push(int val) {
        if(stck.empty())
        {
            stck.push({val, val});
        }
        else
        {
            int m = min(val, stck.top().second);
            stck.push({val, m});
        }
    }
    
    void pop() {
        stck.pop();
    }
    
    int top() {
        return stck.top().first;
    }
    
    int getMin() {
        return stck.top().second;
    }
};
