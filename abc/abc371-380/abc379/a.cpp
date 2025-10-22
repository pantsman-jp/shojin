#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> abc;
  while (n > 0)
  {
    abc.insert(abc.begin(), n % 10);
    n /= 10;
  }
  int bca = abc[1] * 100 + abc[2] * 10 + abc[0];
  int cab = abc[2] * 100 + abc[0] * 10 + abc[1];
  cout << bca << ' ' << cab << endl;
}
