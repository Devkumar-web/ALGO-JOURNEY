class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //lets see 
        priority_queue<int , vector<int> , greater<int> > pq1;
        //now lets see how we can solve this question
        priority_queue<int ,vector<int> , greater<int> > pq2;

        long long result=0;

        //lets see what we can do 
        int i=0;
        int j=costs.size()-1;
        while(k--){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }

            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j--]);
            }

            int min1=1e9;
            int min2=1e9;


            if(pq1.size()>0)
             min1=pq1.top();

            if(pq2.size()>0)
             min2=pq2.top();



            if(min1==1e9 && min2==1e9){
                break;
            }
           
            if(min1<=min2){
                result+=min1;

                if(pq1.size()>0)
                pq1.pop();
            }
            else{
                result+=min2;

                if(pq2.size()>0)
                pq2.pop();
            }
        }


        return result;
    }
};