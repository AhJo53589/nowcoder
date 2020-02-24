# `（简单）` [202002241800.jiugongge-input-method 九宫格输入法](https://www.cnblogs.com/xyqxyq/p/10451433.html)

### 题目描述
假设有九宫格输入法键盘布局如下：

```
 [ 1,.?! ] [ 2ABC ] [ 3DEF  ]

 [ 4GHI  ] [ 5JKL ] [ 6MNO  ]

 [ 7PQRS ] [ 8TUV ] [ 9WXYZ ]

           [ 0空  ]
```

注意：中括号`[ ]`仅为了表示键盘的分隔，不是输入字符。每个中括号中，位于首位的数字字符即是键盘的按键，按一下即可输入该数字字符。多次按同一个键，则输入的字符依次循环轮流，例如按两次`3`，则输入`D`；按5次`7`，则输入`S`；按6次`2`，则输入`A`。按键`0`的输入组合是`0`和`空格`字符，即按两次`0`输入空格。

你需要对于给定的按键组合，给出该组合对应的文本。

### 输入格式:

输入在一行中给出数个字符的按键组合（例如 `999` 表示按3次`9`），每个字符的按键组合之间用空格间隔，最后一个输入法组合之后以换行结束。输入数据至少包括一个字符的按键组合，且输入总长度不超过500个字符。

### 输出格式:

在一行中输出该按键组合对应的文本。

### 输入样例:

```
22 5555 22 666 00 88 888 7777 4444 666 44
```

### 输出样例:

```
ALAN TURING
```



---
### 思路
```

```



### 答题
``` C++
string run(string& input)
{
	vector<string> keyboard = { "0 ", "1,.?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ" };

	string ans = "";
	stringstream ss(input);
	string letter;
	while (ss >> letter)
	{
		string key = keyboard[letter[0] - '0'];
		char c = key[(letter.size() - 1) % key.size()];
		ans += c;
	}
	return ans;
}
```




