#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//��ͨ�ݹ����쳲���������
//�������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�
//ʱ�临�Ӷ���ָ����2^n
int fib(int n);

//ʹ�ñ���¼����ȥ������ڵ����쳲���������,ʱ�临�ӶȽ���Ϊn
//����¼�����ô�ͦ�࣬���Ա����ظ�����
int modified_fib(int memo[], int n);
//