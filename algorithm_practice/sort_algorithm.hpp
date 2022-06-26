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
/// @details ����������һ�ֲ��ȶ������㷨���㷨���Ӷ���nlogn,���ڶ������㷨���ٶȺܿ�
/// �㷨ԭ������ѡ��һ����׼ֵ��һ��ѡ���һ��Ԫ����Ϊ��׼ֵ��Ȼ���Ի�׼ֵΪ�罫�����Ϊ���������飬�Ȼ�׼ֵС��
/// ����ߣ��Ȼ�׼ֵ������ұߡ�Ȼ���ڶ��������ظ����ƵĲ���������ʵ������
/// ��������ı���˼���ǵݹ飬���������õݹ�ʵ�ֵģ���Ҳ���Բ��õݹ�ʵ�ֿ�������
template<class T>
vector<T> quickSort(vector<T> arr)
{
	////��һ���ǵݹ����ֹ������û����һ�����������������ѭ��
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

/// @brief �鲢����
/// @details �鲢������һ���ȶ������㷨���㷨���Ӷ���nlogn,���ڶ������㷨���ٶ��������ŵ�
/// �㷨ԭ��1.��������м仮�ֳ�����������;
/// 2.һֱ�ݹ�ذ������黮�ֳɸ�С�������飬ֱ������������ֻ��һ��Ԫ��
/// 3.���ΰ��յݹ�ķ���˳�򣬲��ϵغϲ��ź���������飬ֱ���������������˳���źá�
//�ϲ��������� a[first..mid] �� a[mid+1..last] ��������������ϲ���һ����������
template<class T>
void merge(T a[], int first, int mid, int last, T temp[])
{
	//�����ڽ�����˳������ϲ�Ϊһ���µ�����
	int i = first;//��������ʼ˳��
	int j = mid + 1;// ��������ʼ˳��
	int m = mid;//��������ֹ˳��
	int n = last;//��������ֹ˳��
	int k = 0;
	//������������һ��������������ѭ��
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
		{
			temp[k] = a[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	//��ȷ������Ϊ��һ������ﵽ��ֹ�����˳�����ѭ����
	//�����ٽ�������ѭ������ʣ�µ�һ����������ȫ�����ηŽ���ʱ������
	while (i<=m)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= n)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	//������õ���ʱ�������ݴ�����������
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
//�鲢������������������ֲ���
//����Ҫ�������飬��Ϊ������һ��ָ�룬�βθı��Ӱ��ʵ��
template<class T>
void merge_sort(T a[], int first, int last, T temp[])
{
	if (first >= last)//��ֹ����
	{
		return;
	}
	int mid = (first + last) / 2;
	//����벿�ֵݹ���
	merge_sort(a, first, mid, temp);
	//�Ұ벿�ֵݹ���
	merge_sort(a, mid + 1, last, temp);
	//�ϲ�
	merge(a, first, mid, last, temp);
}