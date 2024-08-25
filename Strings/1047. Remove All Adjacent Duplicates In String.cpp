
// this won't work 
// see eg -> "azxxzym"
// given test cases ke liye to chal jayega

// class Solution {
// public:
//     string removeDuplicates(string str) {
//         int n = str.length();
//         if(n == 1){
//             return str;
//         }
        
//         int prev = 0, curr = 1;
//         while(prev < n && curr < n){
//             if(prev == curr){
//                 curr++;
//                 prev--;
//                 if(prev < 0){
//                     prev = curr;
//                     curr++;
//                 }
//             }else{
//                 prev++;
//                 curr++;
//             }
//         }
//     }
// };




// O(n^2) - as erase() take O(n)

class Solution {
public:
    string removeDuplicates(string str) {

        int i=1;
        while(i < str.size()){
            if(i != 0 && str[i] == str[i-1]){
                str.erase(i-1, 2);
                i -= 2;
            }
            i++;
        }
        
        return str;
    }
};



class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.length();
        
        stack<char> s;
        s.push(str[0]);
        for(int i=1; i<n; i++){
            char ch = str[i];
            if(!s.empty() && s.top() == ch){
                s.pop();
            }else{
                s.push(ch);
            }
        }
        
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};