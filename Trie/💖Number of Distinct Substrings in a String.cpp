#include<bits/stdc++.h>


class Node{
public:    
    bool data;
    unordered_map<char,Node*> child;

    Node(char d){
        data = d;
    }
};


int distinctSubstring(string &str) {
    int n = str.size();

    int cnt = 0;
    Node* root = new Node('\0');
    for(int i=0; i<n; i++){
        Node* node = root;
        for(int j=i; j<n; j++){
            char ch = str[j];
            if(node->child.find(ch) == node->child.end()){
                Node* n = new Node(ch);
                node->child[ch] = n;
                cnt++;
                node = node->child[ch];
            }else{
                node = node->child[ch];
            }
        }
    }

    return cnt;
}
