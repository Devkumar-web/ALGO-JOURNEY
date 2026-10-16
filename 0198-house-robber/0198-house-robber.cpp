class Solution {
public:
   int recur(int index,vector<int>& nums,vector<int> &dp){

    if(index==0) return dp[index]=nums[index] ;

    if(index==1) return max(nums[index],nums[index-1]);

    if(dp[index]!=-1) return dp[index];
    
    int first=nums[index]+recur(index-2,nums,dp);
    int second=recur(index-1,nums,dp);
    return dp[index]=max(first,second);
   }
    int rob(vector<int>& nums) {
        vector<int>  dp(nums.size(),-1);
        return recur(nums.size()-1,nums,dp);
    }
};