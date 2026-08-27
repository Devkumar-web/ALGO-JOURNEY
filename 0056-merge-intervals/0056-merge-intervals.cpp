class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //let see how we can merge these
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        //now we have merged innterval 
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            //now store current first and lastpoint
            int firstpoint=intervals[i][0];
            int lastpoint=intervals[i][1];
            int back=result.back()[1];
            if(back>=firstpoint){
                int first=result.back()[0];
                int second=back>lastpoint?back:lastpoint;
                result.pop_back();
                result.push_back({first,second});
            }
            else{
                result.push_back(intervals[i]);
            }
            
         }


         return result;
    }
};