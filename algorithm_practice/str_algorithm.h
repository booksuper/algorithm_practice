#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <unordered_map>
#include <stack>

using namespace std;
//找到字符串中的重复字符
set<string> findRepeatStr(char * s, const char * delimiter);

/*242简单 有效的字母异位词：给定两个字符串 s 和 t ，
编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
*/
bool isAnagram(string s, string t);

/*383 简单 赎金信：给你两个字符串：ransomNote 和 magazine ，
判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次
*/
bool canConstruct(string ransomNote, string magazine);

/*20 简单 有效的括号：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，
判断字符串是否有效。有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
*/
bool isValid(string s);

/*1047 简单 删除字符串中的所有相邻重复项：给出由小写字母组成的字符串 S，
重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一
*/
string removeDuplicateStr(string s);

/*344 简单 反转字符串：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题
*/
void reverseString(vector<char>& s);

//使用string反转字符串,重载，输入string
string reverseString(string s);

/*541 简单 反转字符串II:给定一个字符串 s 和一个整数 k，从字符串开头算起，
每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
*/

string reverseStrII(string s, int k);

/*剑指offer05 简单 替换空格：请实现一个函数，把字符串 s 中的每个空格替换成"%20*/
string replaceSpace(string s);

//华为研发编程题：十六进制转十进制
int ox2Binary(string s);