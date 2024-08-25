
// https://www.youtube.com/watch?v=ZbybYvcVLks

#define ll long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        ll ans = INT_MIN;
        while(!q.empty()){
            ll n = q.size();
            ll diff = q.front().second;
            
            ll lb,rb;
            for(int i=0; i<n; i++){
                auto f = q.front();
                q.pop();
                
                auto temp  = f.first;
                ll idx = f.second;
                if(i == 0){
                    lb = idx;
                }
                if(i == n-1){
                    rb = idx;
                }
                idx -= diff; 
                // we can also do idx -= 1 but usse integer overflow 
                // aayega -> bcz no of nodes kaafi jyada hai
                // so starting wali node se subtract krdo
                
                if(temp->left){
                    q.push({temp->left, 2*idx+1});
                }
                if(temp->right){
                    q.push({temp->right, 2*idx+2});
                }                
            }
            
            ans = max(ans, (rb-lb)+1);
        }
        
        return ans;
    }
};