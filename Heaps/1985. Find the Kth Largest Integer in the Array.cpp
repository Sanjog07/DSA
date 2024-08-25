
class cmp{
public:
    bool operator()(string s1, string s2){
        if(s1.length() == s2.length()){
            return s1 > s2;
        }

        return s1.length() > s2.length();
    }    
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        
        priority_queue<string, vector<string>, cmp> pq;
        
        for(int i=0; i<n; i++){
            string str = nums[i];
            
            pq.push(str);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};