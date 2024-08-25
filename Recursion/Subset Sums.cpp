
// Striver Solu Link: 
// 1) https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=53
// 2) https://github.com/striver79/SDESheet/blob/main/SubsetSumsC%2B%2B
// 3) https://github.com/striver79/SDESheet/blob/main/SubsetSumsC%2B%2B

// Apne wala code

class Solution{
   
    vector<int> helper(vector<int> arr, int n,int i){
        vector<int> ans;
        if(i == n-1){
            ans.push_back(0); // iss wale element ko consider na kro
            ans.push_back(arr[i]); // iss wale element ko consider kr lo
            return ans;
        }
        
        vector<int> a = helper(arr, n, i+1);
        // if hum current ele ko consider nhi krenge
        for(int j=0; j<a.size(); j++){
            ans.push_back(a[j]);
        }
        // if hum current ele ko consider krenge
        for(int j=0; j<a.size(); j++){
            ans.push_back(arr[i] + a[j]);
        }  
        
        return ans;
    }   
    
public:
    vector<int> subsetSums(vector<int> arr, int n){
        vector<int> solu = helper(arr,n,0);
        
        return solu;
    }
};