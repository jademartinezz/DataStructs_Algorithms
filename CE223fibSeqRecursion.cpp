// 9/1/23

//Fibonacci Sequence
//Recursive Algorithm

//g++ --std=c++11 CE223fibSeqRecursion.cpp
// ./a.out

#include <chrono>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;
using namespace std::chrono;

unsigned long long int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int n = 42;

  auto s1 = high_resolution_clock::now();
  cout << fib(n) << endl;
  auto e1 = high_resolution_clock::now();
  auto d1 = duration_cast<microseconds>(e1 - s1);

  cout << d1.count() << "us" << endl;
  return 0;
}
