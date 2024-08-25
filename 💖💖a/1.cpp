/*
    Time Complexity : O(N ^ 4)
    Space Complexity : O(N ^ 2)

    where N is the number of rows and columns in 'grid'.
*/

#include <queue>

// Check if the last cell is reachable in given time using BFS traversal.
bool bfs(int time, vector<vector<int>>& grid, int n) {
    // If the starting cell is locked. 
    if (grid[0][0] > time) return false;  
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    queue<pair<int, int>> bfsQ;
    seen[0][0] = true;
    bfsQ.emplace(0, 0);
    // Add 'dir[i]' to move to an adjacent cell.
    static int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  

    while (!bfsQ.empty()) {
        int x = bfsQ.front().first, y = bfsQ.front().second;
        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && !seen[newX][newY] && grid[newX][newY] <= time) {
                 // We have reached the last cell.
                if (newX == n - 1 && newY == n - 1) return true; 
                seen[newX][newY] = true;
                bfsQ.emplace(newX, newY);
            }
        }
    }
    return false;
}

int lastCellLeastTime(vector<vector<int>>& grid, int n) {
    int time = 0;

    while (!bfs(time, grid, n)) {
        // Increase time until the last node is not reachable.
        time++;  
    }

    return time;
}









/*
    Time Complexity : O((N ^ 2) * log(N))
    Space Complexity : O(N ^ 2)

    where N is the number of rows and columns in 'grid'.
*/

#include <queue>

// Check if the last cell is reachable in the given time, using BFS traversal.
bool reachable(int time, vector<vector<int>>& grid, int n) {
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    queue<pair<int, int>> bfsQ;
    seen[0][0] = true;
    bfsQ.emplace(0, 0);
    // Add 'dir[i]' to move to an adjacent cell.
    static int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  

    while (!bfsQ.empty()) {
        int x = bfsQ.front().first, y = bfsQ.front().second;
        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && !seen[newX][newY] && grid[newX][newY] <= time) {
                // We have reached the last cell.
                if (newX == n - 1 && newY == n - 1) return true;  
                seen[newX][newY] = true;
                bfsQ.emplace(newX, newY);
            }
        }
    }
    return false;
}

int lastCellLeastTime(vector<vector<int>>& grid, int n) {
    int low = grid[0][0], high = n * n - 1, mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (reachable(mid, grid, n)) {
            // Store current time as answer and search if a lower time value is possible.
            high = mid;  
        } else {
            // Search for a larger time value.
            low = mid + 1;  
        }
    }

    return low;
}