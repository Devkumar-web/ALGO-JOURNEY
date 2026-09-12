class Solution {
public:

    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mini=INT_MAX;
        while(low<=high){
            //now we need to find whic part is sorted
            int mid=low+(high-low)/2;

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                mini=min(mini,nums[mid]);
                continue ;
            }
            if(nums[low]<=nums[mid]){
                //means left part is sorted
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                //means right part is sorted
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }

        return mini;
    }
};