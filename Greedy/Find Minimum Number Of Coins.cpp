
int arr[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

int findMinimumCoins(int amt){
    
    int cnt = 0;
    int n = 9;
    while(amt > 0){
        int idx = upper_bound(arr, arr+n, amt) - arr;
        idx -= 1;
        cnt++;
        amt -= arr[idx];
    }
    
    return cnt;
}
