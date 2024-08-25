    bool isSafe(int x, int y, vector<vector<int>> &mat, int n,int m, vector<vector<int>> &vis){
        if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 1 && vis[x][y] == 0) {
            return true;
        }
        return false;
    }

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    void solve(int i, int j,vector<vector<int> > & mat, int n, int m, int &len, int &ans,int di, int dj, vector<vector<int>> &vis){
        if(i == di && j == dj){
            //len++;
            ans = max(ans, len);
            //len--;

            return;
        }

        for(int k=0; k<4; k++){
            int newi = i + dx[k];
            int newj = j + dy[k];

            if(isSafe(newi, newj,mat, n, m, vis)){
                len++;
                vis[i][j] = 1;
                solve(newi, newj,mat, n, m,len, ans, di, dj, vis);
                vis[i][j] = 0;
                len--;
            }
        }

        return;
    }


int longestPath(int n, int m, vector<vector<int>> &mat, int si, int sj, int di, int dj) {

    if(mat[si][sj] == 0 || mat[di][dj] == 0){
        return -1;
    }    
	vector<vector<int>> vis(n, vector<int> (m, 0));

    int len = 0;
    int ans = -1;

    solve(si, sj, mat, n, m, len, ans, di, dj, vis);

    return ans;
}