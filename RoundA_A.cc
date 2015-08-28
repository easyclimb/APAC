#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define _TEST_

int solve(int k, long long len) {
    if(k == len/2) return 0;
    else if(k < len/2) return solve(k, len/2);
    else return 1 - solve(len - 2 - k, len/2);
}

int main()
{
    #ifdef _TEST_
    freopen("A-small-practice.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    int k;
    long long len = 1;
    for(int i = 0; i < 60; i++)
        len = 2*len;
    for(int i = 1; i <= T; i++) {
        cin >> k;
        printf("Case #%d: %d\n", i, solve(k, len));
    }
    return 0;
}
