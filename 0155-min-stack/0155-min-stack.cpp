class MinStack {
public:
    int mini;

    //current->previous parent

    stack<pair<int,int> >st;

    MinStack() {
        //stack<pair<int,int> >st;
        mini=INT_MAX;
    }
    
    void push(int value) {
        if(value<mini){
            st.push({value,value});
            mini=value;
        }
        else{
            st.push({value,mini});
        }
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            mini=INT_MAX;
            return ;
        }
        mini=st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */