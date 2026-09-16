class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> l,r;
        for(auto it:flowers){
            l.push_back(it[0]);
            r.push_back(it[1]);
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        //now we need to find for rvery query
        int q=people.size();
        vector<int> result;
        for(auto it:people){
            int left=upper_bound(l.begin(),l.end(),it)-l.begin();
            int right=lower_bound(r.begin(),r.end(),it)-r.begin();
            int count=left-right;
            result.push_back(count);
        }

        return result;
    }
};