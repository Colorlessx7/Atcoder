#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y;
    cin >> n >> x >> y;
    vector<int> dp(n);
    dp[0] = x;
    dp[1] = y;
    for(int i = 2; i < n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 100;
    }
    cout << dp[n-1] << endl;
	return 0;
}
