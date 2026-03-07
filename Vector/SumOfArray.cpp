// SUM OF ARRAY

/*

Difficulty: Basic

You are given an integer array arr[]. The task is to find the sum of it.

Examples: 

```
Input:arr[] = [1, 2, 3, 4]
Output: 10
Explanation: 1 + 2 + 3 + 4 = 10.
```

```
Input:arr[] = [1, 3, 3]
Output: 7
Explanation: 1 + 3 + 3 = 7.
```

Constraints:

1 <= arr.size <= 10^5
1 <= arr[i] <= 10^4

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n;
	cin>>n;
	
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin>>v[i];
	}
	
	int sum = 0;
	for(int i: v){
		sum += i;
	}
	
	cout<<sum;
	return 0;
}

// ======================================
// INPUT:

/*

3
7 4 1

*/

// ======================================
// OUTPUT

/*

12

*/