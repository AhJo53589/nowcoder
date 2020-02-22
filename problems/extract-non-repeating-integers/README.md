# `（简单）` [202002221700.extract-non-repeating-integers 提取不重复的整数 ](https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking)

### 题目描述

<div class="question-intr mt2 mb2">
<div class="subject-item-wrap">
<span>时间限制：C/C++ 1秒，其他语言2秒</span>
<span>空间限制：C/C++ 32M，其他语言64M</span>
<span>热度指数：155197</span>
</div>
<a target="_blank" href="/courses/semester/2018algorithm-higher" class="link-green video-explain">
<i class="fui-video"></i>
算法知识视频讲解
</a>
</div>
<div class="nk-warning js-nk-warning" style="">
校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
</div>
<h2 class="subject-item-title">题目描述</h2>
<div class="subject-describe">
<div class="js-question-content subject-question mb2"><p>输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。</p></div>
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
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="input1">复制</a>
<textarea data-clipboard-text-id="input1" style="display:none;">9876673</textarea>
<div class="question-oi-cont">
<pre>9876673</pre>
</div>
</div>
<div class="question-oi-mod">
<h2>输出</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="output1">复制</a>
<textarea data-clipboard-text-id="output1" style="display:none;">37689</textarea>
<div class="question-oi-cont">
<pre>37689</pre>
</div>
</div>
</div>
</div>
</div>
<ul class="oprt-tool clearfix" style="width: 864px;">
<li><a href="javascript:void(0);" class="oprt-item icon-notes js-add-note nc-req-auth">笔记</a></li>
<li><a href="javascript:void(0);" data-id="23296" class="oprt-item oprt-collect js-click-follow nc-req-auth">收藏</a></li>
<li><a href="javascript:void(0);" class="oprt-item oprt-error click-correction">纠错</a></li>
</ul>


---
### 思路
```
```



### 答题
``` C++
int calc(int n)
{
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

	return b ? ans : -ans;
}
```




