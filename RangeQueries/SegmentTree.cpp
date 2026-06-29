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

        // Complete Overlap.
        // Data user ki range andar hona chahiye. Complete  Overlap k liye
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

    void pointsUpdate(){

    }
};


/*
    This is a simpler version of the Segment Tree that supports point updates and range queries.
    It does not include lazy propagation, making it less efficient for range updates but simpler to understand and implement.
*/

class SegmentTreeSimple {
private:
    vector<int> seg;
    int n;

    // Build the tree
    void buildTree(int low, int high, const vector<int>& arr, int index) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        buildTree(low, mid, arr, index * 2 + 1);
        buildTree(mid + 1, high, arr, index * 2 + 2);

        seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
    }

    // Update Points
    void updatePointsInternal(int pos, int val, int low, int high, int index) {
        if (low == high) {
            seg[index] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (pos <= mid) {
            updatePointsInternal(pos, val, low, mid, index * 2 + 1);
        } else {
            updatePointsInternal(pos, val, mid + 1, high, index * 2 + 2);
        }
        seg[index] = min(seg[index * 2 + 1], seg[index * 2 + 2]);
    }

public: 
    // Constructor
    SegmentTreeSimple(int size) {
        n = size;
        seg.assign(4 * n, 0);
    }

    // Public Wrapper for build
    void build(const vector<int>& arr) {
        buildTree(0, n - 1, arr, 0);
    }

    // Public Wrapper for query 
    void update(int pos, int val) {
        updatePointsInternal(pos, val, 0, n - 1, 0);
    }
};