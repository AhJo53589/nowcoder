# `（简单）` [202002221600.circle-count 围圈报数](https://www.nowcoder.com/practice/b033062d346c4e42a7191b94164c1cd7?tpId=94&&tqId=31045&rp=1&ru=/activity/oj&qru=/ta/bit-kaoyan/question-ranking)

### 题目描述

<div class="question-intr mt2 mb2">
<div class="subject-item-wrap">
<span>时间限制：C/C++ 1秒，其他语言2秒</span>
<span>空间限制：C/C++ 32M，其他语言64M</span>
<span>热度指数：3226</span>
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
<div class="js-question-content subject-question mb2"><span style="">N 个人围成一圈顺序编号，从1 号开始按1、2、3 顺序报数，报3 者退出圈外，其余的人再从1、2、3 开始报数，报3 的人再退出圈外，依次类推。请按退出顺序输出每个退出人的原序号。要求使用环行链表编程。</span></div>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输入描述:</h2>
<pre>输入第一行为整数m表示有m组测试数据，接下来m行每行一个整数N，N不超过50。</pre>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输出描述:</h2>
<pre>输出m行，每行表示题目所求，用空格隔开。</pre>
<!-- <br/>
<h5 style="font-size:14px;font-weight:bold;">输入例子:</h5>
<pre>1
4</pre>
<br/>
<h5 style="font-size:14px;font-weight:bold;">输出例子:</h5>
<pre>3 2 4 1</pre>
 -->
<div class="question-oi">
<div class="question-oi-hd">
示例1
</div>
<div class="question-oi-bd">
<div class="question-oi-mod">
<h2>输入</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="input1">复制</a>
<textarea data-clipboard-text-id="input1" style="display:none;">1
4</textarea>
<div class="question-oi-cont">
<pre>1
4</pre>
</div>
</div>
<div class="question-oi-mod">
<h2>输出</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="output1">复制</a>
<textarea data-clipboard-text-id="output1" style="display:none;">3 2 4 1</textarea>
<div class="question-oi-cont">
<pre>3 2 4 1</pre>
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
vector<int> game(int n, int k = 3)
{
	ListNode* dummy = new ListNode(0);
	ListNode* cur = dummy;
	for (int i = 0; i < n; i++)
	{
		cur->next = new ListNode(i + 1);
		cur = cur->next;
	}
	cur->next = dummy->next;
	delete dummy;

	vector<int> ans;
	int t = 0;
	while (cur->next != cur)
	{
		t = (t + 1) % k;
		if (t == 0)
		{
			ListNode* p = cur->next;
			ans.push_back(p->val);
			cur->next = p->next;
			delete p;
		}
		else
		{
			cur = cur->next;
		}
	}
	ans.push_back(cur->val);
	delete cur;

	return ans;
}
```




