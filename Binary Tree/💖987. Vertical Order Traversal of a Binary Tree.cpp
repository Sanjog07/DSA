

// Vertical Order Traversal krte hue hmesha level order traversal ka use kro 
// kabhi recursive traversal mt lgayo 
// usse ans galat hi aayega

class Solution {
    
    map<int,vector<int>> m;
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> ans;
        queue<pair<int,TreeNode*>> q;
        
        q.push({0, root});
        
        while(!q.empty()){
            int n = q.size();
            
            // priority_queue<pair<int,TreeNode*>, vector<pair<int,TreeNode*>>, greater<pair<int,TreeNode*>> > pq;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            
            for(int i=0; i<n; i++){
                auto f = q.front();
                q.pop();
                
                int dist = f.first;
                TreeNode* temp = f.second;
                
                pq.push({dist, temp->val});
                if(temp->left){
                    q.push({dist-1, temp->left});
                }
                if(temp->right){
                    q.push({dist+1, temp->right});
                }                
            }
            
            while(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                
                m[p.first].push_back(p.second);
            }
        }
        
        for(auto e: m){
            vector<int> v = e.second;
            ans.push_back(v);
        }
        
        return ans;
    }
};


// YE NICHE WALA METHOD GALAT HAI
// [3,1,4,0,2,2] -> see this eg

// class Solution {
    
//     map<int,priority_queue<int, vector<int>, greater<int>> > m;
    
//     void helper(TreeNode* root, int dist){
//         if(root == NULL){
//             return;
//         }
        
//         m[dist].push(root->val);
//         helper(root->left, dist-1);
//         helper(root->right, dist+1);
        
//         return;
//     }    
    
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         if(root == NULL){
//             return {};
//         }
        
//         helper(root, 0);
        
//         vector<vector<int>> ans;
//         for(auto p: m){
//             vector<int> v;
//             priority_queue<int, vector<int>, greater<int>> pq = p.second;
            
//             while(!pq.empty()){
//                 v.push_back(pq.top());
//                 pq.pop();
//             }
            
//             ans.push_back(v);
//         }
        
//         return ans;
//     }
// };