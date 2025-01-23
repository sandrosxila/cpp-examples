#include <iostream>
#include <algorithm>
using namespace std;

long long power10(int n) {
  long long p = 1;
  for (int i = 0; i < n; ++i) p *= 10L;
  return p;
}

int num_size(int num) {
  int size = 0;
  for(;num > 0; num /= 10) size++;
  return size;
}

long long karatsuba(long long num1, long long num2) {
  if(num1 < 10 || num2 < 10) {
    return num1 * num2;
  }

  long long n = max(num_size(num1), num_size(num2));
  long long m = n / 2;

  long long p = power10(m);

  long long a = num1 / p;
  long long b = num1 % p;
  long long c = num2 / p;
  long long d = num2 % p;

  long long ac = karatsuba(a, c);
  long long bd = karatsuba(b, d);

  long long ad_bc = karatsuba(a + b, c + d) - ac - bd;
  
  long long p2 = p * p;

  return (ac * p2) + (ad_bc * p) + bd; 
}

int main() {
  long long x = 1234, y = 56789;
  cout << "karatsuba " << karatsuba(x, y) << endl;
  cout << "multiplication " << x * y << endl;
}