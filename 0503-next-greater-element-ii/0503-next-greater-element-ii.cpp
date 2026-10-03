class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        int size=2*n;
         vector<int> result(n,-1);
        for(int i=size-1;i>=0;i--){
            int actualindex=i%n;
            int current=nums[actualindex];
            while(!st.empty() && st.top()<=current){
                st.pop();
            }
            
            if(i<n){
                result[i]=st.empty()?-1:st.top();
            }

            st.push(current);
        }
        //vector<int> result;
        // for(int i=0;i<n;i++){
        //     result.push_back(mp[nums[i]]);
        // }

        return result;
    }
};