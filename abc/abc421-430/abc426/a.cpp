#include <bits/stdc++.h>
using namespace std;

int main()
{
  string x, y;
  cin >> x >> y;
  vector<string> os = {"Ocelot", "Serval", "Lynx"};
  auto ix = find(os.begin(), os.end(), x) - os.begin();
  auto iy = find(os.begin(), os.end(), y) - os.begin();
  if (ix >= iy)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
