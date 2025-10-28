//  A. Square?

#include <iostream>

auto Solve() -> void
{
	int vA{ 0 }, vB{ 0 }, vC{ 0 }, vD{ 0 };
	::std::cin >> vA >> vB >> vC >> vD;
	if(vA == vB && vA == vC && vA == vD){
		::std::cout << "YES\n";
	}else{
		::std::cout << "NO\n";
	}
}

auto main() -> int
{
	int vT{ 0 };
	::std::cin >> vT;
	while(vT--){
		Solve();
	}
	return 0;
}