/**
 * File: array.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* �������Ԫ�� */
int randomAccess(int *nums, int size) {
    // ������ [0, size) �������ȡһ������
    int randomIndex = rand() % size;
    // ��ȡ���������Ԫ��
    int randomNum = nums[randomIndex];
    return randomNum;
}

/* ��չ���鳤�� */
int *extend(int *nums, int size, int enlarge) {
    // ��ʼ��һ����չ���Ⱥ������
    int *res = new int[size + enlarge];
    // ��ԭ�����е�����Ԫ�ظ��Ƶ�������
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // �ͷ��ڴ�
    delete[] nums;
    // ������չ���������
    return res;
}

/* ����������� index ������Ԫ�� num */
void insert(int *nums, int size, int num, int index) {
    // ������ index �Լ�֮�������Ԫ������ƶ�һλ
    for (int i = size - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // �� num ���� index ����Ԫ��
    nums[index] = num;
}

/* ɾ������ index ����Ԫ�� */
void remove(int *nums, int size, int index) {
    // ������ index ֮�������Ԫ����ǰ�ƶ�һλ
    for (int i = index; i < size - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

/* �������� */
void traverse(int *nums, int size) {
    int count = 0;
    // ͨ��������������
    for (int i = 0; i < size; i++) {
        count += nums[i];
    }
}

/* �������в���ָ��Ԫ�� */
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/* Driver Code */
int main() {
    /* ��ʼ������ */
    int size = 5;
    int *arr = new int[size];
    cout << "���� arr = ";
    printArray(arr, size);

    int *nums = new int[size]{1, 3, 2, 5, 4};
    cout << "���� nums = ";
    printArray(nums, size);

    /* ������� */
    int randomNum = randomAccess(nums, size);
    cout << "�� nums �л�ȡ���Ԫ�� " << randomNum << endl;

    /* ������չ */
    int enlarge = 3;
    nums = extend(nums, size, enlarge);
    size += enlarge;
    cout << "�����鳤����չ�� 8 ���õ� nums = ";
    printArray(nums, size);

    /* ����Ԫ�� */
    insert(nums, size, 6, 3);
    cout << "������ 3 ���������� 6 ���õ� nums = ";
    printArray(nums, size);

    /* ɾ��Ԫ�� */
    remove(nums, size, 2);
    cout << "ɾ������ 2 ����Ԫ�أ��õ� nums = ";
    printArray(nums, size);

    /* �������� */
    traverse(nums, size);

    /* ����Ԫ�� */
    int index = find(nums, size, 3);
    cout << "�� nums �в���Ԫ�� 3 ���õ����� = " << index << endl;

    // �ͷ��ڴ�
    delete[] arr;
    delete[] nums;

    return 0;
}
