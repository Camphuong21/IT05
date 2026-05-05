#include <iostream>
#include <iomanip>
#include <vector>
#include "SinhVien.h"
#include "MonHoc.h"
using namespace std;

const string FILE_SV = "sinhvien.txt";
const string FILE_MH = "monhoc.txt";

static void inMenu(const string& title, const vector<string>& items) {
    cout << "\n========== " << title << " ==========\n";
    for (int i = 0; i < (int)items.size(); i++)
        cout << "  " << i + 1 << ". " << items[i] << "\n";
    cout << "  0. Quay lai / Thoat\n";
    cout << "Lua chon: ";
}

static int docSoNguyen(const string& prompt = "") {
    int val;
    if (!prompt.empty()) cout << prompt;
    while (!(cin >> val)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "  Vui long nhap so nguyen: ";
    }
    cin.ignore();
    return val;
}

// ---- Menu Sinh Vien ----

static void menuTimKiemSV(NodeSV*& head) {
    int ch;
    do {
        inMenu("TIM KIEM SINH VIEN", {
            "Tim theo ma SV",
            "Tim theo ho ten"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: timTheoMaSV(head);  break;
            case 2: timTheoHoTen(head); break;
        }
    } while (ch != 0);
}

static void menuSapXepSV(NodeSV*& head) {
    int ch;
    do {
        inMenu("SAP XEP SINH VIEN", {
            "Sap xep theo ma SV",
            "Sap xep theo ho ten",
            "Sap xep theo diem TB tang dan",
            "Sap xep theo diem TB giam dan"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: sapXepTheoMaSV(head);       inDanhSachSV(head); break;
            case 2: sapXepTheoHoTen(head);      inDanhSachSV(head); break;
            case 3: sapXepTheoDiemTBTang(head); inDanhSachSV(head); break;
            case 4: sapXepTheoDiemTBGiam(head); inDanhSachSV(head); break;
        }
    } while (ch != 0);
}

static void menuThongKeSV(NodeSV*& head) {
    int ch;
    do {
        inMenu("THONG KE SINH VIEN", {
            "SV co diem TB cao nhat",
            "SV co diem TB thap nhat",
            "SV co diem Toan cao nhat",
            "SV co diem Toan thap nhat",
            "Tong diem TB ca lop",
            "Diem TB trung binh ca lop",
            "Dem tong so sinh vien",
            "Dem so SV dat (TB >= 5.0)",
            "Dem so SV xep loai Gioi (TB >= 8.0)",
            "Thong ke so luong theo xep loai",
            "Thong ke SV theo dieu kien"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1:  timDiemTBCaoNhat(head); break;
            case 2:  timDiemTBThapNhat(head); break;
            case 3:  timDiemToanCaoNhat(head); break;
            case 4:  timDiemToanThapNhat(head); break;
            case 5:  cout << "  Tong diem TB ca lop: " << fixed << setprecision(2) << tongDiemTB(head) << "\n"; break;
            case 6:  cout << "  Diem TB trung binh : " << fixed << setprecision(2) << trungBinhDiemTB(head) << "\n"; break;
            case 7:  cout << "  Tong so sinh vien  : " << demTongSV(head) << "\n"; break;
            case 8:  cout << "  So SV dat (TB>=5.0): " << demSVDat(head) << "\n"; break;
            case 9:  cout << "  So SV Gioi (TB>=8.0): " << demSVGioi(head) << "\n"; break;
            case 10: thongKeXepLoai(head); break;
            case 11: thongKeSVTheoDieuKien(head); break;
        }
    } while (ch != 0);
}

static void menuSinhVien(NodeSV*& head) {
    int ch;
    do {
        inMenu("QUAN LY SINH VIEN", {
            "Nhap danh sach sinh vien",
            "In danh sach sinh vien",
            "Doc danh sach tu file",
            "Luu danh sach vao file",
            "Them sinh vien",
            "Sua sinh vien",
            "Xoa sinh vien",
            "Tim kiem",
            "Sap xep",
            "Thong ke / Tinh toan"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: {
                int n = docSoNguyen("Nhap so luong sinh vien: ");
                nhapDanhSachSV(head, n);
                break;
            }
            case 2:  inDanhSachSV(head); break;
            case 3:  docFileSV(head, FILE_SV); break;
            case 4:  luuFileSV(head, FILE_SV); break;
            case 5:  themSV(head); break;
            case 6:  suaSV(head); break;
            case 7:  xoaSV(head); break;
            case 8:  menuTimKiemSV(head); break;
            case 9:  menuSapXepSV(head); break;
            case 10: menuThongKeSV(head); break;
        }
    } while (ch != 0);
}

// ---- Menu Mon Hoc ----

static void menuTimKiemMH(NodeMH*& head) {
    int ch;
    do {
        inMenu("TIM KIEM MON HOC", {
            "Tim theo ma MH",
            "Tim theo ten MH"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: timTheoMaMH(head); break;
            case 2: timTheoTenMH(head); break;
        }
    } while (ch != 0);
}

static void menuSapXepMH(NodeMH*& head) {
    int ch;
    do {
        inMenu("SAP XEP MON HOC", {
            "Sap xep theo ma MH",
            "Sap xep theo ten MH",
            "Sap xep theo so tin chi tang dan",
            "Sap xep theo so tin chi giam dan"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: sapXepTheoMaMH(head);       inDanhSachMH(head); break;
            case 2: sapXepTheoTenMH(head);      inDanhSachMH(head); break;
            case 3: sapXepTheoTinChiTang(head); inDanhSachMH(head); break;
            case 4: sapXepTheoTinChiGiam(head); inDanhSachMH(head); break;
        }
    } while (ch != 0);
}

static void menuThongKeMH(NodeMH*& head) {
    int ch;
    do {
        inMenu("THONG KE MON HOC", {
            "Mon hoc co so tin chi cao nhat",
            "Mon hoc co so tin chi thap nhat",
            "Tong so tin chi",
            "So tin chi trung binh",
            "Dem tong so mon hoc",
            "Thong ke mon hoc theo nguong tin chi"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: timTinChiCaoNhat(head); break;
            case 2: timTinChiThapNhat(head); break;
            case 3: cout << "  Tong so tin chi      : " << tongTinChi(head) << "\n"; break;
            case 4: cout << "  So tin chi trung binh: " << fixed << setprecision(1) << trungBinhTinChi(head) << "\n"; break;
            case 5: cout << "  Tong so mon hoc      : " << demTongMH(head) << "\n"; break;
            case 6: thongKeMHTheoDieuKien(head); break;
        }
    } while (ch != 0);
}

static void menuMonHoc(NodeMH*& head) {
    int ch;
    do {
        inMenu("QUAN LY MON HOC", {
            "Nhap danh sach mon hoc",
            "In danh sach mon hoc",
            "Doc danh sach tu file",
            "Luu danh sach vao file",
            "Them mon hoc",
            "Sua mon hoc",
            "Xoa mon hoc",
            "Tim kiem",
            "Sap xep",
            "Thong ke / Tinh toan"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: {
                int n = docSoNguyen("Nhap so luong mon hoc: ");
                nhapDanhSachMH(head, n);
                break;
            }
            case 2:  inDanhSachMH(head); break;
            case 3:  docFileMH(head, FILE_MH); break;
            case 4:  luuFileMH(head, FILE_MH); break;
            case 5:  themMH(head); break;
            case 6:  suaMH(head); break;
            case 7:  xoaMH(head); break;
            case 8:  menuTimKiemMH(head); break;
            case 9:  menuSapXepMH(head); break;
            case 10: menuThongKeMH(head); break;
        }
    } while (ch != 0);
}

// ---- Main ----

int main() {
    NodeSV* dsSV = nullptr;
    NodeMH* dsMH = nullptr;

    taiFileSV(dsSV, FILE_SV);
    taiFileMH(dsMH, FILE_MH);

    int ch;
    do {
        inMenu("QUAN LY DIEM SINH VIEN", {
            "Quan ly Sinh Vien",
            "Quan ly Mon Hoc"
        });
        ch = docSoNguyen();
        switch (ch) {
            case 1: menuSinhVien(dsSV); break;
            case 2: menuMonHoc(dsMH);   break;
        }
    } while (ch != 0);

    xoaDanhSachSV(dsSV);
    xoaDanhSachMH(dsMH);
    cout << "Thoat chuong trinh.\n";
    return 0;
}
