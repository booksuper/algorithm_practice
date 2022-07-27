#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;
//找到字符串中的重复字符
set<string> findRepeatStr(char * s, const char * delimiter);

/*242简单 有效的字母异位词：给定两个字符串 s 和 t ，
编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
*/
bool isAnagram(string s, string t);