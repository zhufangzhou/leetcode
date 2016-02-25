#include <iostream>

class Solution {
public:
    struct node {
        int id;
        long long val;
        node (int id, long long val) : id(id), val(val) {

        }
        bool operator < (const struct node &a) const {
            return val < a.val;
        }
    };
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<node> v;
        int n = nums.size();

        for (int i = 0; i < n; i++) v.push_back(node(i, nums[i]));
        sort(v.begin(), v.end());

        for (int i = 0; i < n-1; i++) {
            int j = i+1;
            while (j < n && v[j].val - v[i].val <= t) {
                if (abs(v[j].id - v[i].id) <= k) {
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};
