
//https://www.youtube.com/watch?v=yL8a7nnb8xw

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        // hum ismei 3 and 2 ko kind of fix rkhenge 
        // and 1 ko loop lgake find krenge
        
        stack<int> s;
        s.push(nums[n-1]);
        int third_ele = INT_MIN;
        
        for(int i=n-2; i>=0; i--){
            int ele = nums[i];
            if(ele < third_ele){
                return true;
            }
            
            // [1,3,2,4,5,6,7,8,9,10]
            // [3,5,0,3,4]
            // see these eg's for why we've to apply while loop 
            // here instead of just a if condi.
            
            // if(ele > s.top()){
            //     third_ele = s.top();
            //     s.pop();
            //     //s.push(ele);
            // }
            
            while(!s.empty() && ele > s.top()){
                
                // also we're applying this while loop
                // bcz hume third_ele ki value jitni max ho ske
                // utni max chahiye -> bcz first wali value 
                // usse chhoti honi chahiye
                // so ye jitni bdi hogi utna accha hoga
                third_ele = s.top();
                s.pop();                
            }
            
            s.push(ele);
        }
        
        return false;
    }
};






















// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
        
//         if(n < 3){
//             return false;
//         }
        
//         // so 132 pattern mei hume 3 ko fix rkhenge 
//         // and hum iske left mei chhota element find krenge (mine iske liye hi bnayi hai)
//         // and right mei max element find krenge (jiske liye stack bnayi hai)
        
//         vector<int> mine(n,0); // an array of min element till now
//         mine[0] = nums[0];
        
//         for(int i=1; i<n; i++){
//             mine[i] = min(nums[i], mine[i-1]);
//         }
        
//         stack<int> s;
//         s.push(nums[n-1]);
        
//         for(int i=n-2; i>=0; i--){
//             while(!s.empty() && s.top() < nums[i]){
                
//            // iss wale loop ko thoda acche se smajh lena reason hai ki s.top() < nums[i] kyu likha rather than ki jo top pe nums[i] se bde elements hai unko pop krdo -> agr unko pop kr diya to kisi chhote i ke liye vo ans ho skta tha      
                
//                 if(s.top() > mine[i]){
//                     return true;
//                 }
                
//                 s.pop();     
//                 // and otherwise isko pop krdo, thoda dry run isko smajhne ke liye bhi kr lena, bcz agr ye element current ke liye kaam nhi aaya to ye piche wale kisi ke liye kaam nhi aayega, bcz piche walo ka mine[i], current wale ke mine[i] se bda ya equal hi hoga chhota nhi hoga
//             }
            
//             s.push(nums[i]);
//         }
        
//         return false;
//     }
    
// };