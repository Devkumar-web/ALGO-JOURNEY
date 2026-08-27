class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        int mini=INT_MAX;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            if(nums[lo]<=nums[mid]){
                //that's mean we have first sorted array 
                mini=min(mini,nums[lo]);
                lo=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                hi=mid-1;
            }
        }

        return mini;
    }
};