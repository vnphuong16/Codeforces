//  A. Be Positive

#include<iostream>
#include<vector>

using namespace std;

auto main() -> int
{
	int t;
	::std::cin >> t;

	for(int i{ 0 }; i < t; ++i){
		int n;
		int count0{ 0 };
		int countNegative1{ 0 };

		::std::cin >> n;
		::std::vector<int> v(n);
		for(int j{ 0 }; j < n; ++j){
			::std::cin >> v[j];
			if(v[j] == 0) ++count0;
			if(v[j] == -1) ++countNegative1;
		}

		::std::cout << (count0) + ((countNegative1 % 2) * 2) << "\n";
	}

	return(0);
}
