class own{
public:
    int val;
    int arridx;
    int idx;
};

class cmp{
public:
    bool operator()(own a, own b){
        return a.val > b.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k){
        priority_queue<own, vector<own>, cmp> pq;
        int n = k;
        
        for(int i=0; i<n; i++){
             pq.push({arr[i][0], i, 0});
            // own tri;
            // tri.val = arr[i][0];
            // tri.arridx = i;
            // tri.idx = 0;
            
            // pq.push(tri);
        }
        
        
        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            ans.push_back(it.val);
            
            int index = it.idx;
            int array = it.arridx;
            
            if((index+1) < k){
                 pq.push({arr[array][index+1], array, index+1});
                // own tri;
                // tri.val = arr[array][index+1];
                // tri.arridx = array;
                // tri.idx = index+1;
                
                // pq.push(tri);                
            }
        }
        
        return ans;
    }
};