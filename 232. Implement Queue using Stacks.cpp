//
// Created by yxr on 2018/7/12.
//
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty())front=x;
        s.push(x);

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        int t=s2.top();
        s2.pop();
        if(!s2.empty())
            front=s2.top();
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        return t;
    }

    /** Get the front element. */
    int peek() {
        if(s.empty())return NULL;
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> s2;
    int front=0;
};

