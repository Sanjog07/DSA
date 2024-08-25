


  // jb loop seedha chalayege tb ye leke chalenge ki is wale element 
  // ka ans kya ho skta hai vo find krenge
  // jb loop ulta chalayege 
  // tb ye leke chalenge ki ye wala element pichle kis kis element
  // ka ans ho skta hai
  

vector<int> ngr(vector<int> arr){
  int n = arr.size();

  stack<int> s;
  s.push(n-1);

  vector<int> ans;
  ans.push_back(-1);
  for(int i=n-2; i>=0; i--){
    while(!s.empty() && arr[s.top()] <= arr[i]){
      s.pop();
    }
    if(s.empty()){
      ans.push_back(-1);
    }else{
      ans.push_back(arr[s.top()]);
    }

    s.push(i);
  }

  reverse(ans.begin(), ans.end());

  return ans;
}


vector<int> ngr(vector<int> arr){
  int n = arr.size();

  stack<int> s;
  s.push(0);

  vector<int> ans(n);
  for(int i=1; i<n; i++){
    while(!s.empty() && arr[s.top()] < arr[i]){
      ans[s.top()] = arr[i];
      s.pop();
    }

    s.push(i);
  }

  // jo elements last mei stack mei rh gye -> it means vo pop nhi hue 
  // which means there is no ngr for them
  while(!s.empty()){
    ans[s.top()] = -1;
    s.pop();
  }

  return ans;
}