#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int f(int x)
{
  int sum = 0;
  while (x > 0)
    sum += x % 10, x /= 10;
  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> A(n + 1);
  A[0] = 1;
  for (int i = 1; i < n + 1; i++)
  {
    int sum = 0;
    for (int j = 0; j < i; j++)
      sum += f(A[j]);
    A[i] = sum;
  }
  cout << A[n] << endl;
}