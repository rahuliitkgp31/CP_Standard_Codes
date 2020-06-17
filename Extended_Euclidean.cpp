// a*x + b*y = gcd(a, b)

// following function gives one value of (x, y) that satisfy above equation

// if you put b = M and if gcd(a, M)==1 the x value of output of following function
// is multiplicative modular inverse of a wrt M

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x, y;

void extendedEuclidean(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	extendedEuclidean(b, a % b);
	ll tempX = x;
	ll tempY = y;
	x = tempY;
	y = tempX - (a / b) * tempY;
}

int main() {
	ll a, b;
	cin >> a >> b;
	extendedEuclidean(a, b);
	cout << x << " " << y << endl;
	return 0;
}