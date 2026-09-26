class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>> > pq;

        for(auto it:mp){
           
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                //now that mean heap size is equal to k
                if(pq.top().first<it.second){
                    //that's mean i need to push
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }

        vector<int> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};