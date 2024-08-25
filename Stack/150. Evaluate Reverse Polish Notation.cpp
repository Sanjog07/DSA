class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        stack<int> s;
        for(int i=0; i<n; i++){
            string str = tokens[i];
            
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                
                if(str == "+"){
                    s.push(a+b);

                }else if(str == "-"){
                    s.push(a-b);   

                }else if(str == "*"){
                    s.push(a*b); 

                }else if(str == "/"){
                    s.push(a/b);  

                }
            }else{
                s.push(stoi(str));
            }
        }
        
        return s.top();
    }
};


// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         int n = tokens.size();
        
//         stack<int> s;
//         for(int i=0; i<n; i++){
//             string str = tokens[i];
//             if(str == "+"){
//                 int b = s.top();
//                 s.pop();
//                 int a = s.top();
//                 s.pop();
//                 s.push(a+b);
                
//             }else if(str == "-"){
//                 int b = s.top();
//                 s.pop();
//                 int a = s.top();
//                 s.pop();
//                 s.push(a-b);   
                
//             }else if(str == "*"){
//                 int b = s.top();
//                 s.pop();
//                 int a = s.top();
//                 s.pop();
//                 s.push(a*b); 
                
//             }else if(str == "/"){
//                 int b = s.top();
//                 s.pop();
//                 int a = s.top();
//                 s.pop();
//                 s.push(a/b);  
                
//             }else{
//                 s.push(stoi(str));
//             }
//         }
        
//         return s.top();
//     }
// };