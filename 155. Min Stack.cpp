//
// Created by yxr on 2018/7/11.
//
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        this->min=INT_MAX;
    }

    void push(int x) {
        this->s.push_back(x);
        if(x<this->min)min=x;
    }

    void pop() {
        if(min==s.back()){
            min=INT_MAX;
            this->s.pop_back();
            for(int i=0;i<s.size();i++){
                if(s[i]<min)min=s[i];
            }
        }else{
            this->s.pop_back();
        }
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return min;
    }
private:
    vector<int> s;
    int min;
};

