

// ye wala pichle walo se thoda different hai as ismei koi
// sum wali cheez nhi nikalni, so ismei jaise pichle walo mei rectangle pe
// iterate krte thhe -> vaise iterate nhi kr skte


// iss ques mei thoda sa change krenge -> to ye bilkul
//  largest rectangulat submatrix with sum == 0 bn jayega
// jo change krna pdega will be -> sabhi 0's ko -1 se replace kr do
// 1D wala bhi aise hi solve krte hai



int maxLen(vector<int> a){
    unordered_map<int,int> m;
    int n = a.size();
    int pre = 0;
    int len = 0;
    
    for(int i=0; i<n; i++){
        pre += a[i];
        if(pre == 0){
            len = max(len , i+1);
        }else if(m.find(pre) != m.end()){
            len = max(len , i - m[pre]);
        }else{
            m[pre] = i;
        }
    }
    return len;
}

int largestSubmatrixWithSumZero(vector<vector<int>> &mat, int r, int c){
    int ans = 0;
    for(int start=0; start<r; start++){
        
        vector<int> v(c, 0);
        for(int i=start; i<r; i++){
            for(int j=0; j<c; j++){
                v[j] += mat[i][j];
            }
            
            int row = (i - start + 1); // ye no of rows btayegi
            int col = maxLen(v); // and ye no of columns btayegi
            ans = max(ans, row*col); // ye cheez area nikaalegi
        }
    }
    return ans;
}

int maximumArea(vector<vector<int>>& mat, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                mat[i][j] = -1;
            }
        }
    }

    return largestSubmatrixWithSumZero(mat,n,m);
}

