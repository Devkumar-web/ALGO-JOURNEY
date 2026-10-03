class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> st;
        for(auto  it:asteroids){
            if(it<0){
                //if we added any asteriod with left side it would explode till asteroid value is negative
                int asteroid=it;
                while(asteroid<0 && !st.empty() && st.top()>=0){
                    if( -1*asteroid < st.top() ){
                        asteroid=st.top();
                    }
                    else if(-1*asteroid==st.top()){
                        asteroid=0;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(asteroid!=0)
                st.push(asteroid);
            }
            else{
                st.push(it);
            }
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(),result.end());


        return result;
    }
};