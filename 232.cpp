class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        if( empty() ) front = x;
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while( !empty() )
        {
            h.push(s.top());
            s.pop();
        }
        h.pop();
        while( !h.empty() )
        {
            push(h.top());
            h.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return front;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> h;
    int front;
};
