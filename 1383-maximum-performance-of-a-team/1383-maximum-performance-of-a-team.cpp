class Solution {
public:
    int MOD=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
     vector<pair<int,int>> demo;
     for(int i=0;i<n;i++){
        demo.push_back({efficiency[i],speed[i]});
     }
     sort(demo.rbegin(),demo.rend());
     //now we have to go through all the possible minimum efficeincey 
     priority_queue<int,vector<int>,greater<int>> pq;
     long long total=0;
     long long ans=0;
     for(auto it:demo){
        //now
        int velocity=it.second;
        int power=it.first;
        //now we are including this power so we are gonna store ans 
        if(pq.size()<k){
            total+=velocity;
            pq.push(velocity);
        }
        else{
            total-=pq.top();
            pq.pop();
            total+=velocity;
            pq.push(velocity);
        }
        long long current=((total) *(long long)(power));
        if(current>ans){
            ans=current;
        }

     }
     ans%=MOD;

     return (int)ans;
    }
};