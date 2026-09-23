class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        //lets see how to solve this 
        vector<vector<int>> combine;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            combine.push_back({nums1[i],nums2[i],i});
        }
        sort(combine.begin(),combine.end());
        priority_queue<int,vector<int>,greater<int>> pq;
          long long  totalsum=0;
        vector<long long> result(n,0);
        int i=0;
        int j=0;
        while(i<n){
            j=i;

            while(j<n && combine[i][0]==combine[j][0]){
                j++;
            }

            //now put all 
            for(int k=i;k<j;k++){
                result[combine[k][2]]=totalsum;
            }
            
            for(int p=i;p<j;p++){
                if(pq.size()<k){
                    pq.push(combine[p][1]);
                    totalsum+=combine[p][1];
                }
                else{
                    if(pq.top()<combine[p][1]){
                        totalsum-=pq.top();
                        pq.pop();
                        pq.push(combine[p][1]);
                        totalsum+=combine[p][1];
                    }
                }
            }
                i=j;
        }
        return result;
    }
};