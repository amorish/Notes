// Largest in Array

/*

Given an array arr[]. The task is to find the largest element and return it.

Examples:

Input: arr[] = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.

Input: arr[] = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.

Input: arr[] = [10]
Output: 10
Explanation: There is only one element which is the largest.

Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 106

*/

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  vector<int> v(n);
  
  for(int i = 0; i<n; i++){
    cin>>v[i];
  }
  
  
  
  int max = 0;
  
  for(int x: v){
    if(x>max) max = x;
  }
  
  cout<<max;
  
  
  // method - 2
  
  sort(v.begin(), v.end(), greater<int>());
  
  cout<<endl<<v[0];
}



// INPUT

// 5 4 1 2 6 3 

// OUTPUT

// 6
