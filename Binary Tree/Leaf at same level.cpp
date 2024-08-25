class Solution{
    
    bool helper(Node* root, int dist, int hei){
        if(root == NULL){
            return true;
        }      
        if(root->left == NULL && root->right == NULL){
            return dist == hei;
        }
        
        bool l = helper(root->left, dist+1, hei);
        bool r = helper(root->right, dist+1, hei);
        
        if(l && r){
            return true;
        }
        
        return false;
    }
    
    int height(Node*root){
        if(root == NULL){
            return 0;
        }
        
        return max(height(root->left),height(root->right)) + 1;
    }
    
  public:
    /*You are required to complete this method*/
    bool check(Node *root){
       int h = height(root);
       
       return helper(root, 1, h);
    }
};



// Below method is wrong as humko sabhi leaf nodes check krni hai
// and ismei ye check ho rha hai ki ek level wali sabhi node
// leaf hai ya nhi 
// see eg -> 10 20 30 10 15

//class Solution{
//   public:
//     /*You are required to complete this method*/
//     bool check(Node *root){
//         if(root == NULL){
//             return true;
//         }
        
//         queue<Node*> q;
//         q.push(root);
        
//         while(!q.empty()){
//             int n = q.size();
            
//             int cnt = 0;
//             for(int i=0; i<n; i++){
//                 auto f = q.front();
//                 q.pop();
                
//                 if(f->left == NULL && f->right == NULL){
//                     cnt++;
//                     continue;
//                 }
                
//                 if(f->left){
//                     q.push(f->left);
//                 }
//                 if(f->right){
//                     q.push(f->right);
//                 }                
//             }
            
//             if(cnt == n){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };