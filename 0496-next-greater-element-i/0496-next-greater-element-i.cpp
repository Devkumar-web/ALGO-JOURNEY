class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int size2=nums2.size();
        stack<int> st;
        mp[nums2[size2-1]]=-1;
        st.push(nums2[size2-1]);
        //find next greater element for rvery element
        for(int i=size2-2;i>=0;i--){
            int curr=nums2[i];
            if(st.top()<=curr){

                
                while(!st.empty() && st.top()<=curr)
                st.pop();

                if(st.empty()){
                        mp[nums2[i]]=-1;
                }
                else{
                    mp[nums2[i]]=st.top();
                }

             st.push(nums2[i]);

            }

            else{
                
                mp[nums2[i]]=st.top();
                st.push(curr);

            }
            
        }

        vector<int> ans;
        for(auto  it:nums1){
            ans.push_back(mp[it]);
        }


        return ans;

    }
};