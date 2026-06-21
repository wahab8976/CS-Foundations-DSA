#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> countingSortImmutable(const vector<int>& arr) {
    if (arr.empty()) return {};

    int n = arr.size();
    int minVal = arr[0];
    int maxVal = arr[0];
    
    for (int num : arr) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    int range = maxVal - minVal + 1;

    // Populate frequencies with offset shifts
    vector<int> freq(range, 0);
    for (int num : arr) freq[num - minVal]++;

    // Build cumulative/prefix sums to determine exact index positions
    for (int i = 1; i < range; i++) freq[i] += freq[i - 1];

    // Build the output array backwards to preserve stability
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        int currentElement = arr[i];
        int freqIdx = currentElement - minVal;
        
        // Place item in its correct position and decrement the placement counter
        output[freq[freqIdx] - 1] = currentElement;
        freq[freqIdx]--;
    }

    return output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> originalArr = {4, -2, 2, 8, -2, 3, 1, 0};

    // Generate a completely separate sorted array
    vector<int> sortedArr = countingSortImmutable(originalArr);

    cout << "Original Array: ";
    for (int num : originalArr) cout << num << " ";
    cout << "\n";

    cout << "Sorted Array:   ";
    for (int num : sortedArr) cout << num << " ";
    cout << "\n";

    return 0;
}