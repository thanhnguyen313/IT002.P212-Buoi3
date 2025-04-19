#pragma once
#include <iostream>
#include "CANDIDATE.h"
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

bool CANDIDATE::isValidName(const string& name)    //Ham kiem tra ten hop le
{
    if (name.length() < 2) return false;    //Ten phai co it nhat 2 ky tu
    bool hasAlpha = false;      //Kiem tra xem co chu cai ko
    for (size_t i = 0; i < name.length(); i++)
    {
        if (isalpha(name[i])) //Tim thay it nhat mot chu cai
            hasAlpha = true;
        else if (!isspace(name[i])) //Neu khong phai chu cai hoacj khoang trang -> Khong hop le
            return false;
    }
    return hasAlpha;
}       //Kiem tra ten ho
void CANDIDATE::standardizeNames(string& str) //Chuan hoa ten cua hoc sinh sao cho dung dinh dang
{
    int i = 0;
    //Xoa cac khoang trang du thua do nguoi dung nhap
    while (i < str.length())
    {
        if (i > 0 && str[i] == '.' && str[i - 1] == ' ')
        {
            str.erase(i - 1, 1);
            i--;
        }
        if (i > 0 && str[i] == ' ' && str[i - 1] == ' ')
        {
            str.erase(i - 1, 1);
            i--;
        }
        if (i == 0 && str[i] == ' ')
        {
            str.erase(i, 1);
            i--;
        }
        if (i > 0 && str[i] != ' ' && str[i - 1] == '.')
        {
            str.insert(i, " ");
            i++;
        }
        else
            i++;
    }
    //Viet hoa chu cai dau
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    if (str[0] != ' ')
        str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i - 1] == ' ')
            str[i] = toupper(str[i]);
    }
}
void CANDIDATE::Input()
{
    //Nhap ten thi sinh
    do
    {
        cout << "\nNhap ten thi sinh: "; cin.ignore(); getline(cin, name);
        if (!isValidName(name))
            cout << "\nVui long nhap ten hop le (khong chua chu so va ky tu dac biet) !";
        standardizeNames(name);
    } while (!isValidName(name));
    //Nhap MSSV
    do
    {
        cout << "\nNhap MSSV: "; cin >> code;
        if (code < 1000 || code > 9999)     //Quy dinh code co dang 1000 - 9999 (vd: 1207) 
            cout << "\nVui long nhap MSSV hop le (1000 - 9999) !";
    } while (code < 1000 || code > 9999);
    //Nhap ngay thang nam sinh
    do
    {
        cout << "\nNhap ngay thang nam sinh (cach nhau khoang trang): "; cin >> dateOfBirth;
        if (!dateOfBirth.checkDays(dateOfBirth))
            cout << "\nVui long nhap ngay thang nam hop le !";
    } while (!dateOfBirth.checkDays(dateOfBirth));
    //Nhap diem Toan, Van, Anh cua thi sinh
    do
    {
        cout << "\nDiem Toan: "; cin >> mathScore;
        if (mathScore < 0 || mathScore > 10)
            cout << "\nVui long nhap diem hop le! (Trong khoang tu 0 -> 10)";
    } while (mathScore < 0 || mathScore > 10); //Sai diem thi nhap lai
    do
    {
        cout << "\nDiem Van: "; cin >> literatureScore;
        if (literatureScore < 0 || literatureScore > 10)
            cout << "\nVui long nhap diem hop le! (Trong khoang tu 0 -> 10)";
    } while (literatureScore < 0 || literatureScore > 10);
    do
    {
        cout << "\nDiem Anh: "; cin >> englishScore;
        if (englishScore < 0 || englishScore > 10)
            cout << "\nVui long nhap diem hop le! (Trong khoang tu 0 -> 10)";
    } while (englishScore < 0 || englishScore > 10);
    sum = (mathScore + literatureScore + englishScore);
    cout << fixed << setprecision(2); //Lam tron toi chu so thap phan thu 2
}
void CANDIDATE::Output()
{
    cout << "\nHo va ten: " << name;
    cout << "\nMSSV: " << code;
    cout << "\nNgay sinh: " << dateOfBirth;
    cout << "\nDiem Toan: " << mathScore;
    cout << "\nDiem Van: " << literatureScore;
    cout << "\nDiem Tieng Anh: " << englishScore;
    cout << "\nDiem Tong: " << sum;
}
string CANDIDATE::getName() { return name; }    //Lay ten cua thi sinh
float CANDIDATE::getSum() { return sum; }       //Lay tong diem cua thi sinh
CANDIDATE& CANDIDATE::operator=(const CANDIDATE& otherCandidate)        //overload ham gan thi sinh
{
    if (this != &otherCandidate)
    {
        name = otherCandidate.name;
        code = otherCandidate.code;
        dateOfBirth = otherCandidate.dateOfBirth;
        mathScore = otherCandidate.mathScore;
        literatureScore = otherCandidate.literatureScore;
        englishScore = otherCandidate.englishScore;
        sum = otherCandidate.sum;
    }
    return *this;
}
