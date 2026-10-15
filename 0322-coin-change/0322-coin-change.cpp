class Solution {
public:
  int recur(vector<int>&coins,int rem,vector<int>&dp){
    if(rem==0){
        return 0;
    }
    if(rem<0){
        return -1;
    }
    if(dp[rem]!=-2) return dp[rem];
        int mini=INT_MAX;
    for(auto it:coins){
        int res=recur(coins,rem-it,dp);

        if(res>=0 && res<mini){
                mini=1+res;
        }

    }
    dp[rem]=(mini==INT_MAX)?-1:mini;
    return dp[rem];
  }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
       

       for(int i=0;i<=amount;i++){

        for(auto coin:coins){
            if(i-coin>=0 && dp[i-coin]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }
       }

       return dp[amount]==INT_MAX?-1:dp[amount];

    }
};