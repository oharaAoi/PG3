#include <stdio.h>

template <typename TypeA, typename TypeB, typename TypeC>
class MinMax {
public:

	MinMax(TypeA a, TypeB b) : typeA_(a), typeB_(b) {};

	TypeC Compare() {
		if (typeA_ < typeB_) {
			return typeA_;
		} else {
			return typeB_;
		}
	}

private:

	TypeA typeA_;
	TypeB typeB_;

};

int main() {
	MinMax<float, double, int> result1(10.0f, 20);
	printf("%d\n", result1.Compare());
	MinMax<double, float, int> result2(20.0f, 30);
	printf("%d\n", result2.Compare());
	
	MinMax<int, float, double> result3(30, 40.0f);
	printf("%lf\n", result3.Compare());
	MinMax<float, int, double> result4(40.0f, 50.0);
	printf("%lf\n", result4.Compare());

	MinMax<double, int, float> result5(50.0, 60);
	printf("%f(f)\n", result5.Compare());
	MinMax<int, double, float> result6(60, 70.0);
	printf("%f(f)\n", result6.Compare());

	return 0;
}