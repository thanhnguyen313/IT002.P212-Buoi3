#include "CANDIDATE.h"
#include "ListCandidate.h"
#include <iostream>
using namespace std;
int main()
{
    CANDIDATE candidate;
    ListCandidate list;
    list.listCandidateInput();
    int choosen;
    do
    {
        cout << "\n==================================================";
        cout << "\n---------- CHUONG TRINH QUAN LY THI SINH ---------";
        cout << "\n0. Thoat chuong trinh. ";
        cout << "\n1. Danh sach cac thi sinh. ";
        cout << "\n2. Danh sach cac thi sinh co tong diem > 15: ";
        cout << "\n3. Thi sinh co tong diem cao nhat: ";
        cout << "\n4. Danh sach hoc sinh giam dan theo tong diem. ";
        do
        {
            cout << "\nBan chon: "; cin >> choosen;
            if (choosen < 0 || choosen > 4)
                cout << "\nVui long nhap dung lua chon !";
        } while (choosen < 0 || choosen > 4);
        switch (choosen)
        {
        case 0:     // Thoat chuong trinh
            return 0;
        case 1:     //Danh sachs cac thi sinh
            list.listCandidateOutput();
            break;
        case 2:     //Danh sach cac thi sinh co tong diem > 15
            list.listCandidateThatSumOver15();
            break;
        case 3:     //Thi sinh co tong diem cao nhat
            list.candidateThatHaveMaxScore();
            break;
        case 4:
        {
            list.listCandidateDecrease();
            break;
        }
        default:
            break;
        }
    } while (choosen != 0);

    return 0;
}

