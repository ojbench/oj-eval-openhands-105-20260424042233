
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 21;
double dp[MAX_N][MAX_N]; // dp[a][e]: expected days to eat e more apples with a apples left
bool visited[MAX_N][MAX_N];

double solve(int a, int e) {
    if (e == 0) {
        return 0.0; // No more apples to eat
    }
    if (a == 0) {
        return 0.0; // Can't eat more if no apples left (shouldn't happen if e>0, but return 0)
    }
    
    if (visited[a][e]) {
        return dp[a][e];
    }
    
    visited[a][e] = true;
    double res = 0.0;
    int max_eat = min(a, e);
    
    // We eat i apples (1 to max_eat) with probability 1/a each
    for (int i = 1; i <= max_eat; i++) {
        res += solve(a - i, e - i);
    }
    
    // Expected days = 1 (current day) + average of future days
    dp[a][e] = 1.0 + res / a;
    return dp[a][e];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Initialize visited array
    memset(visited, false, sizeof(visited));
    
    // We start with n apples and need to eat m apples
    double result = solve(n, m);
    
    // Output with 2 decimal places
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}
