#include <bits/stdc++.h> 

void binarySearch(vector<int> arr, int target, int & intersection, int & s, int & e){
	int l = s, r = e;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid] == target){
			intersection++;
			s = mid + 1;
			return;
		}
		else if(arr[mid] < target){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
}

pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	// Write Your Code here.
	pair<int, int> res;
	int intersection = 0;

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	if(n <= m){
		int s = 0, e = m-1;
		for(int i = 0; i<n; i++){
			binarySearch(arr2, arr1[i], intersection, s, e);
		}
	}    
	else{
		int s = 0, e = n-1;
		for(int i = 0; i<m; i++){
			binarySearch(arr1, arr2[i], intersection, s, e);
		}
	}
	 
	res.first = intersection;
	res.second = n + m - intersection;

	return res;  
}