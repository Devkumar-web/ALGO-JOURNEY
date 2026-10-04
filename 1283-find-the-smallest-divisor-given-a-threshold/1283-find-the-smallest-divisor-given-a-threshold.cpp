class Solution {
public:
   bool isvalid(vector<int> &nums,int limit,int divisor){
    double totalsum=0;
    for(auto num:nums){
        totalsum+=ceil((double)num/(double)divisor);
    }

    return totalsum<=limit;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int ans;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(isvalid(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};