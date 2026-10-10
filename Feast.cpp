// Problem: Task 3. Feast
// Contest: NOI 2019 Singapore
// URL: https://oj.uz/problem/view/NOI19_feast
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define ll long long

int main(){
	int n,k; cin>>n>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) cin>>a[i];
	
	auto solve_lambda = [&](ll lmb){
		vector<array<pair<ll,ll>,2>> dp(n);
		dp[0][0] = {0,0};
		dp[0][1] = {a[0] - lmb, 1};
		for(int i = 1; i<n; i++){
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = max(make_pair(dp[i-1][0].first + a[i] - lmb, dp[i-1][0].second + 1), make_pair(dp[i-1][1].first + a[i], dp[i-1][1].second));
		}
		return max(dp[n-1][0], dp[n-1][1]);
	};
	
	ll low = 0;
	ll high = 1e18;
	while(low != high){
		ll mid = (low + high)/2;
		solve_lambda(mid).second >= k ? low = mid : high = mid-1;
	}
	cout<<solve_lambda(low).first * low*k << endl;
}