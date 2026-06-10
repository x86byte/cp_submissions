class MinStack {
    stack<pair<int, int>>stck;
public:
    
    MinStack()
    {

    }
    void push(int val) {
        if(stck.empty())
            stck.push({val, val});
        else
            stck.push({val, min(val, stck.top().second)});
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
