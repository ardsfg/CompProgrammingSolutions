// Problem: D. Buy Low Sell High
// Contest: Codeforces - MemSQL Start[c]UP 3.0 - Round 2 and Codeforces Round 437 (Div. 1)
// URL: https://codeforces.com/contest/866/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int p;
		cin >> p;
		ans -= p;
		pq.push(p);
		pq.push(p);
		pq.pop();
	}
	for (int i = 0; i < N; ++i) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << "\n";
}