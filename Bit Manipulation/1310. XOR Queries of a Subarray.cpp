
// notebook

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> prexor(n);
        
        prexor[0] = arr[0];
        for(int i=1; i<n; i++){
            prexor[i] = prexor[i-1] ^ arr[i];
        }
        
        vector<int> ans;
        
        for(auto que: queries){
            int l = que[0];
            int r = que[1];
            
            if(l == 0){
                ans.push_back(prexor[r]);
            }else if(l == r){
                ans.push_back(arr[l]);
            }else{
                int val = prexor[r] ^ prexor[l-1];
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};