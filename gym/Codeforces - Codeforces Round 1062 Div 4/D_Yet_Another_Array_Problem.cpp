//  D. Yet Another Array Problem

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using i64 = long long;
using u64 = unsigned long long;

static auto SmallPrimes() -> const ::std::vector<int>& {
	static const ::std::vector<int> v{
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
		71, 73, 79, 83, 89, 97
	};
	return v;
}

auto Solve() -> void {
	int n;
	::std::cin >> n;

	::std::vector<u64> a(n);
	for (int i{0}; i < n; ++i) {
		::std::cin >> a[i];
	}

	u64 g{0};
	for (int i{0}; i < n; ++i) {
		g = (i == 0) ? a[i] : ::std::gcd(g, a[i]);
	}

	u64 answer{0};
	for (int p : SmallPrimes()) {
		if (g % static_cast<u64>(p) != 0ULL) {
			answer = static_cast<u64>(p);
			break;
		}
	}

	if (answer == 0ULL) {
		u64 p{101};
		auto IsPrime = [](u64 _X) -> bool {
			if (_X < 2) return false;
			if (_X % 2 == 0) return _X == 2;
			for (u64 d{3}; d * d <= _X; d += 2) {
				if (_X % d == 0) return false;
			}
			return true;
		};
		while (true) {
			if (IsPrime(p) && (g % p != 0ULL)) { answer = p; break; }
			p += 2;
		}
	}

	::std::cout << answer << '\n';
	return;
}

auto main() -> int
{
	int t{ 0 };
	::std::cin >> t;
	while(t--) {
		Solve();
	}
	return 0;
}