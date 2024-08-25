
// neeche wale code mei thodi si optimization
// O(n^3) se O(n^2)
// jo subarray bnane ke liye k wala loop chalaya thha
// uski koi zarurat hi nhi thhi

class Solution {
public:
    int countDistinct(vector<int>& nums, int x, int p) {
        int n = nums.size();
            
        int ans = 0;
        unordered_set<string> s;
        for(int i=0; i<n; i++){
            int cnt = 0;
            string str = "";            
            for(int j=i; j<n; j++){
                str += (nums[j] - '0');
                if(nums[j]%p == 0){
                    cnt++;
                }
                //cout<<str<<endl;
                if(cnt <= x){
                    s.insert(str);
                }
            }
        }
        
        return s.size();
    }
};


// class Solution {
// public:
//     int countDistinct(vector<int>& nums, int x, int p) {
//         int n = nums.size();
            
//         int ans = 0;
//         unordered_set<string> s;
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 int cnt = 0;
//                 string str = "";
//                 for(int k=i; k<=j; k++){
//                     str += (nums[k] - '0');
//                     if(nums[k]%p == 0){
//                         cnt++;
//                     }
//                 }
//                 //cout<<str<<endl;
//                 if(cnt <= x){
//                     s.insert(str);
//                 }
//             }
//         }
        
//         return s.size();
//     }
// };

