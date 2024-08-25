bool isSafe(int x,int y, int m,int n){
    if(x >= 0 && x < m && y >= 0 && y < n){
        return true;
    }
    return false;
}

void solve(int i, int j,vector<vector<int> > & mat, int m, int n, vector<int> &v, vector<vector<int>> &ans){
    if(i == m-1 && j == n-1){
        v.push_back(mat[i][j]);
        ans.push_back(v);
        v.pop_back();
        return;
    }

    int ni = i;
    int nj = j+1;
    if(isSafe(ni, nj, m, n)){
        v.push_back(mat[i][j]);
        solve(ni, nj, mat, m, n, v, ans);
        v.pop_back();
    }

    ni = i+1;
    nj = j;
    if(isSafe(ni, nj, m, n)){
        v.push_back(mat[i][j]);
        solve(ni, nj, mat, m, n, v, ans);
        v.pop_back();
    }

    return;

}

vector<vector<int> > printAllpaths(vector<vector<int> > & mat , int m , int n){
    vector<vector<int> > ans;
    vector<int> v;

    solve(0, 0, mat, m, n, v, ans);

    return ans;
}