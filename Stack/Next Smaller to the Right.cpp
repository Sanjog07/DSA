





// ye bhi bilkul NGR jaisa hai bss ismei while loop wala 
// equality sign change kr denge


 vector<int> nsr(vector<int> arr){
  int n = arr.size();

  // jb loop ulta chalayege 
  // ismei ye leke chalenge ki is wale element ka ans kya ho skta hai 
  // vo find krenege
  // and jb hum loop seedha chalayege -> tb ye leke chalenge ki ye wala 
  // element pichle kis kis element ka ans ho skta hai

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

  reverse(ans.begin(), ans.end());

  return ans;
}
