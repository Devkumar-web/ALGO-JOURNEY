class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        int l=nums.size();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(nums[i]+nums[j]==target){
                    a.push_back(i);
                    a.push_back(j);
                    return a;
                }
            }
        }
    return a;
    }
};