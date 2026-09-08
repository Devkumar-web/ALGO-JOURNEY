class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> st;
        int n=nums.size();
        for(int i=0;i<k;i++){
           while(!st.empty() && nums[st.back()]<nums[i]){
            st.pop_back();
           }
           st.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[st.front()]);

        for(int i=k;i<n;i++){
            //now we need to check every point
            while(!st.empty() && nums[st.back()]<nums[i]){
                st.pop_back();
            }
            st.push_back(i);

            if((i-st.front()+1)>k){
                //that's mean we went out of size
                st.pop_front();
            }
            ans.push_back(nums[st.front()]);
        }

        return ans;

    }
};