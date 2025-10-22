#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

bool judge(int n)
{
  vector<int> digit(3);
  for (int i = 2; -1 < i; i--)
  {
    digit[i] = n % 10;
    n /= 10;
  }
  return digit[0] * digit[1] == digit[2];
}

int main()
{
  int n;
  cin >> n;
  for (int m = n; m < 920; m++)
  {
    if (judge(m))
    {
      cout << m << endl;
      return 0;
    }
  }
}
