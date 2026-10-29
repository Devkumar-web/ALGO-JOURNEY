class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //just maintain two passes 
         int n = nums.size();
        std::vector<int> answer(n, 1);
        
        // Step 1: Compute prefix products directly inside the answer array
        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        
        // Step 2: Compute suffix products on the fly using a single variable
        int suffix_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix_product;
            suffix_product *= nums[i];
        }
        
        return answer;
    }
};