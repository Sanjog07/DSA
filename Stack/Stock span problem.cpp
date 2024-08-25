class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int arr[], int n){

        // 
        reverse(arr, arr+n);
        
        stack<int> s;
        s.push(0);

        vector<int> ans(n);
        for(int i=1; i<n; i++){
          while(!s.empty() && arr[s.top()] < arr[i]){
            ans[s.top()] = i;
            s.pop();
          }

          s.push(i);
        }

        // jo elements last mei stack mei rh gye -> it means vo pop nhi hue 
        // which means there is no ngr for them
        while(!s.empty()){
          ans[s.top()] = n;
          s.pop();
        }    
        
        vector<int> solu;
     
        for(int i=0; i<n; i++){
            solu.push_back(ans[i] - i);
        }
        
        reverse(solu.begin(), solu.end());
        return solu;
    }
};

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n){
        
        
        // we'll use NGL
        
        vector<int> ans;
        stack<int> s;
        s.push(0);
        ans.push_back(-1);
        
        for(int i=1; i<n; i++){
            while(!s.empty() && price[s.top()] <= price[i]){
                s.pop();
            }
            if(!s.empty()){
                ans.push_back(s.top());
            }else{
                ans.push_back(-1);
            }
            
            s.push(i);
        }
        
        // for(int i=0; i<n; i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        
        vector<int> solu;
     
        for(int i=0; i<n; i++){
            solu.push_back(i - ans[i]);
        }        
        
        return solu;
    }
};