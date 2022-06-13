#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ȶ�������� a ԭ���� b ��ǰ�棬�� a == b������֮�� a ��Ȼ�� b ��ǰ�棬��Ϊ�ȶ�����
//���ȶ�������� a ԭ���� b ��ǰ�棬�� a == b������֮�� a ���ܲ��� b ��ǰ�棬��Ϊ���ȶ�����

/// @brief ð������
/// @details �㷨ԭ��Ϊ�����ң����������ڵ�����Ԫ�ؽ��бȽϣ����ϴ�ķŵ����档�㷨���Ӷ�ΪO(n2)
/// ����һ���ȶ������㷨
template<class T>
void bubbleSort(vector<T> & arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = 0; j < arr.size()-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				T tem = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tem;
			}
			
		}
	}
}


/// @brief ֱ��ѡ������
/// @details �㷨���Ӷ�ΪO(n2),������������ð�������ٶ��ˣ�nֵ��Сʱ��ѡ�������ð�������
/// ѡ����������������У�Ԫ����������ʱ����ͬԪ�ص�ǰ��˳��ᷢ���ı� �����磺����5 5 7 2 9��
/// ��һ��ѡ���1��Ԫ��5���2��������ôԭ����������5�����ǰ��˳��ͱ��ƻ��ˣ���ð�����򲻻ᣩ��
/// ����ѡ��������һ�ֲ��ȶ��������㷨
template<class T>
void selectSort(vector<T> & arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				T tem = arr[i];
				arr[i] = arr[j];
				arr[j] = tem;
			}

		}
	}

}

/// @brief ��������
/// @details ����������һ�ֲ��ȶ������㷨���㷨���Ӷ���nlogn,���ڶ������㷨���ٶ��������ŵ�
/// �㷨ԭ������ѡ��һ����׼ֵ��һ��ѡ���һ��Ԫ����Ϊ��׼ֵ��Ȼ���Ի�׼ֵΪ�罫�����Ϊ���������飬�Ȼ�׼ֵС��
/// ����ߣ��Ȼ�׼ֵ������ұߡ�Ȼ���ڶ��������ظ����ƵĲ���������ʵ������
/// ��������ı���˼���ǵݹ飬���������õݹ�ʵ�ֵģ���Ҳ���Բ��õݹ�ʵ�ֿ�������
template<class T>
vector<T> quickSort(vector<T> arr)
{
	//��һ���ǵݹ����ֹ������û����һ�����������������ѭ��
	if (arr.size() <= 1)
		return arr;
	T pivot = arr[0];
	vector<T> left;
	vector<T> right;
	//�Ȼ�׼ֵС����left�������right��
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] <= pivot)
		{
			left.push_back(arr[i]);
		}
		else
		{
			right.push_back(arr[i]);
		}
	}
	vector<T> res1, res2,res;
	//��������ݹ�
	res1 = quickSort(left);
	res2 = quickSort(right);
	//ƴ��
	res.insert(res.end(), res1.begin(), res1.end());
	res.insert(res.end(),pivot);
	res.insert(res.end(), res2.begin(), res2.end());
	return res;
}

