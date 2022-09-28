#include <iostream>
#include <vector>

using namespace std;

int power (int a, int n) {
    if(n == 0)
        return 1;
    // else
    if(n % 2 == 0) {
        int temp = power(a, n / 2);
        return temp * temp;
    }
    // else
    return a * power(a, n - 1);
}

int solve(int x, const vector<int> &powers, int index) {
    if(index == 0) {
        return (x == 1) ? 1 : 0;
    }
    // else
    if(x == powers[index])
        return 1 + solve(x, powers, index - 1);
    // else
    int res = 0;
    res += solve(x - powers[index], powers, index - 1);
    res += solve(x, powers, index - 1);
    return res;
}


int main() {
    int x, n;
    cin >> x >> n;
    
    int pow = 1;
    vector<int> powers;
    for(int a = 2; pow <= x; a++) {
        powers.push_back(pow);
        pow = power(a, n);
    }
    
    cout << solve(x, powers, powers.size() - 1) << endl;        
    return 0;
}
