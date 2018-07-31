#include <iostream>
using namespace std;

void func(int a[], int length) {
	int *ptr = &a[0];
//	delete ptr;
//	ptr = nullptr;
}

int main() {
	int a[2] = {1, 2};
	func(a, 2);
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	return 0;
}
