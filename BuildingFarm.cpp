// Problem: Problem 2. Building a Tall Barn
// Contest: USACO - USACO 2017 January Contest, Platinum
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=697
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long



int main(){
	
	ll n,k; cin>>n>>k;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i<n; i++) cin>>a[i];
	
	auto query_x = [&](double x){ // all slopes >= x
		int num = 0;
		for(int i = 0; i<n; i++){
			// a_i / c(c+1) <= x, c(c+1)x >= a[i], larger root approx -1 + sqrt1 + 4a[i]/x ) /2
			ll mx = (ll) (-1 + sqrt(1 + 4*a[i] / x))/2.0;
			if(mx == 0) mx = 1;
			num += mx;
		}
		return num;
	};
	
	double low = 0;
	double high = 1e12;
	
	for(int i = 0; i<200; i++){
		double mid = (low + high)/2.0;
		query_x(mid) >= k ? low = mid : high = mid;
	}
	
	double ans = 0;
	ll tot = 0;
	
	for(int i = 0; i<n; i++){
		ll mx = (ll)(-1 + sqrt(1+4*a[i]/low))/2.0;
		if(mx == 0){
			mx = 1;
			tot+=mx;
			ans+=1.0*a[i]/mx;
		}else{
			tot+=mx;
			ans+=1.0*a[i]/mx;
		}
	}
	cout<<(ll)round(ans)<<endl;
}