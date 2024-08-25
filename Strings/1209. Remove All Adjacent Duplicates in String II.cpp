
// see notebook

class Solution {
public:
    string removeDuplicates(string str, int k) {
        int n = str.size();
        
        // and k ki value 2 se start hai
        
        stack<pair<char,int>> s;
        s.push({str[0], 1});
        
        for(int i=1; i<n; i++){
            char ch = str[i];
            
            // ye condi ko acche se dhyaan rkhna 
            // stack beech mei khi bhi empty ho skti hai
            // see -> s = "deeedbbcccbdaa", k = 3
            if(s.empty()){
                s.push({ch, 1});
                continue;
            }
            
            char f = s.top().first;
            
            if(ch == f){
                s.top().second++;
                if(s.top().second == k){
                    s.pop();
                }
            }else{
                s.push({ch, 1});
            }
        }
        
        string ans = "";
        while(!s.empty()){
            int freq = s.top().second;
            char ch = s.top().first;
            s.pop();
            
            for(int i=0; i<freq; i++){
                ans += ch;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};





// // I TRIED BUT DIDN'T WORK

// // // EG -> "dtpdtaaaaaaaaappppppppppppppppppppaaaaaaaaaaxxxxxxxxxxxxxxsssssssssjjjjjjjjjjjjjjjjjjjjxxxxxxxxxxxxxxxxxxxxsssssssjjjjjjjjjjjjjjjjjjjjssssxxxxxxatdwvvpctpggggggggggggggggggggajagglaaaaaaaaaaaaaaaaaaaa"
// // 20

// // "ppppaaapppppppaaaappp"  & 7

// class Solution {
// public:
//     string removeDuplicates(string str, int k) {
//         int n = str.size();
//         if(n == 1){
//             return str;
//         }
        
//         stack<char> s;
//         s.push(str[0]);
            
//         vector<int> freq(123, 0);
        
//         for(int i=1; i<n; i++){
//             char ch = str[i];
//             if(s.empty()){
//                 s.push(ch);
//                 continue;
//             }
//             if(ch != s.top()){
//                 s.push(ch);
//             }else{
//                 freq[int(ch)]++;
//                 if(freq[int(ch)] == k-1){
//                     freq[int(ch)] = 0;
//                     int cnt = k-1;
//                     while(cnt--){
//                         s.pop();
//                     }
//                 }else{
//                     s.push(ch);
//                 }
//             }
//         }
        
//         string ans = "";
//         while(!s.empty()){
//             ans += s.top();
//             s.pop();
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };
