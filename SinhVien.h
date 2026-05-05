#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string ngaySinh;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    string xepLoai;
};

struct NodeSV {
    SinhVien data;
    NodeSV* next;
};

float tinhDiemTB(float toan, float ly, float hoa);
string tinhXepLoai(float diemTB);

void nhapDanhSachSV(NodeSV*& head, int n);
void inDanhSachSV(NodeSV* head);

void taiFileSV(NodeSV*& head, const string& filename);
void docFileSV(NodeSV*& head, const string& filename);
void luuFileSV(NodeSV* head, const string& filename);

void themSV(NodeSV*& head);
void suaSV(NodeSV* head);
void xoaSV(NodeSV*& head);

void timTheoMaSV(NodeSV* head);
void timTheoHoTen(NodeSV* head);

void sapXepTheoMaSV(NodeSV*& head);
void sapXepTheoHoTen(NodeSV*& head);
void sapXepTheoDiemTBTang(NodeSV*& head);
void sapXepTheoDiemTBGiam(NodeSV*& head);

void timDiemTBCaoNhat(NodeSV* head);
void timDiemTBThapNhat(NodeSV* head);
void timDiemToanCaoNhat(NodeSV* head);
void timDiemToanThapNhat(NodeSV* head);

float tongDiemTB(NodeSV* head);
float trungBinhDiemTB(NodeSV* head);
int demTongSV(NodeSV* head);
int demSVDat(NodeSV* head);
int demSVGioi(NodeSV* head);

void thongKeXepLoai(NodeSV* head);
void thongKeSVTheoDieuKien(NodeSV* head);

void xoaDanhSachSV(NodeSV*& head);
