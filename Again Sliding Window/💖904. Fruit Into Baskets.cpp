


// Agr Interview ke hisaab se dekhna hai to kisi aur ka clean code dekh lena

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(n, 0); // as there can be n diff types of fruits
        
        int i=0, j=0;
        int cnt = 0, ans = 0;
        
        while(j < n){
            if(freq[nums[j]] == 0){
                cnt++;
                if(cnt > 2){
                    ans = max(ans, (j-i));
                    while(true){
                        freq[nums[i]]--;
                        if(freq[nums[i]] == 0){
                            i++;
                            cnt--; // i wale ka cnt km krdo
                            freq[nums[j]]++; // as hum nye wale no pe khade hai // and loop ke baad j++ ho rha hai
                            break;
                        }
                        i++;
                    }
                }else{
                    freq[nums[j]]++;
                }
            }else{
                freq[nums[j]]++;
            }
            
            j++;
        }
        
        ans = max(ans, (j-i));
        
        return ans;
    }
};