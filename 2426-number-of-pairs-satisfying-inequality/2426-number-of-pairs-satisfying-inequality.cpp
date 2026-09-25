class counter{
    public:
     long long size=1;
     vector<long long> tree;
     counter(long long n){
        //now we need to think of something
        while(size<n){
            size*=2;
        }
        tree.resize(2*size,0);
     }

     void update(long long index,long long node,long long start,long long end){
        if(start==end){
            tree[node]+=1;
            return ;
        }

        long long mid=start+(end-start)/2;

        if(index<=mid){
            update(index,node*2+1,start,mid);
        }

        else{
            update(index,node*2+2,mid+1,end);
        }

        tree[node]=tree[node*2+1]+tree[node*2+2];

        return ;
     }

     //now we also need to get totalciunt

     long long total_count(long long l,long long r,long long node,long long start,long long end){
        if(l>end || r<start){
            return 0;
        }

        if(l<=start && r>=end ){
            return tree[node];
        }

            long long mid=start+(end-start)/2;

            long long left=total_count(l,r,node*2+1,start,mid);

            long long right=total_count(l,r,node*2+2,mid+1,end);

            return left+right;

     }


};
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        //lets create new vector
        
        long long n=nums1.size();
        vector<long long> a(n);
        for(long long i=0;i<n;i++){
            a[i]=nums1[i]-(long long)nums2[i];
        }
        vector<long long > demo=a;
        //now new size of our segment tree would be same as of 0 to demo.size after removal of duplicate element
        sort(demo.begin(),demo.end());
        demo.erase(unique(demo.begin(),demo.end()),demo.end());
        //now we need to think of somethinf more improtant
        long long maximum=demo.size();

        counter st(maximum);
        long long ans=0;

        for(auto it:a){
                long long index=lower_bound(demo.begin(),demo.end(),it)-demo.begin();
                long long pos=upper_bound(demo.begin(),demo.end(),it+diff)-demo.begin();
                ans+=st.total_count(0,pos-1,0,0,maximum-1);
                st.update(index,0,0,maximum-1);

        }


        return ans;
    }
};