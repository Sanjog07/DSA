

//https://www.youtube.com/watch?v=9_IGe5K7vss&t=722s

bool helper(Node* root,int min, int max){
    if(root == NULL){
        return false;
    }
    if((max-min) <= 2){
        // agr max-min <= 2 hai it means curent root->data is exactly b/w
        // max and min eg if max = 10 and min = 8 so root->data = 9
        // so hum ab iss root kr baad kuch insert nhi kr skte 
        // bcz tb max - min <= 1 ho jayega and unke beech koi integral value 
        // exist hi nhi kregi -> eg max = 12 and min = 11
        return true;
    }
    
    int value = root->data;
    bool lans = helper(root->left, min, value);
    if(lans) return true;
    
    bool rans = helper(root->right, value, max);
    if(rans) return true;    
    
    return false;    
}

bool isDeadEnd(Node *root){
    
    // Dead End jo hoga vo hmesha ek leaf node hi hogi
    // thoda confusing ho skta hai smajhna ye but aisa hi hai
    // Here Dead End means, we are not able to insert any element after that node.
    // i.e hum after that node -> i.e hum uss node ke baad koi node 
    // insert nhi kr pa rhe hai
    // and here in the 2nd eg mei aise to hum 7 ke baad bhi kuch insert nhi kr pa rhe hai
    // but 7 ke left mei already 2 hai hi and hum 2 ko htake kuch aur lga skte hai
    // and this shows ki leaf node ke alawa nodes are non dead end wali nodes
    
    
    if(root == NULL){
        return false;
    }
    
    // here min value is 0 and not INT_MIN -> mentioned in ques
    return helper(root, 0, INT_MAX);
}