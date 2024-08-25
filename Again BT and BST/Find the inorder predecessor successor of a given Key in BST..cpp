
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if(root == NULL){
        return;
    }
    Node* temp = root;
    while(temp != NULL){
        if(temp->key < key){
            pre = temp;
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }
    
    temp = root;
    while(temp != NULL){
        if(temp->key > key){
            suc = temp;
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }  
    
    return;
}