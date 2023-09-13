int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.

	if(arr.size() == 0){
		return 0;
	}

	int l = 0, r = arr.size()-1;
	int ans = -1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid] == m){
			return mid;
		}
		else if(arr[mid] < m){
			l = mid+1;
			ans = l;
		}
		else{
			r = mid-1;
			ans = r+1;
		}
	}
	return ans;
}

//Time Complexity: O(log n);
//Space Complexity: O(1);