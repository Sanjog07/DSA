
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

class custom{
    public:
    
    int x;
    int y;
    int d;
};


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int shortestPath(vector<vector<int>> &nums){
  int m = nums.size();
  int n = nums[0].size();

  if(m == 1 && n == 1){
    if(nums[0][0] == 1){
      return 0;
    }else if(nums[0][0] == 0){
      return -1;
    }
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(nums[i][j] == 0){
        nums[i][j] = -1;
        for(int k=0; k<4; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];

          if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
            nums[nx][ny] = -1;
          }
        }
      }
    }
  }

  queue<custom> q;  

  for(int i=0; i<m; i++){
    if(nums[i][0] == 1){
      q.push({i, 0, 0});
      nums[i][0] = -1;
      break;
    }
  }

  if(q.empty()){
    return -1; // i.e 1st col mei koi safe pos hi nhi hai
  }

  while(!q.empty()){
    auto f = q.front();
    q.pop();

    int dist = f.d;

    if(f.y == n-1){
      return dist;
    }

    for(int i=0; i<4; i++){
        int nx = f.x + dx[i];
        int ny = f.y + dy[i];

        // if(ny == n-1){
        //   return dist + 1;
        // }
        
        if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
            q.push({nx, ny, dist + 1});
            nums[nx][ny] = -1;
        }
    }    
  }

  return -1;
}