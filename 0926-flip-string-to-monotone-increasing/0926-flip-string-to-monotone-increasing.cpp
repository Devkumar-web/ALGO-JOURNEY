class Solution {
public:
    vector<vector<int>> dp;
    int recur(string &s,int prev,int index){
        
        if(index==s.size()){
            return 0;
        }

        
        if(dp[index][prev]!=-1){
            return dp[index][prev];
        }
        int currbit=s[index]-'0';
        int mini=INT_MAX;

        if(prev==2){
            //you can have both choice 
            if(currbit==1){
                mini=min( mini, recur(s,1,index+1) );
                mini=min(mini,1+recur(s,0,index+1) );
            }
            else{
                mini=min(mini,1+recur(s,1,index+1));
                mini=min(mini,recur(s,0,index+1));
            }
            
            return dp[index][prev]=mini;

            
        }else{
            //now come to main part
            if(currbit==0){
                    if(prev==1){

                        return dp[index][prev]=1+recur(s,1,index+1);
                    }
                    else{
                        //means previous bit is ZERO
                        //lets see what we can do of this 
                        int ans=min(recur(s,0,index+1),1+recur(s,1,index+1));
                        mini=ans;
                        return dp[index][prev]=ans;

                    }
            }
            else{
                //mean's current index value is 1
                //so there are two chances if 
                //we also need to check prev bit
                if(prev==1){
                    return dp[index][prev]=recur(s,1,index+1);
                }
                else{
                    //means we have prev bit as 0 so for currentbit-1 we have two choices
                    int ans=min(recur(s,1,index+1),1+recur(s,0,index+1));
                    mini=ans;
                    return dp[index][prev]=ans;
                }
            }
        }
    }
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(3,-1));
        int count_one=0;
        int flip=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count_one++;
            }
            else{
                //now here is problem it cannot be solved easily
                //i need to choose which flip is best
                flip=min(flip+1,count_one);
            }
        }
        return flip;
        
    }
};