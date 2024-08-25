class Solution{   
    
    int noOfSmallerAndEqualElements(vector<vector<int>> &mat, int r, int c,int mid){
        // we'll find no of elements whose value is less and equal than mid
        int ans = 0;
        for(int i=0; i<r; i++){
            ans += (upper_bound(mat[i].begin() , mat[i].end() , mid) - mat[i].begin());
        } 
        return ans;
    }
    
public:
    int median(vector<vector<int>> &mat, int r, int c){
        int ma = INT_MIN , mi = INT_MAX;
        for(int i=0; i<r; i++){
            mi = min(mi,mat[i][0]); // min element will be in 1st column
        }
        for(int i=0; i<r; i++){
            ma = max(ma,mat[i][c-1]); // max element will be in last column
        }        
        
        int low = mi;
        int high = ma;
        
        int ans = -1;
        int x = (r*c)/2;
        while(low <= high){
            int mid = (low+high) >> 1;
            int sma_ele = noOfSmallerAndEqualElements(mat,r,c,mid);
            if(sma_ele <= x){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int findMedian(vector<vector<int>> &A)
{
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cnt += countSmallerThanMid(A[i], mid);
    }
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int main()
{
  int row = 3, col = 3;
  vector<vector<int>> arr = {{1, 3, 8},
                             {2, 3, 4},
                             {1, 2, 5}};
  cout <<"The median of the row-wise sorted matrix is: "<<findMedian(arr)<<endl;
  return 0;
}
