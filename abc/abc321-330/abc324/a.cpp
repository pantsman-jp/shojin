#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  set<int> item;
  rep(_, n)
  {
    int a;
    cin >> a;
    item.insert(a);
  }
  if (item.size() == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
