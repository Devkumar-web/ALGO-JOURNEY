class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        unordered_map<char,char> mapper;
        mapper['(']=')';
        mapper['{']='}';
        mapper['[']=']';
        stack<char> st;
        for(int i=0;i<n;i++){
            //now we need to see what we got
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(st.empty() || s[i]!=mapper[st.top()] ){
                    return false;
                }
            else{
                st.pop();

            }
        }
        if(st.empty())
        return true;

        return false;
    }
};