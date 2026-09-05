class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int count=0;
        for(auto it:s){
            if(it=='('){
                count++;

            }
            else if(it==')'){

                count--;
            }
            ans=max(ans,count);
        }

        return ans;
    }
};