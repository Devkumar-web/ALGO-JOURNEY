class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
              int total=0;
        for(auto it:piles){
            pq.push(it);
            total+=it;
        }

        for(int i=0;i<k;i++){
            //now i am running k times so i have to think
            int value=pq.top();
            pq.pop();
            total=total-floor(value/2);
            value=value-floor(value/2);
            pq.push(value);
        }
  
        // while(!pq.empty()){
        //     total+=pq.top();
        //     pq.pop();
        // }

        return total;
    }
};