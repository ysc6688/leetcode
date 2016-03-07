class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        Top = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        int size = q.size();
        for(int i = 0; i < size - 1; ++ i)
        {
            h.push(q.front());
            q.pop();
        }
        q.pop();
        while( !h.empty() )
        {
            push(h.front());
            h.pop();
        }
    }

    // Get the top element.
    int top() {
        return Top;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    queue<int> h;
    int Top;
};
