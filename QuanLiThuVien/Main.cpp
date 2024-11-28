#include "Header.h"
#include "DanhSachPhieuMuon.h"
#include "PhieuMuon.h"
#include "Node.h"
#include"LinkedList.h"
#include "DanhSachPhieuMuon.cpp"
#include "Node.cpp"
#include "PhieuMuon.cpp"
int main() {

    DanhSachPhieuMuon<PhieuMuon> danhSachPhieuMuon;

    int choice;
    do {

        cout << "\n----- QUAN LY PHIEU MUON SACH -----" << endl;
        cout << "1. Xuat danh sach phieu muon ra man hinh" << endl;
        cout << "2. Muon sach" << endl;
        cout << "3. Tra sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            danhSachPhieuMuon.xuatConsole();
            break;
        }
        case 2: {
            danhSachPhieuMuon.muon();
            break;
        }
        case 3: {
            danhSachPhieuMuon.tra();
            break;
        }
        case 0: {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        }
        default: {
            cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
        }
    } while (choice != 0);

    return 0;
}