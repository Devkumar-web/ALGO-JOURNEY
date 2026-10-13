class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        vector<int> valid(s.size(),0);
        string result;
        for(int i=0;i<s.size();i++){
            //lets see what we can do
            if(s[i]=='('){
                valid[i]=-1;
                st.push({'(',i});
            }
            else if(s[i]==')'){
                //that's mean we have to pop
                if(!st.empty()){
                    valid[st.top().second]=0;
                    st.pop();
                }
                else{
                    //means we encountered which cannot be closed
                    valid[i]=-1;
                }
                
            }
        }
        // while(!st.empty()){
        //     //now we need to mark all invalid
        //     //lets see what we can do
        //     valid[st.top().second]=-1;
        //     st.pop();
        // }
        for(int i=0;i<s.size();i++){
            if(valid[i]!=-1){
                result.push_back(s[i]);
            }
        }

        return result;
    }
};