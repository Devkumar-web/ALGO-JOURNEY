class Solution {
public:
    int MOD=1e9+7;
    int recur(vector<vector<int>> &dp,int target,int k,int n){
        // if(target==0){
        //     return 1;
        // }
        //dice ended
        if(n==0){
           return target==0?1:0;
        }

        if(dp[n][target]!=-1){
            return (dp[n][target])%MOD;
        }

        long long total=0;
        for(int i=1;i<=k;i++){
            //let suppose  you are choosing any fase od dice then what you would ask
            if(i<=target)
            total=(total+(recur(dp,target-i,k,n-1))%MOD)%MOD;
        }

        return dp[n][target]=(int)(total)%MOD;

    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return recur(dp,target,k,n);
    }
};