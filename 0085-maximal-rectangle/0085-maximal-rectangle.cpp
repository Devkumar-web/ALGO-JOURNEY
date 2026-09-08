class Solution {
public:
    int current(vector<int> &hist){
        int n=hist.size();
        stack<int> st;
        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i=0;i<n;i++){
            //we are doing for left
            while(!st.empty() && hist[st.top()]>hist[i]){
                st.pop();
            }
        left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    
    while(!st.empty()){
        st.pop();
    }

        //now doing for right 
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && hist[st.top()]>=hist[i]){
                st.pop();
            }

            right[i]=st.empty()?n:st.top();

            st.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int l=i-left[i];
            int r=right[i]-i;
            int width=(l+r)-1;
            ans=max(ans,width*hist[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //now we need to apply largest rectangle in histogram for each row  included
        int ans=0;
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int> hist(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    hist[j]++;
                }
                else {
                    hist[j]=0;
                }
            }
            //now after updating we should call function to get maximum area with current histogram available

            ans=max(ans,current(hist));
        }

        return ans;
    }
};