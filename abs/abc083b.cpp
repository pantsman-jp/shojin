#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int sum_of_digit(int n)
{
  int ans = 0;
  while (n > 0)
    ans += n % 10, n /= 10;
  return ans;
}

int main()
{
  int n, a, b, ans = 0;
  cin >> n >> a >> b;
  for (int i = 1; i < n + 1; i++)
  {
    int sum = sum_of_digit(i);
    if (a <= sum and sum <= b)
      ans += i;
  }
  cout << ans << endl;
}