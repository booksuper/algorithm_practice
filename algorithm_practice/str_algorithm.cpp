#include "str_algorithm.h"

set<string> findRepeatStr(char * s,const char * delimiter)
{
	set<string> res_str;
	vector<string> res_str_vec;
	//vector<string> repeat_vec;
	char *p;
	char* ptr = nullptr;//��������ʣ���ַ���
	//strtok_s���������ַ����ָ��һ�������Ǵ��ָ��ַ������ڶ����������ָ���ַ�
	//����������������ָ���ʣ���ַ�
	//�������strtok������̰߳�ȫ��
	//���ص��ǵ�һ���ָ����ַ������ҽ��ֽڷ���λ���ÿ�������
	p = strtok_s(s, delimiter, &ptr);
	//���ص��ַ����ǿյ�ʱ��ͻ�һֱѭ��
	while (p)
	{
		printf("%s\n", p);
		//�ָ�������ַ����Ž�res_str_vec
		res_str_vec.push_back(p);
		//�����ָ��ʱ��һ����������Ϊ�գ�����һ��
		p = strtok_s(NULL, delimiter, &ptr);
	}
	//�ҵ��ַ������ظ����ַ���
	for (size_t i = 0; i < res_str_vec.size(); i++)
	{
		for (size_t j = i + 1; j < res_str_vec.size(); j++)
		{
			if (res_str_vec[i] == res_str_vec[j])
			{
				//ʹ��set���Ա�֤�����в������ظ���Ԫ��
				res_str.insert(res_str_vec[i]);
				break;
			}
		}

	}
	return res_str;
}
//242�� ��Ч����ĸ��λ��
bool isAnagram(string s, string t)
{
	if (s.length() != t.length()) return false;
	//��¼�ַ����ֵĴ���
	int record[26] = {};
	for (size_t i = 0; i < s.length(); i++)
	{
		//���ǲ���Ҫ֪��s�о�����ַ��Ƕ��٣�ֻ��Ҫ������a��Եľ���
		//����ַ���a�����䷴ӳ��record����������0�м�1
		record[s[i] - 'a'] += 1;
		//ͬ���ĵ���Ϊ���ж������ַ����Ƿ���λ��ֻ��Ҫʹ��t�е��ַ�
		//��record�����һ���У�������recordԪ�ض�Ϊ0������λ
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
