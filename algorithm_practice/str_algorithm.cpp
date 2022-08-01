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
