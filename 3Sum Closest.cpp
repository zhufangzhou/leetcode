#include <iostream>
#include <algorithm>
#include <cstdlib>

// Work version, but not good !!!
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		vector<int> cand;
		sort(nums.begin(), nums.end());
		int min_val = 999999, ret, n = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i+1; j < nums.size(); j++) {
				int temp_sum = nums[i] + nums[j];
				int cand_idx;
				if (target - temp_sum < nums[0]) {
					cand_idx = 0;
					while (cand_idx == i || cand_idx == j) cand_idx++;
					if (fabs(target - temp_sum - nums[cand_idx]) < min_val) {
						min_val = fabs(target - temp_sum - nums[cand_idx]);
						ret = temp_sum + nums[cand_idx];
					}
				} else if (target - temp_sum > nums[n-1]) {
					cand_idx = n-1;
					while (cand_idx == i || cand_idx == j) cand_idx--;
					if (fabs(target - temp_sum - nums[cand_idx]) < min_val) {
						min_val = fabs(target - temp_sum - nums[cand_idx]);
						ret = temp_sum + nums[cand_idx];
					}
				} else {
					cand_idx = binary_search(nums, target - temp_sum);
					int left = cand_idx-1, right = cand_idx;
					while (left >= 0 && (left == i || left == j)) left--;
					while (right < n && (right == i || right == j)) right++;

					if (left >= 0 && fabs(target - temp_sum - nums[left]) < min_val) {
						min_val = fabs(target - temp_sum - nums[left]);
						ret = temp_sum + nums[left];
					}
					if (right < n && fabs(target - temp_sum - nums[right]) < min_val) {
						min_val = fabs(target - temp_sum - nums[right]);
						ret = temp_sum + nums[right];
					}

				}
			}
		}
		return ret;
    }

	int binary_search(vector<int>& nums, int target) {
		int left = 0, right = nums.size()-1, mid;

		while (left+1 < right) {
			mid = (left + right) / 2;
			if (nums[mid] <= target) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return right;
	}
};
*/

// Better !!!!!!
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size(), min_val = 99999, ret;
		sort(nums.begin(), nums.end());
 		for (int i = 0; i < n-2; i++) {
			int j = i + 1, k = n - 1;
			while (j < k) {
				int temp_sum = nums[i] + nums[j] + nums[k];
				if (fabs(target - temp_sum) < min_val) {
					min_val = fabs(target - temp_sum);
					ret = temp_sum;
				}
				if (temp_sum <= target) {
					j++;
				} else {
					k--;
				}
			}
		}
		return ret;
    }
};
