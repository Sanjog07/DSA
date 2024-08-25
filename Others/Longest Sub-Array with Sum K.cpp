

// ye wala solu shi hai, and jo coding blocks mei krwaya hua hai
// vo incomplete hai -> usse kuch test cases nhi cover ho rhe
// ye wala ques GFG pe hai

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k){
        unordered_map<int,int> m;
        
        int pre = 0; /// prefix sum
        int len = 0;
        for(int i=0; i<n; i++){
            pre += arr[i];
            if(pre == k){
                len = max(len, i+1);
            }
            if(m.find(pre-k) != m.end()){
                len = max(len, i - m[pre-k]);
            }
            // else{
            //     m[pre] = i;
            // }
            
            // i.e pre ki first occurence ko map mei store krna hai
            // so hum ye pre wali value map mei tabhi daalenge jb
            // wohi pre wali value map mei pehle se na ho
            if(m.find(pre) == m.end()){

                // i.e hume ye tab bhi krna hai jb upar 2 condi mei se
                // koi shi bhi ho
                // but coding blocks wale mei humne is wali condi
                // ko else mei likh diya tha
                m[pre] = i;
            }
        }
        
        return len;
    }

};