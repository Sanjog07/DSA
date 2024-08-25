
typedef pair<Node*, int> pii;

class Solution{
    
    Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root == NULL || root->data == p || root->data == q){
            return root;
        }
        
        Node* l = lowestCommonAncestor(root->left, p, q);
        Node* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r){
            return root;
        }
        
        return (l != NULL) ? l : r;
    }    
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        if(root == NULL){
            return 0;
        }
        
        //i.e ans = dist(lca, a) + dist(lca, b)
        
        Node* lca = lowestCommonAncestor(root, a, b);
        
        int x = -1, y = -1;
        queue<pii> q;
        int dist = 0;
        q.push({lca, dist});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            Node* temp = p.first;
            dist = p.second;
            
            if(temp->data == a){
                x = dist;
            }else if(temp->data == b){
                y = dist;
            }
            
            if(temp->left){
                q.push({temp->left, dist+1});
            }
            if(temp->right){
                q.push({temp->right, dist+1});
            }  
            
            if(x != -1 && y != -1){
                // it means we've found dist of lca from both the nodes
                break;
            }
            
        }
        
        return x+y;
    }
};