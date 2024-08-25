


// https://www.youtube.com/watch?v=2r5wLmQfD6g

class Solution {
    
    unordered_map<Node*, Node*> par;
    unordered_map<Node*, bool> vis;

    Node* target = NULL;

    void helper(Node* root, int tar){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            auto f = q.front();
            q.pop();

            if(f->data == tar){
                target = f;
            }

            if(f->left){
                par[f->left] = f;
                q.push(f->left);
            }
            if(f->right){
                par[f->right] = f;
                q.push(f->right);
            }            
        }
        
        par[root] = NULL;
    }

    int solve(){
        queue<Node*> q;
        q.push(target);

        int ans = -1;

        while(!q.empty()){
            int n = q.size();

            for(int i=0; i<n; i++){
                auto temp = q.front();
                q.pop();
                
                vis[temp] = true;

                Node* parent = par[temp];
                if(parent != NULL){
                    if(vis[parent] == false){
                        q.push(parent);
                    }        
                }
                if(temp->left){
                    if(vis[temp->left] == false){
                        q.push(temp->left);
                    }
                }
                if(temp->right){
                    if(vis[temp->right] == false){
                        q.push(temp->right);
                    }
                }                
            }

            ans++;
        }

        return ans;
    }
    
  public:
    int minTime(Node* root, int tar){
        if(root == NULL){
            return 0;
        }       
        helper(root, tar);

        return solve();
    }
};