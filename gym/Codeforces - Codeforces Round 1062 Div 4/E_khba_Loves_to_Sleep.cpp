//  E. khba Loves to Sleep!

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

using i64 = long long;

struct Interval {
	i64 L{0}, R{0};
};

auto MergeBadIntervals(::std::vector<Interval> &_V) -> ::std::vector<Interval> {
	if (_V.empty()) return {};
	::std::sort(_V.begin(), _V.end(), [](auto const &a, auto const &b){
		return (a.L < b.L) || (a.L == b.L && a.R < b.R);
	});
	::std::vector<Interval> res;
	res.reserve(_V.size());
	res.push_back(_V[0]);
	for (size_t i{1}; i < _V.size(); ++i) {
		if (_V[i].L <= res.back().R + 1) {
			res.back().R = ::std::max(res.back().R, _V[i].R);
		} else {
			res.push_back(_V[i]);
		}
	}
	return res;
}

auto CountSafe(i64 _X, ::std::vector<i64> const &_A, i64 _R) -> i64 {
	if (_R <= 0) {
		return _X + 1;
	}
	::std::vector<Interval> bad;
	bad.reserve(_A.size());
	for (auto v : _A) {
		i64 L = v - (_R - 1);
		i64 R = v + (_R - 1);
		if (R < 0 || L > _X) continue;
		if (L < 0) L = 0;
		if (R > _X) R = _X;
		bad.push_back({L, R});
	}
	auto merged = MergeBadIntervals(bad);
	i64 covered{0};
	for (auto const &iv : merged) covered += (iv.R - iv.L + 1);
	i64 total = _X + 1;
	return total - covered;
}

auto BuildAnswer(i64 _X, ::std::vector<i64> const &_A, i64 _R, i64 _K) -> ::std::vector<i64> {
	::std::vector<Interval> bad;
	if (_R > 0) {
		bad.reserve(_A.size());
		for (auto v : _A) {
			i64 L = v - (_R - 1);
			i64 R = v + (_R - 1);
			if (R < 0 || L > _X) continue;
			if (L < 0) L = 0;
			if (R > _X) R = _X;
			bad.push_back({L, R});
		}
	}
	auto merged = MergeBadIntervals(bad);

	::std::vector<i64> ans;
	ans.reserve(static_cast<size_t>(_K));

	i64 cur{0};
	for (auto const &iv : merged) {
		if (cur < iv.L) {
			for (i64 p = cur; p <= iv.L - 1 && static_cast<i64>(ans.size()) < _K; ++p) {
				ans.push_back(p);
			}
			if (static_cast<i64>(ans.size()) == _K) return ans;
		}
		cur = iv.R + 1;
		if (cur > _X) break;
	}
	if (cur <= _X) {
		for (i64 p = cur; p <= _X && static_cast<i64>(ans.size()) < _K; ++p) {
			ans.push_back(p);
		}
	}
	return ans;
}

auto Solve() -> void {
	int n{0};
	i64 k{0}, x{0};
	::std::cin >> n >> k >> x;

	::std::vector<i64> a(n);
	for (int i{0}; i < n; ++i) ::std::cin >> a[i];
	::std::sort(a.begin(), a.end());

	i64 rMax{0};
	if (!a.empty()) {
		rMax = ::std::max(a[0] - 0, x - a.back());
		for (int i{0}; i + 1 < n; ++i) {
			rMax = ::std::max(rMax, (a[i + 1] - a[i]) / 2);
		}
	}

	i64 lo{0}, hi{rMax}, best{0};
	while (lo <= hi) {
		i64 mid = lo + (hi - lo) / 2;
		if (CountSafe(x, a, mid) >= k) {
			best = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	auto ans = BuildAnswer(x, a, best, k);
	for (int i{0}; i < static_cast<int>(ans.size()); ++i) {
		if (i) ::std::cout << ' ';
		::std::cout << ans[i];
	}
	::std::cout << '\n';
}

auto main() -> int {
	int t{0};
	::std::cin >> t;
	while (t--) {
		Solve();
	}
	return 0;
}