#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
 		int n = nums.size();       
		vector<vector<int> > ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n-2; i++) {
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int j = i+1, k = n-1;
			while (j < k) {
				int temp_sum = nums[i] + nums[j] + nums[k]; 
				if (temp_sum == 0) {
					addItem(ret, nums[i], nums[j], nums[k]);
				}
				if (temp_sum >= 0) {
					int last_val = nums[k];
					while (nums[k] == last_val) k--;
				} else {
					int last_val = nums[j];
					while (nums[j] == last_val) j++;
				}
			}
		}
		return ret;
    }

	void addItem(vector<vector<int> > &ret, int a, int b, int c) {
		vector<int> temp;
		temp.push_back(a); temp.push_back(b); temp.push_back(c);
		sort(temp.begin(), temp.end());
		ret.push_back(temp);
	}
};

int main() {
	Solution s;
	vector<int> a{-1,0,1,2,-1,-4};
	s.threeSum(a);
	return 0;
}
