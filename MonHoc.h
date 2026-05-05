#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct MonHoc {
    string maMH;
    string tenMH;
    int soTinChi;
};

struct NodeMH {
    MonHoc data;
    NodeMH* next;
};

void nhapDanhSachMH(NodeMH*& head, int n);
void inDanhSachMH(NodeMH* head);

void taiFileMH(NodeMH*& head, const string& filename);
void docFileMH(NodeMH*& head, const string& filename);
void luuFileMH(NodeMH* head, const string& filename);

void themMH(NodeMH*& head);
void suaMH(NodeMH* head);
void xoaMH(NodeMH*& head);

void timTheoMaMH(NodeMH* head);
void timTheoTenMH(NodeMH* head);

void sapXepTheoMaMH(NodeMH*& head);
void sapXepTheoTenMH(NodeMH*& head);
void sapXepTheoTinChiTang(NodeMH*& head);
void sapXepTheoTinChiGiam(NodeMH*& head);

void timTinChiCaoNhat(NodeMH* head);
void timTinChiThapNhat(NodeMH* head);

int tongTinChi(NodeMH* head);
float trungBinhTinChi(NodeMH* head);
int demTongMH(NodeMH* head);

void thongKeMHTheoDieuKien(NodeMH* head);

void xoaDanhSachMH(NodeMH*& head);
