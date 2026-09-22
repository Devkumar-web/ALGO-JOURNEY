class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> >>,greater<pair<int,pair<int,int> >>> pq;
        
        //pq.push({nums1[0]+nums2[0],{0,0}});
        int size1=nums1.size();
        int size2=nums2.size();
        for(int i=0;i<min(k,(int)size1);i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> result;

        for(int i=0;i<k && !pq.empty();i++){
            pair<int,pair<int,int> > p=pq.top();
            pq.pop();
            int i1=p.second.first;
            int i2=p.second.second;
            result.push_back({nums1[i1],nums2[i2]});
            if(i2+1<size2){
                pq.push({nums1[i1]+nums2[i2+1],{i1,i2+1}});
            }

        }
        return result;
    }
};