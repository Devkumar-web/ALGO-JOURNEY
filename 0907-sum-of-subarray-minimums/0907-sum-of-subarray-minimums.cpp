class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        //so we have to find every possible subarray
        //so we have to store particular element 
        int n=arr.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            //let suppose we are working
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            right[i]=st.empty() ? n:st.top();

            st.push(i);
        }

        while (!st.empty()) st.pop();
      
        //lets store from left
        for(int i=0;i<n;i++){

            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();

            st.push(i);
        }

        long long ans=0;

        //now we need to count
        for(int i=0;i<n;i++){
            long long l=i-left[i];
            long long r=right[i]-i;
            ans =(ans+((l*r)%mod*arr[i])%mod)%mod;

        }

        return ans;

    }
};