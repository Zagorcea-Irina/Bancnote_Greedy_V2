#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*������� ������� ���������� ���������� �������� ��� �������� �����, ��������� V ��� ��������, ����������� �����
* S - ���������� ��� �����
* bills_size - �������� ������� ��������� ������ �������
* bills - �������� ������� ��������� ������ � ����������
*/
void count_bills(int s, int bills_size, int bills[])
{
    //�������������� ������ ��� �������� ���������� �������
    //�������� ������ ��� ��� �� ����� ��������� �������� ���� ������ � ������� �� �������
    vector<int> optin_bills;

    //�������� �� ����� ������� � ��������, �������� � ����� ��� ��� ����� ������� ������ � ��� � ����� �������
    for (int i = bills_size - 1; i >= 0; i--) {

        //��������� ���� ��������� �������� �������� ��� ����� �����
        //��������� � ������ ��� ��� ��� ������� ����� ������������ ������ ����� �������������
        while (s >= bills[i]) { //������� ��������� ���� �������� ������ �����
            s -= bills[i]; //�������� ���������� �������� �� ����� �����(��� ������� �� �����)
            optin_bills.push_back(bills[i]); //co������� ���������� �������� � ��� ������
        }
    }

    //������� ������ � ����������� �������� �� �����
    for (int i = 0; i < optin_bills.size(); i++) {
        cout << optin_bills[i] << "  ";
    }
}

/*������� ������� ��������� ������ �� �����������
* size_arr - �������� ������� ��������� ������ �������
* arr - �������� ������� ��������� ������ ��� ����������
*/
int * sort_array_asc(int size_arr, int arr[])
{
    int temp; // ��������� ���������� ��� ������ ��������� �������

    // ���������� ������� ���������
    for (int i = 0; i < size_arr - 1; i++) {
        for (int j = 0; j < size_arr - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // �������� ���� ������� ������� ������ ����������
                // ������ �������� �������
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // ����� ���������������� ������� �� �����
    cout << "��������������� ������ �� �����������: ";
    for (int i = 0; i < size_arr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // ������������� Locale ��������� ��� ������ ������ �� �������

    int *arr; // ��������� ��� ��������� ������ ��� ������
    int size; // ���������� ��� ������� �������

    //���� ���������� ��������� �������
    cout << "������� ���������� ������� ";
    cin >> size;

    // ������ ������ ������ ���� ������ 0
    if (size <= 0) {
        cout << "������ ������� ������ ���� ������ 0!";
        return 1;
    }

    arr = new int[size]; // ��������� ������ ��� ������

    // ���������� �������
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // ����� ���������������� ������� �� �����
    cout << "��������� ��������: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ��������� ��� ������ � ������� ��� ��������� ������� sort_array_asc
    int * sort_array = sort_array_asc(size, arr);

    // ������ �������� ����� ��� ���������
    int sum;
    cout << "������� ����� � ������� Enter: ";
    cin >> sum; //��������� ��������� ����� � ����������

    // ��������� ����� �� ������ � ������� �� � ������� �������
    cout << "�������� ���� ����� " << sum << " ������� �� ��������� �����: ";
    count_bills(sum, size, sort_array);

    return 0;
}
