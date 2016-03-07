class MinStack {
public:
    void push(int x) {
        if( s.empty() )
        {
            s.push(x);
            min.push(x);
        }
        else
        {
            s.push(x);
            min.push(std::min(x,min.top()));
        }
    }

    void pop() {
        s.pop();
        min.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
private:
    std::stack<int> s;
    std::stack<int> min;
};
