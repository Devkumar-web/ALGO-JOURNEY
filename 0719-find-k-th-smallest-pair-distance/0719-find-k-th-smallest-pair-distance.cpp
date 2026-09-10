class Solution {
public:
    int count(int mid,vector<int> &nums){
        int left=0;
        int n=nums.size();
        int cnt=0;
        for(int right=0;right<n;right++){

            while(nums[right]-nums[left]>mid){
                left++;
            }

            cnt+=(right-left);
        }

        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        while(low<high){
            int mid=low+(high-low)/2;
            if(count(mid,nums)>=k){
                //move to left
                high=mid;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};