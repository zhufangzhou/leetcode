#include <iostream>

class Solution {
public:
    string intToRoman(int num) {
		// Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
		string ret = "";
		int base[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string letter[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		
		for (int i = 0; i < num/1000; i++) ret += "M";
		num = num % 1000;
		for (int i = 1; i < 13; i++) {
			while (num >= base[i]) {
				ret += letter[i];
				num -= base[i];
			}
		}
		return ret;
    }
};
