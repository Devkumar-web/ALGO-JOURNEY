class Solution {
public:
    int MOD=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int ans=0;
        while(right>0){
            //take  minimum  element
            pair<int,int> p=pq.top();
            pq.pop();
            int element=p.first;
            int index=p.second;
            //now push next value
            if(left>1){
                left--;
                right--;
            }
            else{
                //now we need to calculate the value
                right--;
                //now left==1;
                ans=(ans+element)%MOD;

            }
            if(index<n-1){
                element=(element+nums[index+1])%MOD;
                pq.push({element,index+1});
            }
            

        }

        return ans;
    }
};