class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //now we have sorted cookies in size
        //also student requirement
        int student=0;
        int cookie=0;
        int n1=g.size();
        int n2=s.size();

        while(student<n1 && cookie<n2){
            //now we need to think of whether for current cookie size can be assign it to student or not 
            if(g[student]<=s[cookie]){
                count++;
                student++;
                cookie++;
            }
            else{
                //in this part we are coming because we were not able to assign current cookie to current student 
                //so we need to move higher size cookie
                cookie++;
            }
        }

        return count;
    }
};