class Solution {
public:
    string simplifyPath(string path) {
        //we have to create token
        stringstream ss(path);
        string token;
        
        //now we need to pop  only when there is double period
        stack<string> st;

        while(getline(ss,token,'/')){
            if(token==".."){
                //now we have to pop
                if(!st.empty()){
                    st.pop();
                }
            }
                else if(token=="" || token=="."){
                    //do nothing

                }
                else{
                    st.push(token);
                }

            
        }
        if(st.empty()){
            return "/";
        }
        string result="";
        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }

        return result;
    }
};