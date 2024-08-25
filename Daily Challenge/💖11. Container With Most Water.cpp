

//https://www.youtube.com/watch?v=ZHQg07n_tbg

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = n-1;
        
        int ans = INT_MIN;
        while(i < j){
            int h = min(nums[i], nums[j]);
            ans = max(ans, h * (j-i));
            
            // ye neeche wale steps isliye kiye bcz agr bde pillar 
            // ko avoid krte to kabhi usse jyada ans nhi mil payega
            // tabhi humne chhote pillar ko avoid kiya
            if(nums[i] < nums[j]){
                i++;
            }else{
                j--;
            }
        }
        
        return ans;
        
    }
};