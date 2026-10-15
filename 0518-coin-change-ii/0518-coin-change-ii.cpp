class Solution {
public:
    int recur(int index,int rem,vector<int>& coins,vector<vector<int>>& dp){
        if(index==0){
            if(rem%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(rem<0){
            return 0;
        }
        if(dp[index][rem]!=-1) return dp[index][rem];
        int notaken=recur(index-1,rem,coins,dp);
        int taken=0;
        if(coins[index]<=rem){
            taken=recur(index,rem-coins[index],coins,dp);
        }

        return dp[index][rem]=taken+notaken;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return recur(coins.size()-1,amount,coins,dp);
    }
};