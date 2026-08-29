class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return ;
        }

        //lets create
        int mini=min(m,n);
        int first=m-1;
        int second=n-1;
        int final=n+m-1;

        while(first>=0 && second>=0 && final>=0){
            if(nums1[first]>nums2[second]){
                nums1[final]=nums1[first];
                first--;
                final--;
            }
            else{
                nums1[final]=nums2[second];
                second--;
                final--;
            }
        }

        while(second>=0){
            nums1[final]=nums2[second];
            final--;
            second--;
        }


         while(first>=0){
            nums1[final]=nums1[first];
            final--;
            first--;
        }
        

        return;
    }
};