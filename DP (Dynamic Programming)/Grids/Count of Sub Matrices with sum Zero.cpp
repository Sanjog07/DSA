 


 // ques -> https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/


// i.e count of subarrays with sum == 0 (refer pepcoding)
int count(vector<int> arr){
    int n = arr.size();

    unordered_map<int,int> m;
    int cnt = 0;
    int pre = 0;

    m[0] = 1; // this trick will help jb jb pre == 0 aayega -> uska cnt nikalne mei
    for(int i=0; i<n; i++){
      pre += arr[i];

      if(m.find(pre) != m.end()){
        cnt += m[pre]; // purani wali freq add krlo
        m[pre]++; // and ab freq update krdo
      }else{
        m[pre] = 1;
      }
    }

    return cnt;
}

 int countSubmatrixWithSumZero(vector<vector<int>> &mat, int r, int c){
    int ans = 0;
    for(int start=0; start<r; start++){
        
        vector<int> v(c, 0);
        for(int i=start; i<r; i++){
            for(int j=0; j<c; j++){
                v[j] += mat[i][j];
            }
            
            ans += count(v);
        }
    }
    return ans;
} 