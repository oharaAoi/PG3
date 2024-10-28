#include <stdio.h>
#include <iostream>
#include <format>
#include <string>
#include <type_traits>

template <typename TypeA, typename TypeB>
class MinMax {
private:

	TypeA typeA_;
	TypeB typeB_;

public:

	MinMax(TypeA a, TypeB b) : typeA_(a), typeB_(b) {};

	auto Compare() -> decltype((typeA_ < typeB_) ? typeA_ : typeB_) {
		if (typeA_ < typeB_) {
			return typeA_;  // typeAの値を返す
		} else {
			return typeB_;  // typeBの値を返す
		}
	}
};

int main() {
	
	MinMax<int, int> result1(1, 2);
	std::cout << result1.Compare() << std::endl;

	MinMax<float, float> result2(2.5f, 3.5f);
	std::cout << result2.Compare() << std::endl;

	MinMax<double, double> result3(3.5, 4.5);
	std::cout << result3.Compare() << std::endl;

	MinMax<int, float> result4(4, 5.5f);
	std::cout << result4.Compare() <<  std::endl;

	MinMax<int, double> result5(5, 6.5);
	std::cout << result5.Compare() << std::endl;

	MinMax<float, double> result6(6.5f, 7.5);
	std::cout << result6.Compare() << std::endl;

	return 0;
}