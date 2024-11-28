#include "PhieuMuon.h"

PhieuMuon::PhieuMuon(string MBD, string MS)
    : MaBanDoc(MBD), MaSach(MS), NgayMuon(0), NgayTra(0), TinhTrangPhieuMuon(0) {
    SoPhieuMuon++;
}



int PhieuMuon::getSoPhieuMuon() { return SoPhieuMuon; }
string PhieuMuon::getMaBanDoc() { return MaBanDoc; }
string PhieuMuon::getMaSach() { return MaSach; }
long PhieuMuon::getNgayMuon() { return NgayMuon; }
long PhieuMuon::getNgayTra() { return NgayTra; }
int PhieuMuon::getTinhTrangPhieuMuon() { return TinhTrangPhieuMuon; }

void PhieuMuon::setSoPhieuMuon(int i) { SoPhieuMuon = i; }
void PhieuMuon::setMaBanDoc(string s) { MaBanDoc = s; }
void PhieuMuon::setMaSach(string s) { MaSach = s; }
void PhieuMuon::setNgayMuon(long dt) { NgayMuon = dt; }
void PhieuMuon::setNgayTra(long dt) { NgayTra = dt; }
void PhieuMuon::setTinhTrangPhieu(int i) { TinhTrangPhieuMuon = i; }
void PhieuMuon::traSach() { TinhTrangPhieuMuon = 0; }  //new
//new
void PhieuMuon::xuat() {
    cout << "| " << setw(14) << left << SoPhieuMuon
        << "| " << setw(14) << left << MaBanDoc
        << "| " << setw(14) << left << MaSach
        << "| " << setw(2) << right << /*NgayMuon.DD*/ "26"
        << "/" << setw(2) << right << /*NgayMuon.MM */ "11"
        << "/" << setw(4) << right << /*NgayMuon.YY */ "2024"
        << "" << setw(4) << left << ""
        << "| " << setw(2) << right << /*NgayTra.DD*/ "26"
        << "/" << setw(2) << right << /*NgayTra.MM*/  "11"
        << "/" << setw(4) << right << /*NgayTra.YY*/  "2024"
        << "" << setw(4) << left << ""
        << "| " << setw(14) << left << (TinhTrangPhieuMuon == 1 ? "Dang muon" : "Da tra")
        << "|" << endl;
}