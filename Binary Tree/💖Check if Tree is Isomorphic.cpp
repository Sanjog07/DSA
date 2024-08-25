
class Solution{
    
  public:
    // Return True if the given trees are isomorphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        
        bool notSwap = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
        bool swap = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
        
        if((root1->data == root2->data) && (notSwap || swap)){
            return true;
        }
        
        return false;
    }
};