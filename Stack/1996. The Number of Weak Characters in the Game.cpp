

// Hint dekh ke idea mila tha

// cmp mei vector ko as reference pass kr lena otherwise 
// kuch cases ke liye TLE de rha hai
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[0] == v2[0]){
        return v1[1] > v2[1];
    }
    
    return v1[0] < v2[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), cmp);
        
        int cnt = 0;
        int mx = INT_MIN;
        
        for(int i=n-1; i>=0; i--){
            vector<int> v = arr[i];
            if(v[1] < mx){
                cnt++;
            }else{
                mx = v[1];
            }
        }
        
        return cnt;
    }
};