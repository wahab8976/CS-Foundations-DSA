#include "bits/stdc++.h"

class SegmentTree {
private:
    vector<int> seg;
    vector<int> lazy; 
    int n;

public:
    SegmentTree(int size) {
        n = size;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Build the tree
    void build(int low, int high, const vector<int>& arr, int index) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(low, mid, arr, index * 2 + 1);
        build(mid + 1, high, arr, index * 2 + 2);

        seg[index] = seg[index * 2 + 1] + seg[index * 2 + 2];
    }

    // LazyPropagation: Range Queries
    int query(int userQueryLeft, int userQueryRight, int low, int high, int index) {
        // Resolve any pending lazy values before processing this node
        if (lazy[index] != 0) {
            seg[index] += (high - low + 1) * lazy[index]; // Propagate change up to current range capacity
            
            if (low != high) { // If not a leaf node, pass lazy value down to children
                lazy[index * 2 + 1] += lazy[index];
                lazy[index * 2 + 2] += lazy[index];
            }
            lazy[index] = 0; // Reset lazy marker for current node
        }

        // No Overlap
        if (userQueryRight < low || userQueryLeft > high) 
            return 0;

        // Complete Overlap
        if (userQueryLeft <= low && high <= userQueryRight) 
            return seg[index];

        // Partial Overlap
        int mid = (low + high) / 2;
        int leftChildAns = query(userQueryLeft, userQueryRight, low, mid, index * 2 + 1);
        int rightChildAns = query(userQueryLeft, userQueryRight, mid + 1, high, index * 2 + 2);

        return leftChildAns + rightChildAns;
    }

    // Lazy Propagation: Range Updates (Increments range [valLeft, valRight] by 'val')
    void updateRange(int valLeft, int valRight, int val, int low, int high, int index) {
        // Resolve any pending lazy updates first
        if (lazy[index] != 0) {
            seg[index] += (high - low + 1) * lazy[index];
            if (low != high) {
                lazy[index * 2 + 1] += lazy[index];
                lazy[index * 2 + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // No Overlap boundary check
        if (valRight < low || valLeft > high) 
            return;

        // Complete Overlap: Update current node and mark children as lazy
        if (valLeft <= low && high <= valRight) {
            seg[index] += (high - low + 1) * val;
            if (low != high) {
                lazy[index * 2 + 1] += val;
                lazy[index * 2 + 2] += val;
            }
            return;
        }

        // Partial Overlap
        int mid = (low + high) / 2;
        updateRange(valLeft, valRight, val, low, mid, index * 2 + 1);
        updateRange(valLeft, valRight, val, mid + 1, high, index * 2 + 2);

        // Merge up the tree hierarchy
        seg[index] = seg[index * 2 + 1] + seg[index * 2 + 2];
    }
};