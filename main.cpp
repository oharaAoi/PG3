#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　関数群
//////////////////////////////////////////////////////////////////////////////////////////////////

// 一般的な賃金体系
int CaluclateSalary(const int& workTime, const int& salary) {
	return workTime * salary;
}

// 再帰的な賃金体系
int CaluclateRecursionSalary(const int& workTime, const int& salary) {
	if (workTime == 0) {
		return 0;
	} else {
		return salary + CaluclateRecursionSalary(workTime - 1, (salary * 2) - 50);
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　main関数
//////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int workTime = 8;
	int normal = CaluclateSalary(workTime, 1072);
	int recursion = CaluclateRecursionSalary(workTime, 100);
	printf("一般的給料 : %d\n", normal);
	printf("再帰的給料 : %d\n", recursion);
	if (normal < recursion) {
		printf("再帰的給料の方が高い");
	} else {
		printf("一般的給料の方が高い");
	}
	return 0;
}