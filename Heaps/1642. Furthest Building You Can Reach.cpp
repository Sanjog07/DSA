
// https://www.youtube.com/watch?v=o84_EH4UJXc

class Solution {
public:
    int furthestBuilding(vector<int>& arr, int b, int l) {
        int n = arr.size();
        
        priority_queue<int> pq;
        
        int i = 0;
        for( ; i<n-1; i++){
            int val = arr[i+1] - arr[i];
            if(val > 0){
                if(b >= val){
                    b -= val;
                    pq.push(val);
                }else if(l > 0){
                    if(!pq.empty() && pq.top() > val){
                        b += pq.top();
                        pq.pop();
                        
                        b -= val;
                        pq.push(val);
                    }
                    l--;
                }else{
                    break;
                }
            }
        }
        
        return i;
    }
};