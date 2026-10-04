class segment{
    public:
        int size;
        vector<int> tree;
        segment(int n){
            size=1;
            while(size<n){
                size*=2;
            }

            tree.resize(2*size,0);
        }

        //now we need to form only two function

        void update(int start,int end,int node,int index){
            if(start==end){
                tree[node]=1;
                return ;
            }

            int mid=start+(end-start)/2;

            if(index<=mid){
                update(start,mid,node*2+1,index);
            }
            else{
                update(mid+1,end,node*2+2,index);
            }

            tree[node]=tree[node*2+1]+tree[node*2+2];
        }

        long long count(int start,int end,int l,int r,int node){
            if(l>end || r<start){
                return 0;
            }

            if(l<=start && r>=end){
                return tree[node];
            }

            int mid=start+(end-start)/2;
            long long left=count(start,mid,l,r,node*2+1);
            long long right=count(mid+1,end,l,r,node*2+2);


            return left+right;
        }

};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        segment st(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        //now we are having value key pair 
        st.update(0,n-1,0,mp[nums1[0]]);
        long long ans=0;

        //now we should start calculation of whole thing
        for(int i=1;i<n;i++){
            int element = nums1[i];
            int index=mp[element];
            long long leftcommon=st.count(0,n-1,0,index,0);
            //now we got out left count we can get easily our calculation
            // long long leftcount=index;
            long long leftuncommon=i-leftcommon;
            long long totalright=(n-1-index);
            long long rightcommon=totalright-leftuncommon;
            ans+=(leftcommon*rightcommon);
            st.update(0,n-1,0,index);
        }

        return ans;
    }
};