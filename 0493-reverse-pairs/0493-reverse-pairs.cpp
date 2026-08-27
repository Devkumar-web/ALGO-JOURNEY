class Solution {
public:
   int count=0;
   void countpairs(vector<int>& nums,int low,int mid,int high){
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && nums[i]>(long long)2*nums[j]){
            j++;
        }
        count=count+(j-(mid+1));
    }
   }
   void merge(vector<int>& nums,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;

    //lets make new two vector and start merging into given right span of array
    vector<int> num1(n1);
    vector<int> num2(n2);
    for(int i=0;i<n1;i++){
        num1[i]=nums[low+i];
    }

    for(int  i=0;i<n2;i++){
        num2[i]=nums[mid+1+i];
    }

    int k=low;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        //when we have element in both array 
        //now this is right time to calculate number of 
        if(num1[i]<=num2[j]){
            nums[k]=num1[i];
            k++;
            i++;
        }
        else{
            nums[k]=num2[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        nums[k]=num1[i];
        i++;
        k++;
    }
     while(j<n2){
        nums[k]=num2[j];
        j++;
        k++;
    }
   }
    void mergersort(vector<int> &nums,int low,int high){
        if(low>=high){
            return ;
        }
        int mid=(low+high)/2;

        mergersort(nums,low,mid);
        mergersort(nums,mid+1,high);
        countpairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        
    }
    int reversePairs(vector<int>& nums) {

        mergersort(nums,0,nums.size()-1);

        return count;
    }
};