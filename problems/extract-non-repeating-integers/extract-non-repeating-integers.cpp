// extract-non-repeating-integers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	bool s[10] = { false };

	int ans = 0;
	bool b = (n > 0);
	while (n != 0)
	{
		int t = n % 10;
		n /= 10;
		if (s[t]) continue;
		s[t] = true;
		ans *= 10;
		ans += t;
	}
	ans = b ? ans : -ans;
	cout << ans << endl;
}