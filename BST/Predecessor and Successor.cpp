
void helper(Node* root, Node*& pre, Node*& suc, int key){

    Node* temp = root;
    while(temp){
        int val = temp->key;
        if(val >= key){
            temp = temp->left;
        }else{
            pre = temp;
            temp = temp->right;
        }
    }
    
    temp = root;
    while(temp){
        int val = temp->key;
        if(val <= key){
            temp = temp->right;
        }else{
            suc = temp;
            temp = temp->left;
        }
    }    
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if(root == NULL){
        return;
    }
    
    helper(root, pre, suc, key);
    
    return;
}


// void inorder(Node* root,vector<Node*> &v){
//     if(root == NULL){
//         return;
//     }
    
//     inorder(root->left,v);
//     v.push_back(root);
//     inorder(root->right,v);
    
//     return;
// }

// // This function finds predecessor and successor of key in BST.
// // It sets pre and suc as predecessor and successor respectively
// void findPreSuc(Node* root, Node* &pre, Node* &suc, int key){
//     if(root == NULL){
//         return;
//     }
//     vector<Node*> v;
//     inorder(root,v);
    
//     // for(int i=0; i<v.size(); i++){
//     // for(int i=0; i<v.size(); i++){
//     //     cout<<v[i]->key<<" ";
    
//     // pre = NULL;
//     // suc = NULL;
    
//     for(int i=0; i<v.size(); i++){
//         if(v[i]->key < key){
//             pre = v[i];
//         }else if(v[i]->key > key){
//             suc = v[i];
//             break;
//         }
//     }