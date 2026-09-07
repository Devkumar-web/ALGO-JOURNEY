class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        stack<int> st;

        //for left
        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }

            left[i]=st.empty()?-1:st.top();

            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        //for right
        for(int i=n-1;i>=0;i--){


            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            right[i]=st.empty()?n:st.top();

            st.push(i);
        }

        vector<int> width(n);
        int temp=0;
        for(int i=0;i<n;i++){
            temp=0;
            temp+=i-left[i];
            temp+=right[i]-i;
            width[i]=temp-1;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            temp=width[i]*heights[i];
            ans=max(ans,temp);
        }
        

        return ans;



        
    }
};