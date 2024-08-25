

// https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53

class BSTIterator {
    
    stack<TreeNode*> s;
    bool reverse = false;
    
public:
    BSTIterator(TreeNode* root, bool rev){
        TreeNode* temp = root;
        reverse = rev;
        
        while(temp != NULL){
            s.push(temp);
            if(reverse){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
    }
    
    int next() {
        auto ans = s.top();
        s.pop();
        
        auto temp = ans;
        if(reverse){
            if(temp->left){
                temp = temp->left;
                while(temp){
                    s.push(temp);
                    temp = temp->right;
                }
            }            
        }else{
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
            }            
        }
        
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* obj1 = new BSTIterator(root, false);
        BSTIterator* obj2 = new BSTIterator(root, true);
        
        int i = obj1->next();
        int j = obj2->next();
        
        while(i < j){ // as i and j values hai and BST mei values bhi sorted hoti hai -> inorder mei -> and hum ussi hisaab se hi to chal rhe hai
            
            int x = i+j;
            if(x == k){
                return true;
            }else if(x < k){
                if(obj1->hasNext()){
                    i = obj1->next();
                }else{
                    return false;
                }
            }else{
                if(obj2->hasNext()){
                    j = obj2->next();
                }else{
                    return false;
                }                
            }
        }
        
        return false;
    }
};