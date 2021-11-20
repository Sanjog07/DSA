class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        // when array is empty
        if(n == 0){
            return 0;
        }
        
        int i=0, j=1;
        while(j < n){
            if(nums[i] == nums[j]){
                j++;
            }else{
                swap(nums[i+1], nums[j]);
                i++;
                j++;
            }
        }
        
        // for(int k=0; k<n; k++){
        //     cout<<nums[k]<<" ";
        // }
        // cout<<endl;
        // cout<<i+1<<" ";
        
        return i+1;
    }
};