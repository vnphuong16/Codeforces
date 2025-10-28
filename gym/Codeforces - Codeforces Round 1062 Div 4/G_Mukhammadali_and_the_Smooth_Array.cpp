//  G. Mukhammadali and the Smooth Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using i64 = long long;

auto Solve() -> void {
	int n{0};
	::std::cin >> n;

	::std::vector<i64> a(n), c(n);
	for (int i{0}; i < n; ++i) ::std::cin >> a[i];
	for (int i{0}; i < n; ++i) ::std::cin >> c[i];

	i64 totalC{0};
	for (int i{0}; i < n; ++i) totalC += c[i];

	::std::vector<i64> dp(n, 0);
	i64 bestKeep{0};

	for (int i{0}; i < n; ++i) {
		i64 bestPrev{0};
		for (int j{0}; j < i; ++j) {
			if (a[j] <= a[i]) {
				bestPrev = ::std::max(bestPrev, dp[j]);
			}
		}
		dp[i] = c[i] + bestPrev;
		bestKeep = ::std::max(bestKeep, dp[i]);
	}

	i64 answer = totalC - bestKeep;
	::std::cout << answer << '\n';
	return;
}

auto main() -> int {
	int t{0};
	::std::cin >> t;
	while (t--) {
		Solve();
	}
	return 0;
}