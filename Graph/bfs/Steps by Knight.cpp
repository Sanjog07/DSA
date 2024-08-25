


class Solution 
{
	
	bool isValid(int sr,int sc,int n){
        if(sr < 1 || sc < 1 || sr > n || sc > n){
            return false;
        }
        return true;
    }
	
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int> &knightPos,vector<int>&targetPos,int n){
	    int sx = knightPos[0];
	    int sy = knightPos[1];
	    int tx = targetPos[0];
	    int ty = targetPos[1];
	    
	    if(sx == tx && sy == ty){
	        return 0;
	    }
	    
	    int dx[] = {2,-2,1,-1,2,-2,1,-1};
	    int dy[] = {1,-1,2,2,-1,1,-2,-2}; 
	    
	    int dist[n+1][n+1];
	    //memset(dist , INT_MAX , sizeof(dist));
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++){
	            dist[i][j] = INT_MAX;
	        }
	    }
	    
	    queue<pair<int,int> > q;
	    q.push(make_pair(sx,sy));
	    dist[sx][sy] = 0;
	    
	    while(!q.empty()){
	        int cx = q.front().first;
	        int cy = q.front().second;
	        q.pop();
	        
	        for(int i=0; i<8; i++){
	            if(isValid(cx+dx[i],cy+dy[i],n)){
	                if(dist[cx+dx[i]][cy+dy[i]] == INT_MAX){
    	                dist[cx+dx[i]][cy+dy[i]] = dist[cx][cy] + 1;
    	                if(cx+dx[i] == tx && cy+dy[i] == ty){
    	                    return dist[tx][ty];
    	                }    	                
    	                q.push(make_pair(cx+dx[i] , cy+dy[i]));
	                }
	            }
	        }
	    }
	    return dist[tx][ty];
	}
};