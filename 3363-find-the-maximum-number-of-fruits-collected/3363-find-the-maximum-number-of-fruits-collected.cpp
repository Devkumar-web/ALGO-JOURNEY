class Solution {
public:
    vector<vector<int>> dp;
    
    int recur2(vector<vector<int>> &fruits,int row,int col){
        //you should remember that you should not cross those row and column where
        if(row>=col){
            return -1;
        }
        if(row<0 || col<0 || row>=fruits.size() || col>=fruits.size()){
            return -1;
        }
        //now you should ask for maximum sum from all three direction
        if(row==fruits.size()-1 && col==fruits.size()-1){
            return fruits[row][col];
        }

        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        //try all three option
        int maxisum=0;
        maxisum=max(maxisum,recur2(fruits,row+1,col-1));
        maxisum=max(maxisum,recur2(fruits,row+1,col));
        maxisum=max(maxisum,recur2(fruits,row+1,col+1));

        //lets see what we can do
        return dp[row][col]=maxisum+fruits[row][col];
    }
    int recur3(vector<vector<int>> &fruits,int row,int col){
         if(row<=col){
            return -1;
        }
        if(row<0 || col<0 || row>=fruits.size() || col>=fruits.size()){
            return -1;
        }
        //now you should ask for maximum sum from all three direction
        if(row==fruits.size()-1 && col==fruits.size()-1){
            return fruits[row][col];
        }


        if(dp[row][col]!=-1){
            return dp[row][col];
        }


          int maxisum=0;
        maxisum=max(maxisum,recur3(fruits,row-1,col+1));
        maxisum=max(maxisum,recur3(fruits,row,col+1));
        maxisum=max(maxisum,recur3(fruits,row+1,col+1));

        //lets see what we can do
        return dp[row][col]=maxisum+fruits[row][col];

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int child1=0;
        int n=fruits.size();
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            child1+=fruits[i][i];
        }

        //now we can think if better answer for child2

        int chr=0;
        int chc=n-1;

        int child2=recur2(fruits,chr,chc);

        int r=n-1;
        int c=0;

        int child3=recur3(fruits,r,c);

        return child1+child2+child3;


    }
};