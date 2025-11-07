#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int diff = 0;
  rep(i, 5)
  {
    int a;
    cin >> a;
    diff += abs(a - (i + 1));
  }
  if (diff == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
