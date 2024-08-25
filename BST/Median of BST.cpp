int count(struct Node *root){
    if(root == NULL){
        return 0;
    }
    return  1 + count(root->left) + count(root->right);
}
int cnt = 0;
float pre = -1; // n/2th node
float mid = -1; // (n+1)/2th node
float nxt = -1; // (n+2)/2th node

void helper(struct Node *root,int n){
    if(root == NULL){
        return;
    }
    helper(root->left,n);
    cnt++;
    if(cnt == n/2){
        pre = root->data;
    }
    else if(cnt == (n+1)/2){
        mid = root->data;
    }
    else if(cnt == (n+2)/2){
        nxt = root->data;
    }
    helper(root->right,n);
    
    return;
}
// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root){
    
    if(root == NULL){
        return -1;
    }
    int n = count(root);
    
    cnt = 0; // as humne isse globally declare kiya hua hai, to agle testcase mei purani wali value cnt mei na ho isliye yha fir se 0 se initialize kr do
	helper(root,n);
    float ans = 0;
    if(n % 2 == 0){
        ans = (float)(pre + nxt)/2.0;
    }else{
        ans = mid;
    }
    return ans;
}