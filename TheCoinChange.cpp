#include<bits/stdc++.h>
#define endl \n
using namespace std;

int main() {
    // Read input
    int N, M;
    cin>>N;
    cin>>M;
    int *coin = new int[M];
    long *change = new long[N+1];
    for(int i = 0; i < M; i++) {
        cin>>coin[i];
    }

    // Initialize change (change[i] = numbers of way to make i change) to zero
    memset(change, 0, sizeof(change));

    // Base case: There is 1 way to make change for zero cents, use no coins
    change[0] = 1;
    for(int i = 0; i < M; i++) {
        for(int j = coin[i]; j <= N; j++) {
            change[j] += change[j-coin[i]];
        }
    }
    
    // Print solution
    cout<<change[N];
    return 0;
}
