class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3){
            return false;
        }
        
        // so 132 pattern mei hume 3 ko fix rkhenge 
        // and hum iske left mei chhota element find krenge (mine iske liye hi bnayi hai)
        // and right mei max element find krenge (jiske liye stack bnayi hai)
        
        vector<int> mine(n,0); // an array of min element till now
        mine[0] = nums[0];
        
        for(int i=1; i<n; i++){
            mine[i] = min(nums[i], mine[i-1]);
        }
        
        stack<int> s;
        s.push(nums[n-1]);
        
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && s.top() < nums[i]){
                
           // iss wale loop ko thoda acche se smajh lena reason hai ki s.top() < nums[i] kyu likha rather than ki jo top pe nums[i] se bde elements hai unko pop krdo -> agr unko pop kr diya to kisi chhote i ke liye vo ans ho skta tha      
                
                if(s.top() > mine[i]){
                    return true;
                }
                
                s.pop();     
                // and otherwise isko pop krdo, thoda dry run isko smajhne ke liye bhi kr lena, bcz agr ye element current ke liye kaam nhi aaya to ye piche wale kisi ke liye kaam nhi aayega, bcz piche walo ka mine[i], current wale ke mine[i] se bda ya equal hi hoga chhota nhi hoga
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
    
};