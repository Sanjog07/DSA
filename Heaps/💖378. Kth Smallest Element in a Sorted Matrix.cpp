
// https://www.youtube.com/watch?v=G5wLN4UweAM&t=52s

class Solution {
    
    // this fnc will count no of values smaller than or equal to
    // mid in the matrix
    
    // this is kind of staircase search wala method
    int count(vector<vector<int>>& mat, int n,int mid){
        int i = n-1;
        int j = 0;
        
        int cnt = 0;
        while(i >= 0 && j < n){
            if(mat[i][j] > mid){
                i--;
            }else{
                cnt += (i+1);
                j++;
            }
        }
        
        return cnt;
    }
    
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // we'll apply Binary Search
        
        int s = mat[0][0];
        int e = mat[n-1][n-1];
        
        int ans;
        while(s <= e){
            int mid = s + (e-s)/2;
            int num = count(mat,n,mid);
            
            if(num < k){
                s = mid  + 1;
            }else{
                ans = mid;
                e = mid - 1;
            }
        }
        
        return ans;
    }
};




// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& arr, int k) {
//         int n = arr.size();
        
//         priority_queue<int> pq;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 pq.push(arr[i][j]);
//                 if(pq.size() > k){
//                     pq.pop();
//                 }
//             }
//         }
        
//         return pq.top();
//     }
// };