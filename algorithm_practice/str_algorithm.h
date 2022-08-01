﻿#pragma once
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