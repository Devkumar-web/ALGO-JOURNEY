class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //now we can work in O(n3)
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> result;
        if(n<=3){
            return {};
        }
        int i=0;
        int j=1;
        while(i<n-3){
             int constant1=nums[i];
            j=i+1;
            while(j<n-2){
                int constant2=nums[j];
               
                //now we have selected two element

                int first=j+1;
                int second=n-1;
               
                while(first<second){

                int firstelement=nums[first];
                int secondelement=nums[second];

                long long part1=constant1+constant2;
                long long remaining=target-part1;
                long long current=firstelement+secondelement;


                if(current<remaining){
                    while(first<n && firstelement==nums[first]){
                        first++;
                    }
                }

                else if(current>remaining){

                    while(second >j && secondelement==nums[second]){
                        second--;
                    }
                }

                else{
                    //now we need to store the answer
                    result.push_back({nums[i],nums[j],nums[first],nums[second]});


                   while(first<n && firstelement==nums[first]){
                        first++;
                    }

                    while(second >= j && secondelement==nums[second]){
                        second--;
                    }
                }
            }
            while(j<n && constant2==nums[j]){
                j++;
            }

            
        }

        while(i<n && constant1==nums[i]){
                i++;
            }
            

        }

        return result;
    }
};