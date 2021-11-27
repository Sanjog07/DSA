class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        
        //SOLUTION LINK: https://leetcode.com/problems/find-a-peak-element-ii/discuss/1566025/C%2B%2B-O(n-log-m)-binary-search-solution-%2B-explanation
        
        int m = mat.size();
        int n = mat[0].size();
        
        // so we'll apply binary search on row
        // and will iterate over column linearly
        
        int s = 0;
        int e = m-1;
        
        
        while(s <= e){
            int mid = (s+e) >> 1;
            
            int solu = INT_MIN;
            int pt = -1;
            for(int j=0; j<n; j++){
                if(mat[mid][j] > solu){
                    solu = mat[mid][j];
                    pt = j;
                }
            }
            
            // as all the elements of matrix are +ve
            // ui -> mat[pt] ke top wala element
            // li -> mat[pt] ke down wala element
            
            int ui = (mid == 0) ? -1 : mat[mid-1][pt];
            int li = (mid == m-1) ? -1 : mat[mid+1][pt];
            
            if(mat[mid][pt] > ui && mat[mid][pt] > li){
                ans.push_back(mid);
                ans.push_back(pt);
                return ans;
            }
            else if(mat[mid][pt] > ui){
                // to lower side mei search kro
                s = mid+1;
            }
            else if(mat[mid][pt] > li){
                // otherwise upper side mei search kro
                e = mid-1;
            }
        }
        
        return {};
    }
};