#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
  freopen("mowing.in","r",stdin);
  freopen("mowing.out","w",stdout);
  int n; cin>>n;
  vector<vector<int>> lastVisited;
  for (int i=0; i<10000; i++) {
    vector<int> row(10000, -1);
    lastVisited.push_back(row);
  }
  int currx=5000; int curry=5000;
  lastVisited[currx][curry]=0;
  int currtime=0;
  int ans=99999999;
  for (int i=0; i<n; i++) {
    char c; cin>>c;
    int x; cin>>x;
    int dx=0; int dy=0;
    if (c=='N') {
      dy=1;
    }
    if (c=='S') {
      dy=-1;
    }
    if (c=='E') {
      dx=1;
    }
    if (c=='W') {
      dx=-1;
    }
    int counter=1;
    while (counter<=x) {
      currtime++;
      currx+=dx;
      curry+=dy;
      if (lastVisited[currx][curry]>=0) {
        ans=min(ans, currtime-lastVisited[currx][curry]);
      }
      lastVisited[currx][curry]=currtime;
      counter++;
    }
  }
  if (ans==99999999) {
    cout<<-1;
    return 0;
  }
  //cout<<ans<<endl;
  printf("%d\n", ans);
}