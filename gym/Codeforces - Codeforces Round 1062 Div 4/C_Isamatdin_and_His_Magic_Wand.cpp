//  C. Isamatdin and His Magic Wand!

#include <iostream>
#include <vector>
#include <algorithm>

auto IsOdd(int const &num) -> bool {
	return (num % 2) == 1;
}

auto IsEven(int const &num) -> bool {
	return (num % 2) == 0;
}

auto Solve() -> void {
	int n{ 0 };
	::std::cin >> n;
	::std::vector<int> v(n);
	bool hasOdd{false}, hasEven{false};
	for (int i{0}; i < n; ++i) {
		::std::cin >> v[i];
		if (IsOdd(v[i])) { hasOdd = true; }
		if (IsEven(v[i])) { hasEven = true; }
	}

	if (hasOdd && hasEven) {
		::std::sort(v.begin(), v.end());
	}

	for (int i{0}; i < n; ++i) {
		if (i) { ::std::cout << ' '; }
		::std::cout << v[i];
	}
	::std::cout << '\n';

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