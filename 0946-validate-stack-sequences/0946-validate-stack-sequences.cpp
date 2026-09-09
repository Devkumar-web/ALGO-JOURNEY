class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int front=0;
        int n=pushed.size();
        for(int i=0;i<n;i++){
            st.push(pushed[i]);

            while(!st.empty() && front<n && st.top()==popped[front]){
                front++;
                st.pop();
            }
        }
        return st.empty();
    }
};