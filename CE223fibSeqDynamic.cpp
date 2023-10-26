// 9/4/23

//Fibonacci Sequence
//Dynamic Algorithm

//g++ --std=c++11 CE223fibSeqDynamic.cpp
// ./a.out

#include <chrono>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;
using namespace std::chrono;

unsigned long int fib_dyn(int n){
    unsigned long int f[n]; int i;
    f[0] = 0; f[1] = 1;

    for (i = 2; i <= n; i ++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// MORE EFFICIENT FUNCTION
unsigned long int space_optimized(int n){
  unsigned long int a, b, c; int i;
  a = 0; b = 1; 
  
  for (i=2; i <= n; i ++){
    c = a + b;
    a = b; b = c;
  }
  return c;
}

int main() {
  int n = 80;

  auto s1 = high_resolution_clock::now();
  //cout << fib_dyn(n) << endl;
  cout << space_optimized(n) << endl;
  auto e1 = high_resolution_clock::now();
  auto d1 = duration_cast<nanoseconds>(e1 - s1);

  cout << d1.count() << "ns" << endl;
  return 0;
}