class Solution {
public:
    bool caneat(vector<int>&piles,int k,int h){
        long long total=0;
        for(auto pile:piles){
            total+=(pile/k)+(pile%k?1:0);
        }
        return total<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int ans;
        int high=*max_element(piles.begin(),piles.end());
        while(left<=high){
            int mid=(left+high)/2;
            if(caneat(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return ans;
    }
};