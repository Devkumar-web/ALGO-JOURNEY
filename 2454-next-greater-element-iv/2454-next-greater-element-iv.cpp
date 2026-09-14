class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        stack<int> first;
        stack<int> second;
        vector<int> result(n,-1);
          vector<int>  temp;
        for(int i=0;i<n;i++){

               
            while(!second.empty() && nums[second.top()]<nums[i]){
                //if current element is greater than element who have founded first greater element already
                result[second.top()]=nums[i];
                second.pop();
            }
            while(!first.empty() && nums[first.top()]<nums[i]){
               
                temp.push_back(first.top());
                // second.push(first.top());
                first.pop();
            }
            reverse(temp.begin(),temp.end());
            for(auto it:temp){
                second.push(it);
            }
            temp.clear();

                first.push(i);
        }


        return result;
      
        
    }
};