#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<int, int> where;
  for (int i = 0; i < n; i++)
    where[a[i]] = i;
  sort(a.begin(), a.end(), greater<>());
  cout << ++where[a[1]] << endl;
}
