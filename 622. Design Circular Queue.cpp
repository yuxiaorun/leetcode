//
// Created by yxr on 2018/8/14.
//
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> space;
    int front;int end;int size;int cur_size;
    MyCircularQueue(int k) {
        this->space=vector<int> (k, -1);
        this->front=0;
        this->end=0;
        this->size=k;
        this->cur_size=0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(cur_size>=size)return false;
        space[end]=value;
        end++;
        if(end>=size)end-=size;
        cur_size++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(cur_size==0)return false;
        space[front]=-1;
        front++;
        if(front>=size)front-=size;
        cur_size--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return space[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        int t=end-1;
        if(t<0)t=size-1;
        return space[t];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cur_size==0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cur_size==size;
    }
};
