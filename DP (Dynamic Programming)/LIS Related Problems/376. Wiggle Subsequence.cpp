class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return 1;
        }
        if(n == 2 && nums[0] != nums[1]){
            return 2;
        }
        
        // Exactly same as Longest Alternating Subseq (LAS)
        // agr ques ko dhyaan se dekhe to LAS ko ghuma ke pucha
        // hua hai -> i.e jb elements alternating honge
        // tb automatically unka diff +ve and -ve mei
        // rotate krega
        
        int ma = 1;
        int mi = 1;
        for(int i=1; i<n; i++){
            int diff = nums[i] - nums[i-1];
            if(diff > 0){
                ma = mi + 1;
            }else if(diff < 0){
                mi = ma + 1;
            } 
            
            // when diff is 0 tb kuch nhi krna
        }
        
        return max(ma, mi);
    }
};