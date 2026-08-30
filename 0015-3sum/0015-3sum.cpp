class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int k=n-1;
        vector<vector<int>> result;
        while(i<n){
            //now we have to select the j and k 
            //remember k would always be last index
            int constant=nums[i];
            j=i+1;
            k=n-1; 

            while(j<k&& j<n){
                //now we have to search whether all three element sum to 
                int makedsum=nums[i]+nums[j]+nums[k];
                if(makedsum>0){
                    k--;
                }
                else if(makedsum<0){
                    j++;
                }
                else{
                    //now we got are result
                    result.push_back({nums[i],nums[j],nums[k]});
                    int left=nums[j];
                    int right=nums[k];
                    while(j<n && left==nums[j]){
                        j++;
                    }

                    while(k>=0 && right==nums[k]){
                        k--;
                    }
                }
            }

            while( i<n  && constant==nums[i]){
                i++;
            }

        }

        return result;
    }
};