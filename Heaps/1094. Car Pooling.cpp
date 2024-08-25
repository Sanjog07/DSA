
typedef pair<int,int> pii;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& arr, int cap) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), cmp);
        
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        
        
        // see this case
        // [[9,0,1],[3,3,7]] , capacity = 4
        // is wale case mei hum first wale ko hi pick nhi kr skte
        
        if(cap >= arr[0][0]){
            cap -= arr[0][0];
        }else{
            return false;
        }
        pq.push({arr[0][2], arr[0][0]});
        
        for(int i=1; i<n; i++){
            int val = arr[i][0];
            
            while(!pq.empty() && (pq.top().first) <= arr[i][1]){
                cap += pq.top().second;
                pq.pop();
            }
            
            if(cap >= val){
                cap -= val;
                pq.push({arr[i][2], arr[i][0]});
            }else{
                return false;
            }
        }
        
        return true;
    }
};