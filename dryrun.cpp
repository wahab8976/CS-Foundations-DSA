#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> seg;
    vector<int> lazy;
    int n;

public:
    SegmentTree(int n) {
        this->n = n;
        this->seg.assign(4 * n, 0);
        this->lazy.assign(4 * n, 0); // Prepared for lazy propagation later!
    }

    void build(int index, int low, int high, const vector<int>& arr) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        // seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }
    
    int queryMax(int index, int low, int high, int a, int b) {
        // No Overlap
        if (b < low || a > high) return INT_MIN;
        
        // Complete Overlap (node range [low, high] is inside query range [a, b])
        if (a <= low && high <= b) return seg[index];
        
        // Partial Overlap
        int mid = (low + high) / 2;
        // FIXED: Catching the returned values from children
        int left = queryMax(2 * index + 1, low, mid, a, b);
        int right = queryMax(2 * index + 2, mid + 1, high, a, b);
        
        // return max(left, right);
        return left + right;
    }
    
    void pointUpdates(int pos, int val, int low, int high, int index) {
        if (low == high) {
            seg[index] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        if (pos <= mid) pointUpdates(pos, val, low, mid, 2 * index + 1);
        else pointUpdates(pos, val, mid + 1, high, 2 * index + 2);
        
        // seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    void rangeUpdate(int index, int low, int high, int a, int b, int val) {
        // Check for any pending lazy updates and apply them
        if(lazy[index] != 0){
            int valsToUpdate = high - low + 1;
            // Add value to current node
            seg[index] += valsToUpdate * lazy[index];

            
            if(low != high){
                // Pass lazy values to lazy children, if not a leaf node
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;    // Reset Lazy node
        }

        // No Overlap
        if(b < low && a > high) return;

        // Complete Overlap
        if(low >= a && high >= b) {
            seg[index] += (high - low + 1) * val;

            if(low != high){
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] = val;
            }
        }
        return;

        // Partial Overalap
        int mid = (low + high) / 2;
        if(val <= mid){
            rangeUpdate(2* index + 1, low, mid, a, b, val);
        }else{
            rangeUpdate(2* index + 2, mid + 1, high, a, b, val);
        }
        
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }


};

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    vector<int> arr = {1, 3, 2, 5, 4};
    int n = arr.size();
    
    SegmentTree st(n);
    st.build(0, 0, n - 1, arr);

    // Max in range [1, 3] -> elements: 3, 2, 5 -> Output: 5
    cout << "Max in range [1, 3]: " << st.queryMax(0, 0, n - 1, 1, 3) << "\n"; 
    
    st.pointUpdates(2, 6, 0, n - 1, 0); // Update index 2 to value 6 -> array becomes {1, 3, 6, 5, 4}
    
    // Max in range [1, 3] -> elements: 3, 6, 5 -> Output: 6
    cout << "Max in range [1, 3] after update: " << st.queryMax(0, 0, n - 1, 1, 3) << "\n"; 
    
    return 0;
}