class Solution {
    
    map<int, vector<int>> m;
    
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        queue<pair<Node*, int> > q;
        int dist = 0;
        q.push({root, dist});
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            Node* temp = f.first;
            dist = f.second;
            
            m[dist].push_back(temp->data);
            
            if(temp->left){
                q.push({temp->left, dist-1});
            }
            if(temp->right){
                q.push({temp->right, dist+1});
            }
        }
        
        
        for(auto p: m){
            vector<int> v = p.second;
            ans.push_back(v[v.size() - 1]);
        }
        
        return ans;
    }
};

// Below Method is wrong
// see this: 1 2 3 4 5 6 7 N N N 8 N N N 9

// class Solution {
    
//     map<int, vector<int>> m;
    
//     void helper(Node* root, int dist){
//         if(root == NULL){
//             return;
//         }
        
//         m[dist].push_back(root->data);
//         helper(root->left, dist-1);
//         helper(root->right, dist+1);
        
//         return;
//     }
    
//   public:
//     vector<int> bottomView(Node *root) {
//         vector<int> ans;
        
//         helper(root, 0);
        
//         for(auto p: m){
//             vector<int> v = p.second;
//             ans.push_back(v[v.size() - 1]);
//         }
        
//         return ans;
//     }
// };