
class Solution {
    
    void dfs(Node* orig, Node* temp, vector<Node*> &vis){
        vis[orig->val] = temp;
        
        for(auto nbr: orig->neighbors){
            if(!vis[nbr->val]){
                Node* n = new Node(nbr->val);
                temp->neighbors.push_back(n);
                dfs(nbr, n, vis);
            }else{
                temp->neighbors.push_back(vis[nbr->val]);
            }
        }
        
        return;
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        Node* clone = new Node(node->val);
        
        vector<Node*> vis(101, NULL);
        dfs(node, clone, vis);
        
        return clone;
    }
};