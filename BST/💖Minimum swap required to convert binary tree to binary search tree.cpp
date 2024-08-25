

The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value. 
So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer. Please refer below post to find minimum number of swaps required to get the array sorted.
Minimum number of swaps required to sort an array

// Exactly same as Min Swaps required to sort the array

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