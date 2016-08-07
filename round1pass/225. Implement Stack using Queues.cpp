class Stack {
public:
    queue <int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue <int> t;
        while(q.size() > 1) {
            t.push(q.front());
            q.pop();
        }
        q.pop();
        while(!t.empty()) {
            q.push(t.front());
            t.pop();
        }
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};