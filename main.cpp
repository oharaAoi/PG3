#include <stdio.h>
#include <iostream>
#include <thread>

void ShowThreadId(int num) {
	std::cout << "thread " << num << std::endl;
}

int main() {

	std::thread thread1(ShowThreadId, 1);
	thread1.join();
	std::thread thread2(ShowThreadId, 2);
	thread2.join();
	std::thread thread3(ShowThreadId, 3);
	thread3.join();
	
	return 0;
}