class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end()); 
        //so basically hum original array ko sort ki taraf nhi le jayege
        // blki ulta krenge ki sorted array ko original array mei convert
        // krne ke liye kitne swaps lgenge
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i != v[i].second){
                swap(v[i], v[v[i].second]);
                cnt++;
                i--;
            }
        }
        
        return cnt;
	}
};