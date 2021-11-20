// bool checkAnagram(string a,string p){
// //     sort(a.begin(), a.end());
// //     sort(b.begin(), b.end());
    
// //     if(a == b){
// //         return true;
// //     }
// //     return false;
    
//     unordered_map<int,int> m;
//     for(int i=0; i<p.length(); i++){
//         m[p[i]]++;
//     }
    
//     for(int i=0; i<a.length(); i++){
//         if(m[a[i]] == 1){
//             m.erase(a[i]);
//         }else{
//             m[a[i]]--;
//         }
//     }
    
//     if(m.empty()){
//         return true;
//     }
//     return false;
// }

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k = p.length();
        // yha pe window ka size fixed hoga i.e k
        int n = s.length();
        
        // agr k ka size bda hua to ans vector mei kuch nhi aayega
        if(k > n){
            return {};
        }
        
//         int i=0;
//         while(i <= (n-k)){
//             string x = s.substr(i,k);//i.e starting from idx = i, of len = k
//             if(checkAnagram(x,p)){
//                 ans.push_back(i);
//             }
            
//             i++;
//         }
        
        //int freq[26] = {0};
        vector<int> freq(26,0);
        
        for(int i=0; i<k; i++){
            int x = int(p[i]);
            //cout<<x<<endl;
            freq[x-97]++;
        }
        
        // for(int i=0; i<26; i++){
        //     cout<<freq[i]<<" ";
        // }
        
        //int fq[26] = {0};
        vector<int> fq(26,0);
        int i=0, j=k-1;
        
        //string str = s.substr(i,k);
        for(int i=0; i<k; i++){
            int y = int(s[i]);
            //cout<<y<<endl;
            fq[y-97]++;
        }
        
        
        // upar humne 2 arrays ki jagha 2 vector isliye liye, bcz hum 
        // aise vectors ko compare kr skte hai
        if(freq == fq){
            ans.push_back(i);
        }        
        // for(int i=0; i<26; i++){
        //     cout<<fq[i]<<" ";
        // }
        
        while(j < n-1){
            int start = int(s[i]);
            fq[start-97]--;
            i++;
            
            j++;
            //if(j < n){
                int end = int(s[j]);
                fq[end-97]++;
            //}
            
            if(freq == fq){
                ans.push_back(i);
            }            
            
            //j++;
        }
        
        
        // cout<<endl;
        // for(int i=0; i<26; i++){
        //     cout<<fq[i]<<" ";
        // }
        
        return ans;
    }
};