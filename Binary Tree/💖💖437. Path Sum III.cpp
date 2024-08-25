
#define ll long long

class Solution {
    
    ll helper(TreeNode* root, ll tar, ll sum){
        // yha pe sum isliye liya bcz jb tar - root->val 
        // kr rhe the to overflow ho rha tha
        
        if(root == NULL){
            return 0;
        }
        
        sum += root->val;
        ll cnt = 0;
        if(sum == tar){
            cnt++;
            // yha pe return nhi krna
        }
        
        cnt += helper(root->left, tar, sum);
        cnt += helper(root->right, tar, sum);
        
        return cnt; 
    }    
    
public:
    int pathSum(TreeNode* root, int tar) {
        
        // imp pt to notice that the path must go downward
        // i.e we don't have to consider those paths
        // in whih some nodes are in lst and some are in rst        
        
        if(root == NULL){
            return 0;
        }
        
        ll ans1 = helper(root, tar, 0);
        ll ans2 = pathSum(root->left, tar);
        ll ans3 = pathSum(root->right, tar);
        
        return ans1 + ans2 + ans3;
    }
};






#define ll long long

class Solution {
    
    ll cnt;
    void helper(TreeNode* root, ll tar, ll sum){
        if(root == NULL){
            return;
        }
        
        sum += root->val;
        if(sum == tar){
            cnt++;
            // yha pe return nhi krna
        }
        
        helper(root->left, tar, sum);
        helper(root->right, tar, sum);
        
        return;
    }
  
    
public:
    int pathSum(TreeNode* root, int tar) {
        
        // imp pt to notice that the path must go downward
        // i.e we don't have to consider those paths
        // in whih some nodes are in lst and some are in rst        
        
        if(root == NULL){
            return 0;
        }
        
        // yha pe ye cnt ko aise isliye likh rhe hai
        // bca as cnt is globaly declared 
        // and hum root->left and root->right pe same fnc call
        // lga rhe hai
        // agr simply cnt ko declare krre to vo baar baar add hota rhega
        cnt = 0;                
        helper(root, tar, 0);
        ll ans1 = 0;
        ans1 += cnt;
        ll ans2 = pathSum(root->left, tar);
        ll ans3 = pathSum(root->right, tar);
        
        return ans1 + ans2 + ans3;

    }
};



class Solution {
    
    int cnt = 0;
    vector<int> v; // to store the path
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        v.push_back(root->val);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);

        // yha pe hum ye check krenge ki iss root pe end 
        // hone wala koi path hai ya nhi    
        int sum = 0;
        for(int i=v.size()-1; i>=0; i--){
            sum += v[i];
            if(sum == targetSum){
                cnt++;
            }
        }
        v.pop_back();
        
        return cnt;
    }
};