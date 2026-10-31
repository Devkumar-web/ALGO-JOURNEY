class Solution {
public:
    vector<int> dp;
    int recur(vector<int>& days,vector<int>& costs,int index){
        if(index>=days.size()){
            return 0;
        }

        int current_day=days[index];

        if(dp[index]!=-1){
            return dp[index];
        }

        if(index==days.size()){
            return costs[0];
        }

        //now only remaining choice are left
        int one_day=costs[0]+recur(days,costs,index+1);
        //lets suppose i am buying 7 day pass then i need to find a index whose value is greater than days[index]+6
        int i7=upper_bound(days.begin(),days.end(),days[index]+6)-days.begin();

        int seven_day=costs[1]+recur(days,costs,i7);

        int i30=upper_bound(days.begin(),days.end(),days[index]+29)-days.begin();

        int thirty_day=costs[2]+recur(days,costs,i30);

        return dp[index]=min(one_day,min(seven_day,thirty_day));

        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n=days.size();
        int max_day=*max_element(days.begin(),days.end());
        set<int> st={days.begin(),days.end()};
        dp.resize(max_day+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=max_day;i++){
            if(st.count(i)){
                int one_day=costs[0]+dp[i-1];
                int seven_day=costs[1]+dp[max(0,i-7)];
                int thirty_day=costs[2]+dp[max(0,i-30)];
            
                dp[i]=min(one_day,min(seven_day,thirty_day));
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[max_day];
    }
};