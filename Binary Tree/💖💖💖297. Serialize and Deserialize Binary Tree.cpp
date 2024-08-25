class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        string ans = "";
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            if(f == NULL){
                ans += "#,";
            }else{
                ans += to_string(f->val);
                ans += ',';
            }
            
//             if(f != NULL){
//                 if(f->left){
//                     q.push(f->left);
//                 }else{
//                     q.push(NULL);
//                 }
                
//                 if(f->right){
//                     q.push(f->right);
//                 }else{
//                     q.push(NULL);
//                 }                
//             }
            
            // upar wale ko chhote tareeke se likhna
            if(f != NULL){
                q.push(f->left);
                q.push(f->right);
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();
        if(n == 0){
            return NULL;
        }
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root); 
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#"){
                f->left = NULL;
            }else{
                f->left = new TreeNode(stoi(str));
                q.push(f->left);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                f->right = NULL;
            }else{
                f->right = new TreeNode(stoi(str));
                q.push(f->right);
            }          
        }        
        
        return root;
    }
};