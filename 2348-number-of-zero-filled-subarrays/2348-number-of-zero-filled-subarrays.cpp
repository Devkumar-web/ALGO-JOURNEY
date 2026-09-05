class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //This question is saying only filled with zero
        //now i need you to understand
        int i=0,j=0;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            //now if i am encountering a non zero element then i would assume that from current element sub arrat cannot start jo i would update my starting point
            if(nums[i]==0){
                count+=i-j+1;
            }
            else{
                j=i+1;
            }
        }

        return count ;

        return 0;
    }
};