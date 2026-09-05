class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix=1;
        long long suffix=1;
        long long ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                prefix=1;
                ans=max((int)ans,0);
            }
            else{
                prefix*=nums[i];
                ans=max(prefix,ans);
            }
            
            
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                suffix=1;
                ans=max((int)ans,0);
            }
            else{
                suffix*=nums[i];
                 ans=max(ans,suffix);
            }
            
           
        }

        return ans;
       
    }
};