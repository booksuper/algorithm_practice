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
