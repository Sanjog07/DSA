
typedef pair<int,int> pii;

class Solution{
    
    pii helper(Node *root){
        pii p;
        if(root == NULL){
            p.first = 0;
            p.second = 0;
            
            return p;
        }
        
        
        pii lef = helper(root->left);
        pii rig = helper(root->right);
        
        p.second = max(lef.second, rig.second) + 1;
        
        if(lef.second > rig.second){
            p.first = lef.first + root->data;
        }else if(rig.second > lef.second){
            p.first = rig.first + root->data;
        }else if(lef.second == rig.second){
            p.first = max(lef.first, rig.first) + root->data;
        }
        
        return p;
     }

public:
    
    int sumOfLongRootToLeafPath(Node *root){
        if(root == NULL){
            return 0;
        }
        pii ans = helper(root);
        
        return ans.first;
    }
};