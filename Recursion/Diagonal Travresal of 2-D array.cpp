
arr -> 2D array

for(int gap=0; gap<arr.length(); gap++){
  for(int i=0, j=gap; j < arr.length(); i++, j++){
    cout<<arr[i][j];
  }
}