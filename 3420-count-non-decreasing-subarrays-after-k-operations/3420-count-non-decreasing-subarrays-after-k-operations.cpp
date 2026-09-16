class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> q;
        int right=n-1;
        long long cost=0;
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            //now we need to think of how we would traverse
            long long count=1;
            long long val=nums[i];
            

            while(!q.empty() && q.back().first<val){
                
                int value=q.back().first;
                int cnt=q.back().second;
                q.pop_back();
                count+=cnt;
                cost+=1LL*(val-value)*cnt;

            }

            q.push_back({val,count});
            
            //now it might be possible that that total cost is greater than our required k
            while(cost>k){
                //now we need to reduce from right side
                cost-= 1LL*(q.front().first-nums[right]);


                if(q.front().second==1){

                    q.pop_front();
                }
                else{
                    q.front().second--;
                }
                right--;
            }
                ans+=right-i+1;
        }

        return ans;
    }
};