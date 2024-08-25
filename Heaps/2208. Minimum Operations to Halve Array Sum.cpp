class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<double> pq(nums.begin(), nums.end());
        
        double sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        int ope = 0;
        double val = double(sum)/2.0;
        //cout<<val<<endl;
        
        while(sum > val){
            double x = pq.top();
            //cout<<x<<" ";
            pq.pop();
            
            double y = double(x)/2.0;
            pq.push(y);
            sum -= y;
            
            //cout<<sum<<" ";
            ope++;
        }
        
        return ope;
    }
};