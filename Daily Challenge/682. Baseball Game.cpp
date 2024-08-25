

// https://leetcode.com/problems/baseball-game/discuss/1930719/C%2B%2B-CYCLE-Explained

// hum stack wala kaam ek vector se bhi krwa skte hai

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        
        // we're making a stack as we wanted to keep record of the 
        // previous states
        stack<int> s;
        
        int a = stoi(ops[0]);
        s.push(a);
        for(int i=1; i<n; i++){
            string str = ops[i];
            if(str == "+"){
                int one = s.top();
                s.pop();
                int two = s.top();
                
                int sum  = one + two;
                s.push(one);
                s.push(sum);
            }else if(str == "C"){
                s.pop();
            }else if(str == "D"){
                int x = s.top();
                s.push(2*x);
            }else{
                int val = stoi(str);
                s.push(val);
            }
        }
        
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};