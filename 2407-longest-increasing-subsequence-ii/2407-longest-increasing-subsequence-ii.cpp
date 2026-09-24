class segment{
    public:
    int size=1;
    vector<int> tree;
    segment(int n){
        while(size<n){
            size*=2;
        }
        tree.resize(2*size,0);
    }
    void update(int index,int value,int node,int start,int end){
        if(start==end){
            tree[node]=max(tree[node],value);
            return;
        }
        int mid=start+(end-start)/2;
        if(index<=mid){
            update(index,value,node*2+1,start,mid);
        }
        else{
            update(index,value,node*2+2,mid+1,end);
        }
        tree[node]=max(tree[node*2+1],tree[node*2+2]);
        return ;
    }

    int returnmax(int l,int r,int node,int start,int end){
        if(l>end || r<start){
            return 0;
        }
        if(l<=start && r>=end){
            return tree[node];
        }
        int mid=start+(end-start)/2;

        int left=returnmax(l,r,node*2+1,start,mid);
        int right=returnmax(l,r,node*2+2,mid+1,end);
        return max(left,right);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=*max_element(nums.begin(),nums.end());
        int size1=nums.size();
        segment st(n+1);
        int result=0;
        for(int i=0;i<size1;i++){
            //now range we would be looking would be numa[i]-k to nums[i]-1;
            int maximum=1+st.returnmax(nums[i]-k,nums[i]-1,0,1,n);
            result=max(result,maximum);
            st.update(nums[i],maximum,0,1,n);
        }
        return result;
    }
};