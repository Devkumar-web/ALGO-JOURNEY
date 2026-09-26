class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //now let see
        priority_queue<pair<int,pair<int,int>>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];

            int distance=abs(x*x)+abs(y*y);

            if(pq.size()<k){
                pq.push({distance,{x,y}});
            }
            else{
                if(distance<pq.top().first){
                pq.pop();
                pq.push({distance,{x,y}});
            }
            }
            


        }
        //now i am left with smallest k points
        vector<vector<int>> result;

        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            result.push_back({x,y});
        }

        return result;
    }
};