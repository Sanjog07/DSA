class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int> > minh;   
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxh.empty()){
            maxh.push(num);
            return;
        }
        
        double med = findMedian();
        // cout<<"/././././.   ";
        // cout<<med<<" ";
        if(num < med){
            maxh.push(num);
        }else{
            minh.push(num);
        }
        
        if(maxh.size() > (minh.size()+1)){
            minh.push(maxh.top());
            maxh.pop();
        }
        if(minh.size() > (maxh.size()+1)){
            maxh.push(minh.top());
            minh.pop();
        }        
    }
    
    double findMedian() {
        
        double ans;
        
        if(maxh.size() == minh.size()){
            double a = (double)(maxh.top());
            double b = (double)(minh.top());
            
            // cout<<endl<<"-------";
            // cout<<a<<" "<<b<<" ";
            
            ans = (a+b)/2.0;
            
        }else if(maxh.size() == (minh.size() + 1)){
            ans = (double)(maxh.top());
        }else if(minh.size() == (maxh.size() + 1)){
            ans = (double)(minh.top());
        }
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */