#pragma once
#include "DanhSachPhieuMuon.h"
#include "LinkedList.h"
#include "Header.h"
#include "Node.h"
/***********************************************************************************************
* @Description     Lấy dữ liệu file txt
* @parameter       Tên file txt
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::docFile(string fn) {
	ifstream is(fn);
	if (!is.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	string s;
	while (getline(is, s)) {
		stringstream ss(s);
		vector<string> v;
		string tmp;
		while (getline(ss, tmp, '|')) {
			v.push_back(tmp);
		}
		//if (v.size() != 2) continue;
		PhieuMuon phieuMuon(v[0], v[1]);
		cout << phieuMuon.getMaBanDoc();
		LinkedList<PhieuMuon>::addTail(phieuMuon);
	}
	is.close();
}

/***********************************************************************************************
* @Description     Ghi đè lên file txt
* @parameter       Tên file txt
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::xuatFile(string fn) {
	ofstream os(fn);
	if (!os.is_open()) {
		cout << "Khong mo duoc file!!!" << endl;
		return;
	}
	Node<PhieuMuon>* node = LinkedList<PhieuMuon>::getHead();
	while (node != NULL) {
		os << node << endl;
		node = node->_pNext;
	}
	os.close();
}

/***********************************************************************************************
* @Description     Xuất Danh Sach Sach ra màn hình
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::xuatConsole() {
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	if (tmp == NULL) {
		cout << "Danh sach phieu muon rong!" << endl;
	}
	else {
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
		cout << "| So phieu muon | Ma ban doc    | Ma sach       | Ngay muon     | Ngay tra      | Tinh trang    |" << endl;
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
		while (tmp != NULL) {
			tmp->_data.xuat();
			tmp = tmp->_pNext;
		}
		cout << "+---------------+---------------+---------------+---------------+---------------+---------------+" << endl;
	}


}

/***********************************************************************************************
* @Description     Kiểm tra dữ liệu nhập vào đạt chuẩn hay không
* @parameter       chuỗi cần kiểm tra
* @return          Trả về true nếu chuỗi đúng chuẩn và false nếu chuỗi không đúng chuẩn
*************************************************************************************************/
template<class PhieuMuon>
bool DanhSachPhieuMuon<PhieuMuon>::kiemTra(const string& st) {
	for (char c : st) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
			return false;
		}
	}
	return true;
}

/***********************************************************************************************
* @Description     Xử lí tháo tác mượn sách và tạo phiếu mượn
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::muon() {
	int count = 0;
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	string maSach, maBanDoc;
	do {
		cout << "Nhap ma sach: " << endl;
		cin >> maSach;
		if (!kiemTra(maSach)) {
			cout << "Ma sach chi duoc nhap chu va so! Vui long nhap lai." << endl;
		}
	} while (!kiemTra(maSach));
	do {
		cout << "Nhap ma ban doc: " << endl;
		cin >> maBanDoc;
		if (!kiemTra(maBanDoc)) {
			cout << "Ma ban doc chi duoc nhap chu va so! Vui long nhap lai." << endl;
		}
	} while (!kiemTra(maBanDoc));

	bool sachDaMuon = false;
	while (tmp != NULL) {
		if (tmp->_data.getMaSach() == maSach && tmp->_data.getTinhTrangPhieuMuon() == 1) {
			sachDaMuon = true;
			break;
		}
	}
	if (sachDaMuon) {
		cout << "Sach da duoc muon boi nguoi khac!" << endl;
	}
	else {
		PhieuMuon phieuMuon(maBanDoc, maSach);
		LinkedList<PhieuMuon>::addTail(phieuMuon);
		cout << "Muon sach thanh cong!" << endl;
	}
}

/***********************************************************************************************
* @Description     Xử lí tháo tác trả sách và xóa phiếu mượn
*************************************************************************************************/
template<class PhieuMuon>
void DanhSachPhieuMuon<PhieuMuon>::tra() {
	int soPhieuMuon;
	cout << "Nhap so phieu muon: ";
	cin >> soPhieuMuon;
	bool found = false;
	Node<PhieuMuon>* tmp = LinkedList<PhieuMuon>::getHead();
	while (tmp != NULL) {
		if (tmp->_data.getSoPhieuMuon() == soPhieuMuon) {
			tmp->_data.traSach();
			cout << "Tra sach thanh cong!" << endl;
			found = true;
			break;
		}
		tmp = tmp->_pNext;
	}
	if (!found) {
		cout << "So phieu muon khong ton tai!" << endl;
	}
}