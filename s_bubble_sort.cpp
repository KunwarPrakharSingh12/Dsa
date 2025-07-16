#include<bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(int arr[], int n)
{
 for(int i=0; i<n-1; i++){
  for(int j=1; j<n-i; j++){
    if(arr[j-1]>arr[j]){
      swap(arr[j-1], arr[j]);
    }

  }
 }
  return vector<int>(arr, arr+n);
}

int main(){
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements: ";
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
cout << "Sorted array: ";
  vector<int> sortedArr = bubbleSort(arr.data(), n);
  for(int i = 0; i < n; i++) {
    cout << sortedArr[i] << " ";
  }
 
  return 0;
}