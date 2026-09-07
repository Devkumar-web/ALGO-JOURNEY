class Solution {
public:
    string removeKdigits(string num, int k) {
        //now we need to remove all those maximum element which is greater and earlier to minimum element
        stack<int> st;
        int n=num.size();
        vector<int> toremove(n,0);
        if(k==n){
            return "0";
        }
        
        for(int i=0;i<n;i++){

            while(!st.empty() && k && num[st.top()]-'0' > num[i]-'0'){
                k--;
                toremove[st.top()]=1;
                st.pop();
            }
            if(k==0){
                break;
            }

            st.push(i);
        }

        while(!st.empty() && k){
            toremove[st.top()]=1;
            k--;
            st.pop();
        }

        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && k && num[st.top()]-'0' > num[i]-'0' ){
        //         k--;
        //         toremove[st.top()]=1;
        //         st.pop();
        //     }
        //     if(k==0){
        //         break;
        //     }

        //     st.push(i);
        // }


        string ans="0";
        string temp;
        for(int i=0;i<n;i++){
            if(toremove[i]==0){
                if(temp.size()==0 && num[i]=='0'){
                    continue;
                }
                temp.push_back(num[i]);
            }
        }
        
        ans=temp.size()?temp:ans;


        return ans;
    }
};