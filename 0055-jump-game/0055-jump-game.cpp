class Solution {
public:
    vector<int> dp;
    bool solve(vector<int> &nums,int index){
        //base case
        if(index>=nums.size()){
            return false;
        }

        if(index==nums.size()-1){
            return true;
        }


        if(dp[index]!=-1){
            if(dp[index]==1){
                return true;
            }
            else{
                return false;
            }
        }

        //lets see what we can do
        //fo current index you should find length
        int len=nums[index];
        for(int i=index+1;i<=index+len;i++){
            if(solve(nums,i)==true){
                dp[index]=1;
                return true;
            }
        }
        
        dp[index]=0;
        return false;
    }
    bool greedy(vector<int>& nums,int n){
        int farthest=0;
        for(int i=0;i<n;i++){

            if(i>farthest){
                return false;
            }

            //lets see what we can do
            int maxjump=i+nums[i];
            farthest=max(farthest,maxjump);
        }

        return true;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,false);
        dp[n]=false;
        dp[n-1]=true;
        //now start loop from n-2
        for(int i=n-2;i>=0;i--){
            int len=nums[i];

            for(int jump=i+1;jump<=min(i+len,n);jump++){

                //now check the value how you are going to do some work 
                if(dp[jump]==true){
                    dp[i]=true;
                }
            }

            // dp[i]=false;
        }


        return greedy(nums,n);
    }
};