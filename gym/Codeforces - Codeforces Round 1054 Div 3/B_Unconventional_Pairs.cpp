#include <iostream>
#include <vector>
#include <algorithm>

auto process(::std::vector<int>& v) -> int
{
	int res{ INT_MIN };
	if(v.size() == 2){
		return(abs(v[0] - v[1]));
	}
	::std::sort(v.begin(), v.end());
	for(size_t i{ 0 }; i < v.size(); i = i + 2){
		res = ::std::max(res, abs(v[i] - v[i + 1]));
	}
	return(res);
}

auto main() -> int
{
	int t;
	::std::cin >> t;
	for(int i{ 0 }; i < t; ++i){
		int n;
		::std::cin >> n;
		::std::vector<int> v(n);
		for(int j{ 0 }; j < n; ++j){
			::std::cin >> v[j];
		}
		::std::cout << process(v) << "\n";
	}

	return(0);
}