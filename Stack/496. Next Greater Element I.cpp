class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // 1st Method -> peeche se loop chalayege
        
//         vector<int> ans;
//         ans.push_back(-1);
        
//         int n = nums2.size();
//         stack<int> s;
//         s.push(nums2[n-1]);
        
//         for(int i=n-2; i>=0; i--){
//             while(!s.empty() && nums2[i] > s.top()){
//                 s.pop();
//             }
            
//             if(s.empty()){
//                 ans.push_back(-1);
//             }else{
//                 ans.push_back(s.top());
//             }
            
//             s.push(nums2[i]);
//         }
        
//         reverse(ans.begin() , ans.end());
        
//         vector<int> solu;
//         unordered_map<int,int> m;
//         for(int i=0; i<n; i++){
//             m[nums2[i]] = i;
//         }
        
//         for(int j=0; j<nums1.size(); j++){
//             int x = m[nums1[j]];
//             solu.push_back(ans[x]);
//         }
        
//         return solu;
        
        
        
        // 2nd Method : start se loop chalayege   
        stack<int> s;
        
        //index push kr rhe hai
        s.push(0);    
        
        int n = nums2.size();
        
        vector<int> ans(n); // vector ka size define krdo, uska size define na krne pr runtime error dikha rha hai.
        // maybe bcz humne khi pe ans.push_back() use nhi kiya
        
        for(int i=1; i<n; i++){
            while(!s.empty() && nums2[i] >= nums2[s.top()]){
                ans[s.top()] = nums2[i];
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty()){
            //i.e jo elements phle pop nhi hue bcz unka koi ngr hi nhi tha
            ans[s.top()] = -1;
            s.pop();
        }
        
        vector<int> solu;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[nums2[i]] = i;
        }
        
        for(int j=0; j<nums1.size(); j++){
            int x = m[nums1[j]];
            solu.push_back(ans[x]);
        }
        
        return solu;
    }
};