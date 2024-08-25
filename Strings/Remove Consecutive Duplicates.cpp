string removeDuplicate(string &str){
    int n = str.size();
    if(n == 1){
        return str;
    }

    int prev = 0, curr = 1;
    string ans = "";
    ans +=  str[0];
    while(curr < n){
        if(str[prev] == str[curr]){
            curr++;
        }else{
            ans += str[curr];
            prev = curr;
            curr++;
        }
    }

    return ans;
}
