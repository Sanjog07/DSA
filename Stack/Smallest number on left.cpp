class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        reverse(arr, arr+n);
        
        stack<int> s;
        s.push(n-1);

        vector<int> ans;
        ans.push_back(-1);
        for(int i=n-2; i>=0; i--){
          while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
          }
          if(s.empty()){
            ans.push_back(-1);
          }else{
            ans.push_back(arr[s.top()]);
          }

          s.push(i);
        }


        return ans;    
    }
};