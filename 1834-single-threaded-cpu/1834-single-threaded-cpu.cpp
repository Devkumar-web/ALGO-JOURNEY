class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> result;
        int n=tasks.size();
        int index=0;
        vector<int> ans;
        for(auto it:tasks){
            result.push_back({it[0],it[1],index++});
        }
        sort(result.begin(),result.end());

        //now we need to define min heap for time and index
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        //we are managing pair in totaltime , index
        long long current_time=0;
    int i=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                current_time=max(current_time,1LL*result[i][0]);
            }

            while(i<n && current_time>=result[i][0]){
                pq.push({result[i][1],result[i][2]});
                i++;
            }

            if(!pq.empty()){
                //now we need to change the current_time
                int duration=pq.top().first;
                int index=pq.top().second;

                current_time=current_time+duration;
                ans.push_back(index);
                pq.pop();
            }

        }
            return ans;
    }
};