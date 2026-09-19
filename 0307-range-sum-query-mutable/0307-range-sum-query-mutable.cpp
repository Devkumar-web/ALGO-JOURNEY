class NumArray {
    private:
     void build(vector<int>& nums,vector<int> &tree,int node,int start,int end){
        if(start>end){
            return ;
        }
        if(start==end){
            tree[node]=nums[start];
            return ;
        }
        int mid=start+(end-start)/2;

        build(nums,tree,node*2+1,start,mid);
        build(nums,tree,node*2+2,mid+1,end);

        tree[node]=tree[node*2+1]+tree[node*2+2];

        return ;

     }
     void set(vector<int> &tree,int node,int index,int value,int start,int end){
        if(start==end){
            tree[node]=value;
            return ;
        }
        int mid=start+(end-start)/2;
        if(index<=mid){
            set(tree,node*2+1,index,value,start,mid);
        }
        else{
            set(tree,node*2+2,index,value,mid+1,end);
        }

        tree[node]=tree[node*2+1]+tree[node*2+2];

        return ;
     }
     int sumrange(vector<int> &tree,int node,int left,int right,int start,int end){
        if(left>end || right<start){
            return 0;
        }
        if(left<=start && right>=end){
            return tree[node];
        }
        int mid=start+(end-start)/2;

        int leftsum=sumrange(tree,node*2+1,left,right,start,mid);
        int rightsum=sumrange(tree,node*2+2,left,right,mid+1,end);

        return leftsum+rightsum;
     }
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        //here segment tree come in play
         n=nums.size();
        int size=1;
        while(size<n){
            size*=2;
        }
        //now form a tree
        tree.resize(2*size,0);
        build(nums,tree,0,0,n-1);
        //now we have build our tree

    }
    
    void update(int index, int val) {
        set(tree,0,index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return sumrange(tree,0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */