# `（中等）` [202002221800.task-scheduling 任务调度 ](https://www.nowcoder.com/practice/88d5fa34fe0748e09062e48c6ae6ffc7?tpId=40&&tqId=31018&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking)

### 题目描述

<div class="question-intr mt2 mb2">
<div class="subject-item-wrap">
<span>时间限制：C/C++ 1秒，其他语言2秒</span>
<span>空间限制：C/C++ 32M，其他语言64M</span>
<span>热度指数：365</span>
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
<div class="js-question-content subject-question mb2"><span style="">读入任务调度序列，输出n个任务适合的一种调度方式。</span></div>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输入描述:</h2>
<pre>输入包含多组测试数据。<br><br>每组第一行输入一个整数n（n&lt;100000），表示有n个任务。<br><br>接下来n行，每行第一个表示前序任务，括号中的任务为若干个后序任务，表示只有在前序任务完成的情况下，后序任务才能开始。若后序为NULL则表示无后继任务。</pre>
<h2 style="font-size:14px;font-weight:bold;color:#34495e;">输出描述:</h2>
<pre>输出调度方式，输出如果有多种适合的调度方式，请输出字典序最小的一种。</pre>
<!-- <br/>
<h5 style="font-size:14px;font-weight:bold;">输入例子:</h5>
<pre>4
Task0(Task1,Task2)
Task1(Task3)
Task2(NULL)
Task3(NULL)</pre>
<br/>
<h5 style="font-size:14px;font-weight:bold;">输出例子:</h5>
<pre>Task0 Task1 Task2 Task3</pre>
 -->
<div class="question-oi">
<div class="question-oi-hd">
示例1
</div>
<div class="question-oi-bd">
<div class="question-oi-mod">
<h2>输入</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="input1">复制</a>
<textarea data-clipboard-text-id="input1" style="display:none;">4
Task0(Task1,Task2)
Task1(Task3)
Task2(NULL)
Task3(NULL)</textarea>
<div class="question-oi-cont">
<pre>4
Task0(Task1,Task2)
Task1(Task3)
Task2(NULL)
Task3(NULL)</pre>
</div>
</div>
<div class="question-oi-mod">
<h2>输出</h2>
<a class="code-copy-btn" href="javascript:void(0);" data-clipboard-text-id="output1">复制</a>
<textarea data-clipboard-text-id="output1" style="display:none;">Task0 Task1 Task2 Task3</textarea>
<div class="question-oi-cont">
<pre>Task0 Task1 Task2 Task3</pre>
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
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include <sstream>

using namespace std;

vector<string> runTask(map<string, int>& inDegree, map<string, vector<string>>& lst)
{
    queue<string> que;
    for (auto i : inDegree)
    {
        if (i.second == 0) que.push(i.first);	// 将入度为 0 的结点放入队列
    }

    vector<string> ans;
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        ans.push_back(q);

        for (auto l : lst[q])
        {
            if (--inDegree[l] == 0) que.push(l);
        }
    }

    return ans;
}

int main()
{
    map<string, int> inDegree;
    map<string, vector<string>> lst;
    stringstream tss;
    
    int n = 0;
    cin >> n;
    while (n-- != 0)
    {
        string str;
        cin >> str;
        str = str.replace(str.find("("), 1, " ");
        str = str.replace(str.find(")"), 1, " ");
        while (str.find(",") != string::npos)
        {
            str = str.replace(str.find(","), 1, " ");
        }
        
        tss.clear();
        tss << str;
        string sName;
        tss >> sName;
        inDegree[sName] = 0;
        while (tss >> str)
        {
            if (str == "NULL") break;
            inDegree[str]++;
            lst[str].push_back(sName);
        }
    }

    auto ans = runTask(inDegree, lst);
    for (auto& w : ans) cout << w << " ";
    cout << endl;
    return {};
}
```




