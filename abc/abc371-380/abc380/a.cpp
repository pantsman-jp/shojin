#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> count(10, 0);
  while (n > 0)
  {
    ++count[n % 10];
    n /= 10;
  }
  if (count[1] == 1 and count[2] == 2 and count[3] == 3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
