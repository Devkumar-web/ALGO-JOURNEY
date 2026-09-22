class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maximum_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
                if(nums[i]>=0){
                    maximum_sum+=nums[i];
                }
                else{
                    nums[i]=abs(nums[i]);
                }

        }
        //now we have maximum_sum
        sort(nums.begin(),nums.end());
        long long cost=0;
        priority_queue<pair<long long,int> ,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({nums[0],0});
        int index=0;

        for(int cnt=0;cnt<k-1;cnt++){
            pair<long long,int> p=pq.top();
            pq.pop();
            cost=p.first;
            //now we need to generate two things
            index=p.second;
            if(index+1<n){
                 long long first=p.first-nums[index]+nums[index+1];
            long long second=p.first+nums[index+1];
            pq.push({first,index+1});
            pq.push({second,index+1});
            }
           
        }

       
        long long answer=maximum_sum-cost;

        return answer;
    }
};