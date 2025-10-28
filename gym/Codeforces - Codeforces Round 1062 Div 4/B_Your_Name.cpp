//  B. Your Name

#include <iostream>
#include <map>
#include <string>

auto solve() -> void
{
	int vN{0};
	::std::cin >> vN;
	::std::string vS{""}, vT{""};
	::std::cin >> vS >> vT;
	::std::map<char, int> vMapS{};
	::std::map<char, int> vMapT{};
	for(auto c : vS){ vMapS[c]++; }
	for(auto c : vT){ vMapT[c]++; }

	if(vMapS == vMapT){ ::std::cout << "YES\n"; }
	else{ ::std::cout << "NO\n"; }
}

auto main() -> int
{
	int vT{ 0 };
	::std::cin >> vT;
	while(vT--){
		solve();
	}
	return 0;
}