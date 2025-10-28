//  F. Tree, TREE!!!

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using i64 = long long;

auto Solve() -> void {
	int n{0}, k{0};
	::std::cin >> n >> k;

	::std::vector<::std::vector<int>> adj(n + 1);
	for (int i{0}; i < n - 1; ++i) {
		int u{0}, v{0};
		::std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	::std::vector<int> parent(n + 1, 0);
	::std::vector<int> order;
	order.reserve(n);

	::std::vector<int> st;
	st.reserve(n);
	st.push_back(1);
	parent[1] = -1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		order.push_back(v);
		for (int u : adj[v]) {
			if (u == parent[v]) continue;
			parent[u] = v;
			st.push_back(u);
		}
	}

	::std::vector<int> sz(n + 1, 1);
	for (int i = n - 1; i >= 0; --i) {
		int v = order[i];
		for (int u : adj[v]) {
			if (u == parent[v]) continue;
			sz[v] += sz[u];
		}
	}

	::std::int64_t ans = n;

	for (int v = 2; v <= n; ++v) {
		int s = sz[v];
		int t = n - s;
		if (s >= k) ans += t;
		if (t >= k) ans += s;
	}

	::std::cout << ans << '\n';
	return;
}

auto main() -> int {
	int t;
	::std::cin >> t;
	while(t--) {
		Solve();
	}
	return 0;
}