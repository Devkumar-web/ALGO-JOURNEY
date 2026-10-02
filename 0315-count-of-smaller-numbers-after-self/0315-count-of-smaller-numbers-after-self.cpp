class segment{
        public:
        long long size;
        vector<long long> tree;
        segment(long long n){
            size=1;
            while(size<n){
                size*=2;
            }

            tree.resize(2*size,0);
        }

        void update(long long node,long long start,long long end,long long value){
            if(start==end){
                tree[node]++;
                return;
            }
            long long mid=start+(end-start)/2;

            if(value<=mid){
                update(node*2+1,start,mid,value);
            }
            else{
                update(node*2+2,mid+1,end,value);
            }

            tree[node]=tree[node*2+1]+tree[node*2+2];

            return ;
        }

        long long get(long long l,long long r,long long start,long long end,long long node){
            if(l>end || r<start){
                return 0;
            }
            if(l<=start && r>=end){
                return tree[node];
            }

            long long mid=start+(end-start)/2;

            long long left=get(l,r,start,mid,node*2+1);
            long long right=get(l,r,mid+1,end,node*2+2);


            return left+right;
        }

};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> demo=nums;
        long long n=nums.size();
        vector<int> result(n,0);
        demo.erase(unique(demo.begin(),demo.end()),demo.end());
        sort(demo.begin(),demo.end());
        long long m=demo.size();
        segment st(m);
        //now we move from left
        for(long long i=n-1;i>=0;i--){
            long long index=lower_bound(demo.begin(),demo.end(),nums[i])-demo.begin();
            if(index==0){
                result[i]=0;
            }
            else{
                long long total=st.get(0,index-1,0,m-1,0);
                result[i]=total;
            }
            
            st.update(0,0,m-1,index);
        }


        return result;
    }
};