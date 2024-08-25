class MyHashSet {
    
    vector<bool> v;
    
public:
    MyHashSet() {
        v.resize(1e6+1, false);
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    bool contains(int key) {
        return v[key];
    }
};



// https://leetcode.com/problems/design-hashset/discuss/1968031/CPP-or-Fastre-than-97-or-Easy-Understand-or-TC%3A-O(1)-SC%3A-O(n)orUsing-vector


// class MyHashSet {
    
//     vector<int> v;
    
// public:
//     MyHashSet() {
        
//     }
    
//     void add(int key) {
//         if(contains(key) == false){
//             v.push_back(key);
//         }
//     }
    
//     void remove(int key) {
//         if(contains(key) == true){
//             int idx = -1;
//             for(int i=0; i<v.size(); i++){
//                 if(v[i] == key){
//                     idx = i;
//                     break;
//                 }
//             }
            
//             v.erase(v.begin() + idx);
//         }
//     }
    
//     bool contains(int key) {
//         for(int i=0; i<v.size(); i++){
//             if(v[i] == key){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };