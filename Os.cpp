#include<iostream>
using namespace std;

// Roll No : 2019UEC2713

void avgTime(int n, int bt[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    wt[0] = 0;
 
    for (int  i = 1; i < n ; i++){
        wt[i] =  bt[i-1] + wt[i-1];
    } 
    for (int  i = 0; i < n ; i++){
        tat[i] = bt[i] + wt[i]; 
    }

    
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";

    for (int  i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
int main(){

    cout<<"Sanjog Kukreja"<<endl;
    cout<<"2019UEC2713"<<endl;
  
    // Enter the No of Processes
    int n;
    cin>>n;
    int bt[n];
    for(int i=0; i<n; i++){
      cin>>bt[i];
    }
 
    avgTime(n, bt);
    return 0;
}
