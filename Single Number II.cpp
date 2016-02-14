class Solution {
public:
    int singleNumber(vector<int>& nums) {
 		int digit, ret = 0;	       
		for (int j = 0; j < 32; j++) {
			digit = 0;
			for (int i = 0; i < nums.size(); i++) {
				digit += nums[i] & 0x01;
				nums[i] >>= 1;
			}
			digit %= 3;
			ret += (digit << j);
		}
		return ret;
    }
};
