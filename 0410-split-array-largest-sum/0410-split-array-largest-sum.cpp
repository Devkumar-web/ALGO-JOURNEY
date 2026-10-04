class Solution {
public:
    bool isvalid(vector<int>& nums,int k,int limit){
        long long slide=0;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            if(slide+nums[i]>limit){
                count++;
                slide=nums[i];
            }else if(slide==limit){
                count++;
                slide=0;
            }
            else{
                slide+=nums[i];
            }
        }

        if(slide>0){
            count++;
        }

        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(isvalid(nums,k,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};