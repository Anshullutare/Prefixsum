#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> nums(N), prefix(N);
    
    // Input array elements and compute prefix sum
    for (int i = 0; i < N; i++) {
        cin >> nums[i];

        // Replacing the previous complex line with a simple if-else
        if (i == 0)
            prefix[i] = nums[i];  // First element is the same as nums[i]
        else
            prefix[i] = nums[i] + prefix[i - 1];  // Add current number to previous sum
    }

    // Input number of queries
    int Q;
    cin >> Q;

    while (Q--) {
        int L, R;
        cin >> L >> R;

        // Compute range sum using prefix sum array
        long long sum = prefix[R] - (L > 0 ? prefix[L - 1] : 0);
        
        cout << sum << endl;
    }

    return 0;
}
