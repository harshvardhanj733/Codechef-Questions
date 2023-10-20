#include <bits/stdc++.h> 

bool isPossible(vector<int> time, int n, int m, long long mid);

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long sum = 0;
	for(int i = 0; i < m; i++){
		sum += time[i];
	}

	long long l = 0, r = sum, ans = sum;
	
	while(l <= r){
		long long mid = l + (r - l)/2;
		if(isPossible(time, n, m, mid)){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}

	return ans;
}

bool isPossible(vector<int> time, int n, int m, long long mid){
	int count = 1; long long sum = 0;
	int i = 0;
	while(i < m){
		if(sum + 1LL*time[i] <= mid){
			sum += 1LL*time[i];
			i++;
		}
		else{
			count++;
			if(count > n){
				return false;
			}
			
			sum = 0;
		}
	}

	return true;
}