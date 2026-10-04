class Solution {
public:
    bool ispossible(int timelimit,vector<int> &bloomday,int m,int k){
        int count=0;
        for(auto it:bloomday){
            //if current day time is up then what we have to do 
            if(it>timelimit){
                count=0;
            }
            else{
                count++;
                if(count==k){
                    m--;
                    count=0;
                }
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //lets make function to make m bouquet
        //m = bouquet need to make
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(mid,bloomDay,m,k)){
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