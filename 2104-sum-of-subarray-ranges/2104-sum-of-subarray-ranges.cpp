class Solution {
public:
    long long minimum(vector<int> &nums){
            //now we have to capture left and right
            int n=nums.size();

            vector<int> left(n,1);
            vector<int> right(n,1);

            stack<int> st;
            for(int i=n-1;i>=0;i--){

                while(!st.empty() && nums[st.top()]>nums[i]){
                    st.pop();
                }

                right[i]=st.empty()?n:st.top();

                st.push(i);
            }
            
            while(!st.empty()){
                st.pop();
            }
            //now for left side
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }

                left[i]=st.empty()?-1:st.top();

                st.push(i);
            }

            long long count=0;

            for(int i=0;i<n;i++){
                int l=i-left[i];
                int r=right[i]-i;
                count+=(l*r)*(long long)nums[i];
            }

            return count;
            


    }
    long long maximum(vector<int> &nums){
            int n=nums.size();
            vector<int> left(n,1);
            vector<int> right(n,1);

            long long count=0;
            stack<int> st;

            for(int i=n-1;i>=0;i--){

                while(!st.empty() && nums[st.top()]<nums[i]){
                    st.pop();
                }

                right[i]=st.empty()?n:st.top();

                st.push(i);
            }

            while(!st.empty()){
                st.pop();
            }

            for(int i=0;i<n;i++){

                while(!st.empty() && nums[st.top()]<=nums[i]){
                    st.pop();
                }

                left[i]=st.empty()?-1:st.top();

                st.push(i);
            }


            for(int i=0;i<n;i++){
                int l=i-left[i];
                int r=right[i]-i;

                count+=(long long)(l*r)*nums[i];
            }

            return count;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sumofminimum=0;
        long long sumofmaximum=0;
        sumofminimum=minimum(nums);
        sumofmaximum=maximum(nums);
        return sumofmaximum-sumofminimum;

    }
};