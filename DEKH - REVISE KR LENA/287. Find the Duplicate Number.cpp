
// notebook 
// thoda sa same concept as 41. First Missing +ve

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m = nums.size();
        int n = m-1;
        
        // repeated number 2 se jyada baar bhi repeat ho skta hai
        
        for(int i=0; i<m; i++){
            if(nums[abs(nums[i])] > 0){
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }else{
                return abs(nums[i]);
            }
        }
        
        return -1; // ye condi kabhi aayegi hi nhi -> as repeated ele hmesha hoga
    }
};




// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int m = nums.size();
//         int n = m-1;
        
//         // as the array contains only 1 repeated no
//         // it means , if we treat array as a linked list 
//         // then it'll definitely contain a cycle
        
//         int slow = -1;
//         int fast = -2;
//         while(slow != fast){
//             if(slow == -1 && fast == -2){
//                 slow = nums[0];
//                 fast = nums[0];                
//             }
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }
        
//         fast = nums[0];
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[fast];
//         }
        
//         return slow;
//     }
// };