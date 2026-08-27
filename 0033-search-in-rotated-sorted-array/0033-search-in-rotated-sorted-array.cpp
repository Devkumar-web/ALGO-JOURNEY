class Solution {
public:
    int search(vector<int>& nums, int target) {
        //so our core should need to find which part is sorted if out current element is in that sorted part then only we would go that way
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[lo]<=nums[mid]){
                //check if target lie between this sorted part
                if(nums[lo]<=target && target<nums[mid]){
                    //that's mean current target lie in this sorted part
                    hi=mid-1;
                }
                else{
                    //that's mean our target is not there in this sorted part so we should go in opposite side
                    lo=mid+1;
                }
            }
            else{
                //that's mean our second part is sorted 
                if(nums[mid]<=target && target<=nums[hi]){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }


        return -1;
    }
};