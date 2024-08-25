
// https://www.youtube.com/watch?v=3XHAikDnB2w

// notebook

class Solution {
    
    int convertStringToBits(string str){
        int n = str.size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            int x = ch - 'a';
            
            ans |= (1 << x);
        }
        
        return ans;
    }
    
public:
    int maxProduct(vector<string>& nums) {
        int n = nums.size();
        
        vector<int> correspondingBits(n);
        for(int i=0; i<n; i++){
            string word = nums[i];
            correspondingBits[i] = convertStringToBits(word);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            string x = nums[i];
            for(int j=i+1; j<n; j++){
                string y = nums[j];
                
                int a = correspondingBits[i];
                int b = correspondingBits[j];
                
                if((a & b) == 0){
                    int val = x.size() * y.size(); // ye int mei store ho jayega
                    ans = max(ans, val);
                }
            }
        }
        
        return ans;
    }
};