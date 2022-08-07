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
//383 �� �����
bool canConstruct(string ransomNote, string magazine)
{
	//ʹ������ȹ�ϣ���ʡʱ����Ϊ����Ҫά��һ����ϣ��
	unordered_map<int, int> temp_map;//key�Ǵ����ַ���0����a���������ƣ�value���ַ����ֵĴ���
	unordered_map<int, int> temp_map2;
	//�������ַ����ĸ��ַ������ֱ��¼��map��
	for (size_t i = 0; i < ransomNote.length(); i++)
	{
		temp_map[ransomNote[i] - 'a']++;
		//��ʹ��insert,û������ͬԪ�ؼ�һ
		//temp_map.insert(pair<int, int>(ransomNote[i] - 'a',i));
	}
	for (size_t i = 0; i < magazine.length(); i++)
	{
		temp_map2[magazine[i] - 'a']++;
	}
	//���Ŀ���ַ�����С�������ַ���ֱ��false
	if (temp_map2.size() < temp_map.size())
	{
		return false;
	}
	else
	{
		for (auto var : temp_map)
		{
			auto temp = temp_map2.find(var.first);
			//���ȿ���û������ַ���û��ֱ��false
			if (temp == temp_map2.end())
			{
				return false;
				
			}
			//Ȼ������ַ��Ĵ����ǲ���С�������ַ��Ĵ�����С��ֱ��false
			if (temp->second < var.second)
			{
				return false;
			}
		}
		return true;
	}


}
//20 �� ��Ч������
bool isValid(string s)
{
	/*����ƥ������ʹ��ջ���ֽṹ�����
	�ȰѴ�ƥ����ַ�������ѹ�룬Ȼ�������ζ���Щ�ַ��������ж�*/
	stack<int> st;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') st.push(')');
		else if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		//�жϡ�ջ��֮ǰ�ܲ���ƥ���϶�Ӧ���ַ�
		else if (st.empty() || st.top() != s[i]) return false;
		else st.pop();//ƥ�����˾�Ҫ������
		

	}
	//forѭ��������˵����ƥ�����ˣ������ʱ��ջΪ�գ��͸ոպã�true
	//�����ʱ���ж����ջ��˵������һЩ������û��ƥ�䣬false
	return st.empty();
}
//1047 �� ɾ���ַ����е����������ظ���
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
	//���Ҫ��תһ��ջ
	//ʱ�临�Ӷ�on
	string out = "";
	//auto k = res.rbegin();
	//��ת����������ĩβ��ʼ������ע�⻹����Ҫ����
	for (auto it = res.rbegin(); it != res.rend(); it++)
	{
		out += *it;
	}
	//reverse(res.begin(), res.end());
	return out;

	
}
//344 �� ��ת�ַ���
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
//344 �� ��ת�ַ��� ���أ�����string
string reverseString(string s)
{
	//ʹ�ö������飬�������
#if 0
	string res = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		res += s[i];
		
	}
	return res;
#endif
	//��ʹ�ö�������
	//s[0] = '1';
	/*ע�⣡char *�ַ����Ƕ����ڳ����������Բ��ɱ��޸ģ���char[]��������ջ�ϣ��ɱ��޸ģ�stringҲ�Ǳ�������ջ��
	����Ҳ�ɱ��޸�,����������char * ���͵��ַ����������޸������ɰ���תΪstring���ٽ���ת����ת�����ٵ���string��
	data��������c_str����
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
//541 �� ��ת�ַ���II
string reverseStrII(string s, int k)
{
	
	//�ܷ�ת����
	int epoch = s.size() / (2 * k);
	//����
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
//��ָoffer05 �� �滻�ո�
string replaceSpace(string s)
{
	//on2�ĸ��Ӷ�
#if 0
	string temp = "%20";
	for (size_t i = 0; i < s.size(); i++)
	{
		
		if (s[i] == ' ')
		{
			//eraseɾ��ָ��λ�õ��ַ���λ�ô�0��ʼ����
			//����ɾ���ո�,ֻ��ɾ���ո񣬵��������������λ�ü�֮����ַ�ȫɾ����
			//ԭ�����ڲ�����int����ʵ�ʵ�����erase�ĵڶ������أ�������һ������������ɾ������
			//ûдĬ�Ͼ���ȫɾ��ֻ��Ҫ����һ��1������ɾ��һ������
			//���߸�����һ������������Ҳ��
			s.erase(i,1);
			//��ָ��λ��֮ǰ�����ַ�����ע������ָ��λ��֮ǰ����
			//ǰ���ɾ�˿ո�����i��λ������һ���ַ�����֮ǰ�պ�����Ҫ������滻�ַ�λ��
			s.insert(i, temp);
		}
	}
	return s;
#endif

	//˫ָ�뼼�ɣ�on�ĸ��Ӷ�
#if 1
	int count = 0; // ͳ�ƿո�ĸ���
	int sOldSize = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	// �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
	s.resize(s.size() + count * 2);
	int sNewSize = s.size();
	// �Ӻ���ǰ���ո��滻Ϊ"%20"
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
