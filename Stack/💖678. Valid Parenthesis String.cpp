
// https://www.youtube.com/watch?v=KuE_Cn3xhxI

typedef pair<char,int> pii;

class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size();
        
        stack<pii> s1;
        stack<pii> s2;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                s1.push({ch, i});
            }else if (ch == '*'){
                s2.push({ch, i});
            }else{
                if(!s1.empty()){
                    s1.pop();
                }else if(!s2.empty()){
                    s2.pop();
                }else{
                    return false;
                }
            }
        }
        
        // last mei agr s1 mei "(" bach gye and s2 mei bhi "*" hai
        // to inn "*" ko as ")" consider kr lenge
        
        // and upar "*" ko as "(" consider kiya tha
        if(s1.size() > s2.size()){
            return false;
        }
        
        
        // pr abhi bhi ek aur cheez check krni pdegi ki
        // jo s2 mei "*" hai unka idx khi s1 ke "(" se chhota to nhi
        // e.g -> ***(((
        // upar wali condi ke hisaab se to iska ans should be true
        // but yha pe "*" ko as ")" consider krke fayda hi nhi
        
        while(!s1.empty()){
            int x = s1.top().second;
            int y = s2.top().second;
            
            if(x < y){
                s1.pop();
                s2.pop();
            }else{
                return false;
            }
        }
        
        return true;
    }
};

