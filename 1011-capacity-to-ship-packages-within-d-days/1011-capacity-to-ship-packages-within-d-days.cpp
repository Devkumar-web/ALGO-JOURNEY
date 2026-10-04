class Solution {
public:
    bool canship(vector<int>& weights,int days,int capacity){
        long long loader=0;
        long long count=0;
        for(auto weight:weights){


            if(weight>capacity){
                return false;
            }


           if(loader+weight==capacity){
            count++;
            loader=0;
           }
           else if(loader+weight>capacity){
            count++;
            loader=weight;
           }
           else{
            loader+=weight;
           }
        }
        
        if(loader>0){
            count++;
        }

        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int ans=1;
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(canship(weights,days,mid)){
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