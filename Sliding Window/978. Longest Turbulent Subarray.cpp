class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        
        //A subarray is turbulent if the comparison sign flips between each           adjacent pair of elements in the subarray.
        
        // i.e beech wala element ya to dono side wale elements se chhota 
        //hoga ya bda hoga
        
        int len = INT_MIN;
        int l=0, r=1;
        
        if(n == 1){
            return 1;
        }
        
        if(n == 2){
            if(arr[l] == arr[r]){
                return 1;
            }else{
                return 2;
            }
        }
        
        while(l <= r && r < n-1){
            if((arr[r] > arr[r-1] && arr[r] > arr[r+1]) || (arr[r] < arr[r-1] && arr[r] < arr[r+1]) ){
                
                r++;
            }else{
                if((r == (l+1)) && arr[r] == arr[l]){
                    len = max(len, 1);
                    //cout<<len<<" ->"<<endl;
                }else{
                    len = max(len, (r-l+1));
                    //cout<<len<<" ->"<<endl;
                }
                l = r;
                r++;
            }
        }
        
        // agr hum kabhi else block mei gye hi nhi
        // ya fir agr last wali subarray longest hui
        // as hum last walo ke liye else mei nhi ja payege
        if((r == (l+1)) && arr[r] == arr[l]){
            len = max(len, 1);
            //cout<<len<<" ->"<<endl;
        }else{
            len = max(len, (r-l+1));
            //cout<<len<<" ->"<<endl;
        }
        
        return len;
    }
};