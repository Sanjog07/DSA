class Solution {
    
    vector<int> ans;
    
    void solve1(Node* root){
        // always remember isko root->left se start kro 
        // and not from root;
        // bcz agr root se start kiya and root->left NULL hua 
        // in that case ans galat aayega
        
        Node* temp = root->left;
        while(temp){
            if(temp->left == NULL && temp->right == NULL){
                break;
            }
            ans.push_back(temp->data);    
            if(temp->left){   
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        
        return;
    }
    
    void solve2(Node* root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        solve2(root->left);
        solve2(root->right);
        
        return;
    }
    
    void solve3(Node* root){
      
        Node* temp = root->right;
        
        vector<int> v;
        while(temp){
            if(temp->left == NULL && temp->right == NULL){
                break;
            }
            v.push_back(temp->data);
            if(temp->right){
                temp = temp->right;
            }else{
                temp = temp->left;
            }            
        }
        
        for(int i=v.size()-1; i>=0; i--){
            ans.push_back(v[i]);
        }
        
        return;
    }    
    
public:
    vector<int> boundary(Node *root){
        if(root == NULL){
            return {};
        }
        ans.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            return ans;
        }
        
        solve1(root);
        solve2(root);
        solve3(root);
        
        return ans;
    }
};