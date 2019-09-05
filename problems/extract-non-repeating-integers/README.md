# [提取不重复的整数](https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking)

### 题目描述
<div class="js-question-content" style="margin-bottom:10px;"><p>输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。</p></div>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输入描述:</h2>
<pre><p>输入一个int型整数</p></pre>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输出描述:</h2>
<pre><p>按照从右向左的阅读顺序，返回一个不含重复数字的新的整数</p></pre>
<!-- <br/>
<h5 style="font-size:14px;font-weight:bold;">输入例子:</h5>
<pre>9876673</pre>
<br/>
<h5 style="font-size:14px;font-weight:bold;">输出例子:</h5>
<pre>37689</pre>
 -->
<div class="question-oi">
<div class="question-oi-hd">
示例1
</div>
<div class="question-oi-bd">
<div class="question-oi-mod">
<h2>输入</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text="9876673">复制</a>
<div class="question-oi-cont">
<pre>9876673</pre>
</div>
</div>
<div class="question-oi-mod">
<h2>输出</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text="37689">复制</a>
<div class="question-oi-cont">
<pre>37689</pre>
</div>
</div>
</div>
</div>


---
### 思路
```
```

### 答题
``` C++
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
```

