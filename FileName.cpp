#include<iostream>
using namespace std;


int main() {
	cout.tie();
	cin.tie();
	ios::sync_with_stdio(0);
	long long int a, b, tmp = 0;

	cin >> a >> b;
	long long int bb = a * b;
	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	} // ū ���ڰ� a, ���� ���ڰ� b
	
	while (b!=0) {
		tmp = b;
		b= a % b;
		a = tmp;
	}
	cout << bb / a;


	return 0;
}
