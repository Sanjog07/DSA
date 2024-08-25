class Solution {
public:
    char nextGreatestLetter(vector<char>& nums, char tar) {
        int n = nums.size();
        
        // ye condi extra aayegi bss as the letters wrap around.
        if(nums[n-1] <= tar){
            return nums[0];
        }
        
        int s=0, e=n-1;
        char ans = ' ';
        while(s <= e){
            int mid = e - (e-s)/2;
            char ch = nums[mid];
            
            if(ch <= tar){
                s = mid+1;
            }else{
                ans = ch;
                e = mid-1;
            }
        }
        
        return ans;
    }
};




// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         int n = letters.size();
        
//         int s = 0;
//         int e = n-1;
//         char ans = ' ';
        
//         while(s <= e){
//             int mid = (s+e) >> 1;
            
//             if(int(letters[mid]) > int(target)){
//                 ans = letters[mid];
//                 e = mid - 1;
//             }else{
//                 s = mid+1;
//             }
//         }
        
//         return ans;
//     }
// };