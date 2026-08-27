class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     //peak element follow the concept of higher slope and lower slope
     int lo=0;
     int hi=nums.size()-1;
     if(hi==0){
        return 0;
     }
     if(nums[0]>nums[1]){
        return 0;
     }
     if(nums[hi]>nums[hi-1]){
        return hi;
     }

     lo++;
     hi--;
     while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }
        else if(nums[mid]>nums[mid-1]){
            lo=mid+1;
        }     
        else{
            hi=mid-1;
        }
        
        
        }

        return -1;

    }
};