#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
void sortSolomon(vector<T> *arr){//�㭪�� ���஢��
    //���� 1 ᮧ����� ������
    T min=(*arr)[0];
    T max=(*arr)[0];

    for(int i=0;i<arr->size();i++){//��室�� �������訩 � �������訩 �����
        if((*arr)[i]<min)
            min=(*arr)[i];
        if((*arr)[i]>max)
            max=(*arr)[i];
    }
    cout << "������� �������쭮� � ���ᨬ��쭮� ���祭�� � ���ᨢ� - " << min << " � " << max <<"\n";
    float delta=(float)(max-min)/arr->size();//�����뢠�� ������
    cout << "����⠭� delta �� ��㫥 (max-min)/N = " << delta << "\n";

    vector<vector<T>> tmp;
    //�⠯ 2, �६� ࠧ���뢠�� �����
    tmp.resize(arr->size()+2);
    for(int i=0;i<arr->size();i++){
        int curPos=((*arr)[i]-min)/delta+1;//�����뢠�� ������ ��� ������� ����� � ��।��塞 � ᮮ⢥����騥 ���⪨
        cout << i << "-� ����� ��।���� � " << curPos << " �����\n";
        tmp[curPos].push_back((*arr)[i]);
        cout << "������⢮ ����⮢ �� �६����� ����� ����஢:\n";
        for(int j=1;j<tmp.size();j++){
            cout << tmp[j].size() << " ";
        }
        cout << "\n\n";
    }
    cout << "�� �⮣� ����� ᫥���騩 �६���� �����:\n";
    for(int i=1;i<tmp.size();i++){//�⮣��� ����� ����஢
        cout << tmp[i].size() << ": ";
        for(int j=0;j<tmp[i].size();j++){
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    //�⠯ 3, �६� ᮡ���� �����
    arr->clear();
    cout << "��᫥����⥫쭮 �����塞 �����, �����஢�� ��:\n";
    for(int i=0;i<tmp.size();i++){//�����塞 �����, ������ ��, ��� ��-ࠧ���� ����� ���������� � ᯨ᮪ ��।�������� �����
        if(tmp[i].size()==0)
            continue;
        //�⠭���⭠� ���஢�� ����쪮� ����-������
        for(int j=0;j<tmp[i].size();j++)
            for(int k=j;k<tmp[i].size();k++)
                if(tmp[i][j]>tmp[i][k]) {
                    T t = tmp[i][j];
                    tmp[i][j] = tmp[i][k];
                    tmp[i][k] = t;
                }
        for(int j=0;j<tmp[i].size();j++){
            arr->push_back(tmp[i][j]);
        }
        for(int j=0;j<arr->size();j++){
            cout << (*arr)[j] << " ";//�஬������ �ண��� ������ ������ ���ᨢ�
        }
        cout << "\n";
    }
}

int main() {
    //���� �室��� ��ப�
    int choose=0;
    cout << "Choose input:\n0.CIN\n1.FILE\n";
    cin >> choose;//�롨ࠥ� ����� ������ � ���᮫� � �� 䠩��
    getchar();
    vector<int> arr;
    vector<int> arr2;
    string x;
    if(choose==0){
        getline(cin,x);
        while(!x.empty()){
            arr.push_back(std::atoi(x.c_str()));
            arr2.push_back(std::atoi(x.c_str()));
            getline(cin,x);
        };
    }else {
        ifstream ff;
        ff.open("Lab4Input.txt");
        if (ff.is_open()) {
            getline(ff, x);
            while(!x.empty()){
                arr.push_back(std::atoi(x.c_str()));
                arr2.push_back(std::atoi(x.c_str()));
                getline(ff, x);
            }
        }
        else
            return 0;
    }

    cout << "��室�� ���冷�:\n";
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    if(arr.size()>=2) {
        cout << "\n����� ���஢��:\n\n";
        sortSolomon(&arr);
    }else{
        cout << "��� ����室����� ����᪠�� ���஢��\n";
    }

    cout << "�����஢���� ���冷�:\n";
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }

    sort(arr2.begin(),arr2.end());
    cout << "\n�����஢���� ��������� ��⮤�� ���冷�:\n";
    for(int i=0;i<arr2.size();i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
