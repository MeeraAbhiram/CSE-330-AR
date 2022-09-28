#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdint.h>

using namespace std;

static uint32_t cache[302];

static uint32_t grundy(uint32_t cnt) {
  uint64_t gr;
  uint32_t i, gx;
  if (cache[cnt]!=UINT32_MAX)
    return cache[cnt];
  gr=0;
  for (i=1; i<cnt; i++) {
    gx=grundy(i-1)^grundy(cnt-i);
    gr|=1<<gx;
  }
  for (i=2; i<cnt; i++) {
    gx=grundy(i-2)^grundy(cnt-i);
    gr|=1<<gx;
  }
  for (i=0; i<64; i++)
    if ((gr&(1<<i))==0)
      break;
  cache[cnt]=i;
  return i;
}

char str[308];

int main() {
  uint32_t t, gx, c, i, l;
  memset(cache, 0xff, sizeof(cache));
  cache[0]=0;
  cache[1]=1;
  cache[2]=2;
  cin >> t;
  while (t--) {
    cin >> l >> str;
    gx=0;
    c=0;
    for (i=0; i<l; i++)
      if (str[i]=='I') {
        c++;
      } else {
        gx^=grundy(c);
        c=0;
      }
    gx^=grundy(c);
    if (gx)
      cout << "WIN" << endl;
    else
      cout << "LOSE" << endl;
  }
  return 0;
}
