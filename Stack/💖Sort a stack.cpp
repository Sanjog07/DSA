void insert(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    
    if(s.top() < val){
        s.push(val);
        return;
    }
    
    int y = s.top();
    s.pop();
    insert(s, val);
    s.push(y);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    int x = s.top();
    s.pop();
    
    sortStack(s);
    insert(s,x);
    
}