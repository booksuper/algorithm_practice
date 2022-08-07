#include "str_algorithm.h"

set<string> findRepeatStr(char * s,const char * delimiter)
{
	set<string> res_str;
	vector<string> res_str_vec;
	//vector<string> repeat_vec;
	char *p;
	char* ptr = nullptr;//用来保存剩余字符串
	//strtok_s函数用于字符串分割，第一个参数是待分割字符串，第二个是用来分割的字符
	//第三个是用来保存分割后的剩余字符
	//这个函数strtok相比是线程安全的
	//返回的是第一个分割后的字符，并且将分节符的位置用空来代替
	p = strtok_s(s, delimiter, &ptr);
	//返回的字符不是空的时候就会一直循环
	while (p)
	{
		printf("%s\n", p);
		//分割出来的字符串放进res_str_vec
		res_str_vec.push_back(p);
		//继续分割，此时第一个参数设置为空，后面一样
		p = strtok_s(NULL, delimiter, &ptr);
	}
	//找到字符串中重复的字符串
	for (size_t i = 0; i < res_str_vec.size(); i++)
	{
		for (size_t j = i + 1; j < res_str_vec.size(); j++)
		{
			if (res_str_vec[i] == res_str_vec[j])
			{
				//使用set可以保证集合中不会有重复的元素
				res_str.insert(res_str_vec[i]);
				break;
			}
		}

	}
	return res_str;
}
//242简单 有效的字母异位词
bool isAnagram(string s, string t)
{
	if (s.length() != t.length()) return false;
	//记录字符出现的次数
	int record[26] = {};
	for (size_t i = 0; i < s.length(); i++)
	{
		//我们不需要知道s中具体的字符是多少，只需要求其与a相对的就行
		//如果字符是a，则其反映在record就是在索引0中加1
		record[s[i] - 'a'] += 1;
		//同样的道理，为了判断两个字符串是否异位，只需要使用t中的字符
		//对record数组减一就行，如果最后record元素都为0，则异位
		record[t[i] - 'a'] -= 1;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (record[i] != 0)
		{
			return false;
		}
			 
	}
	
	return true;

}
//383 简单 赎金信
bool canConstruct(string ransomNote, string magazine)
{
	//使用数组比哈希表更省时，因为不需要维护一个哈希表
	unordered_map<int, int> temp_map;//key是代表字符，0就是a，依次类推，value是字符出现的次数
	unordered_map<int, int> temp_map2;
	//将两个字符串的各字符个数分别记录在map中
	for (size_t i = 0; i < ransomNote.length(); i++)
	{
		temp_map[ransomNote[i] - 'a']++;
		//不使用insert,没法对相同元素加一
		//temp_map.insert(pair<int, int>(ransomNote[i] - 'a',i));
	}
	for (size_t i = 0; i < magazine.length(); i++)
	{
		temp_map2[magazine[i] - 'a']++;
	}
	//如果目标字符个数小于输入字符，直接false
	if (temp_map2.size() < temp_map.size())
	{
		return false;
	}
	else
	{
		for (auto var : temp_map)
		{
			auto temp = temp_map2.find(var.first);
			//首先看有没有这个字符，没有直接false
			if (temp == temp_map2.end())
			{
				return false;
				
			}
			//然后看这个字符的次数是不是小于输入字符的次数，小于直接false
			if (temp->second < var.second)
			{
				return false;
			}
		}
		return true;
	}


}
//20 简单 有效的括号
bool isValid(string s)
{
	/*这种匹配问题使用栈这种结构最合适
	先把待匹配的字符串依次压入，然后再依次对这些字符串进行判断*/
	stack<int> st;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') st.push(')');
		else if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		//判断。栈空之前能不能匹配上对应的字符
		else if (st.empty() || st.top() != s[i]) return false;
		else st.pop();//匹配上了就要弹出来
		

	}
	//for循环走完了说明都匹配上了，如果这时候栈为空，就刚刚好，true
	//如果这时候还有多余的栈，说明还有一些右括号没有匹配，false
	return st.empty();
}
//1047 简单 删除字符串中的所有相邻重复项
string removeDuplicateStr(string s)
{
	stack<char> st;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!st.empty() && st.top() == s[i]) st.pop();
		else st.push(s[i]);

	}
	string res = "";
	int size = st.size();
	for (size_t i = 0; i < size; i++)
	{
		res += st.top();
		st.pop();
	}
	//最后还要反转一下栈
	//时间复杂度on
	string out = "";
	//auto k = res.rbegin();
	//反转迭代器，从末尾开始迭代，注意还是需要递增
	for (auto it = res.rbegin(); it != res.rend(); it++)
	{
		out += *it;
	}
	//reverse(res.begin(), res.end());
	return out;

	
}
//344 简单 反转字符串
void reverseString(vector<char>& s)
{
	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
	
}
//344 简单 反转字符串 重载，输入string
string reverseString(string s)
{
	//使用额外数组，暴力求解
#if 0
	string res = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		res += s[i];
		
	}
	return res;
#endif
	//不使用额外数组
	//s[0] = '1';
	/*注意！char *字符串是定义在常量区，所以不可被修改，而char[]被定义在栈上，可被修改，string也是被定义在栈上
	所以也可被修改,如果传入的是char * 类型的字符，但又想修改它，可把其转为string，再进行转化，转化后再调用string的
	data函数或者c_str函数
	*/

	int left = 0;
	int right = s.size() - 1;
	while (left < right)
	{
		swap(s[left],s[right]);
		left++;
		right--;
	}
	return s;


}
//541 简单 反转字符串II
string reverseStrII(string s, int k)
{
	
	//能反转几次
	int epoch = s.size() / (2 * k);
	//余数
	int surplus = s.size() - (2 * k) * epoch;
	for (int i = 0; i < epoch; i++)
	{
		int left = i * 2 * k;
		int right = i * 2 * k + k - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		
	}

	if (surplus >= k && surplus < 2 * k)
	{
		int left = epoch * 2 * k;
		int right = epoch * 2 * k + k - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;
	}
	else
	{
		int left = epoch * 2 * k;
		int right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
		return s;

	}
	
	
}
//剑指offer05 简单 替换空格
string replaceSpace(string s)
{
	//on2的复杂度
#if 0
	string temp = "%20";
	for (size_t i = 0; i < s.size(); i++)
	{
		
		if (s[i] == ' ')
		{
			//erase删除指定位置的字符，位置从0开始计数
			//首先删除空格,只想删除空格，但这个函数会把这个位置及之后的字符全删除掉
			//原因在于参数是int，这实际调用了erase的第二个重载，它还有一个参数，就是删除几个
			//没写默认就是全删，只需要加上一个1，代表删除一个就行
			//或者给它传一个迭代器索引也行
			s.erase(i,1);
			//在指定位置之前插入字符串，注意是在指定位置之前插入
			//前面刚删了空格，现在i的位置是下一个字符，其之前刚好是需要插入待替换字符位置
			s.insert(i, temp);
		}
	}
	return s;
#endif

	//双指针技巧，on的复杂度
#if 1
	int count = 0; // 统计空格的个数
	int sOldSize = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
	s.resize(s.size() + count * 2);
	int sNewSize = s.size();
	// 从后先前将空格替换为"%20"
	for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
		if (s[j] != ' ') {
			s[i] = s[j];
		}
		else {
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			i -= 2;
		}
	}
	return s;

#endif
}
