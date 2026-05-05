#include "SinhVien.h"
#include <iomanip>
#include <algorithm>

float tinhDiemTB(float toan, float ly, float hoa) {
    return (toan + ly + hoa) / 3.0f;
}

string tinhXepLoai(float diemTB) {
    if (diemTB >= 8.0f) return "Gioi";
    if (diemTB >= 6.5f) return "Kha";
    if (diemTB >= 5.0f) return "Trung Binh";
    return "Yeu";
}

static SinhVien nhapMotSV() {
    SinhVien sv;
    cout << "  Ma SV    : "; cin >> sv.maSV;
    cin.ignore();
    cout << "  Ho ten   : "; getline(cin, sv.hoTen);
    cout << "  Ngay sinh: "; getline(cin, sv.ngaySinh);
    cout << "  Diem Toan: "; cin >> sv.diemToan;
    cout << "  Diem Ly  : "; cin >> sv.diemLy;
    cout << "  Diem Hoa : "; cin >> sv.diemHoa;
    cin.ignore();
    sv.diemTB   = tinhDiemTB(sv.diemToan, sv.diemLy, sv.diemHoa);
    sv.xepLoai  = tinhXepLoai(sv.diemTB);
    return sv;
}

static void inTieuDe() {
    cout << left
         << setw(8)  << "Ma SV"
         << setw(22) << "Ho Ten"
         << setw(12) << "Ngay Sinh"
         << setw(7)  << "Toan"
         << setw(7)  << "Ly"
         << setw(7)  << "Hoa"
         << setw(7)  << "TB"
         << setw(12) << "Xep Loai"
         << "\n";
    cout << string(82, '-') << "\n";
}

static void inMotSV(const SinhVien& sv) {
    cout << left
         << setw(8)  << sv.maSV
         << setw(22) << sv.hoTen
         << setw(12) << sv.ngaySinh
         << setw(7)  << fixed << setprecision(1) << sv.diemToan
         << setw(7)  << sv.diemLy
         << setw(7)  << sv.diemHoa
         << setw(7)  << sv.diemTB
         << setw(12) << sv.xepLoai
         << "\n";
}

void nhapDanhSachSV(NodeSV*& head, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        NodeSV* node = new NodeSV{ nhapMotSV(), nullptr };
        if (!head) {
            head = node;
        } else {
            NodeSV* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
    }
}

void inDanhSachSV(NodeSV* head) {
    if (!head) { cout << "  Danh sach trong.\n"; return; }
    inTieuDe();
    for (NodeSV* cur = head; cur; cur = cur->next)
        inMotSV(cur->data);
}

void taiFileSV(NodeSV*& head, const string& filename) {
    ifstream f(filename);
    if (!f) return;
    xoaDanhSachSV(head);
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        SinhVien sv;
        size_t p = 0, q;
        auto next = [&]() {
            q = line.find('|', p);
            string token = (q == string::npos) ? line.substr(p) : line.substr(p, q - p);
            p = (q == string::npos) ? line.size() : q + 1;
            return token;
        };
        sv.maSV     = next();
        sv.hoTen    = next();
        sv.ngaySinh = next();
        sv.diemToan = stof(next());
        sv.diemLy   = stof(next());
        sv.diemHoa  = stof(next());
        sv.diemTB   = tinhDiemTB(sv.diemToan, sv.diemLy, sv.diemHoa);
        sv.xepLoai  = tinhXepLoai(sv.diemTB);
        NodeSV* node = new NodeSV{ sv, nullptr };
        if (!head) { head = node; }
        else {
            NodeSV* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
    }
}

void docFileSV(NodeSV*& head, const string& filename) {
    ifstream f(filename);
    if (!f) { cout << "  Khong mo duoc file: " << filename << "\n"; return; }
    NodeSV* tmp = nullptr;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        SinhVien sv;
        size_t p = 0, q;
        auto next = [&]() {
            q = line.find('|', p);
            string token = (q == string::npos) ? line.substr(p) : line.substr(p, q - p);
            p = (q == string::npos) ? line.size() : q + 1;
            return token;
        };
        sv.maSV     = next();
        sv.hoTen    = next();
        sv.ngaySinh = next();
        sv.diemToan = stof(next());
        sv.diemLy   = stof(next());
        sv.diemHoa  = stof(next());
        sv.diemTB   = tinhDiemTB(sv.diemToan, sv.diemLy, sv.diemHoa);
        sv.xepLoai  = tinhXepLoai(sv.diemTB);
        NodeSV* node = new NodeSV{ sv, nullptr };
        if (!tmp) { tmp = node; }
        else {
            NodeSV* cur = tmp;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
    }
    cout << "  Da doc tu file: " << filename << "\n";
    inDanhSachSV(tmp);
    xoaDanhSachSV(tmp);
}

void luuFileSV(NodeSV* head, const string& filename) {
    ofstream f(filename);
    if (!f) { cout << "  Khong mo duoc file: " << filename << "\n"; return; }
    for (NodeSV* cur = head; cur; cur = cur->next) {
        const SinhVien& sv = cur->data;
        f << sv.maSV << "|" << sv.hoTen << "|" << sv.ngaySinh << "|"
          << sv.diemToan << "|" << sv.diemLy << "|" << sv.diemHoa << "\n";
    }
    cout << "  Da luu vao file: " << filename << "\n";
}

void themSV(NodeSV*& head) {
    cout << "Nhap thong tin sinh vien moi:\n";
    NodeSV* node = new NodeSV{ nhapMotSV(), nullptr };
    if (!head) { head = node; return; }
    NodeSV* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    cout << "  Da them sinh vien.\n";
}

void suaSV(NodeSV* head) {
    string ma;
    cout << "Nhap ma SV can sua: "; cin >> ma; cin.ignore();
    for (NodeSV* cur = head; cur; cur = cur->next) {
        if (cur->data.maSV == ma) {
            cout << "Nhap thong tin moi (bo trong de giu nguyen):\n";
            cout << "  Ho ten [" << cur->data.hoTen << "]: ";
            string s; getline(cin, s);
            if (!s.empty()) cur->data.hoTen = s;
            cout << "  Ngay sinh [" << cur->data.ngaySinh << "]: ";
            getline(cin, s);
            if (!s.empty()) cur->data.ngaySinh = s;
            cout << "  Diem Toan [" << cur->data.diemToan << "]: ";
            getline(cin, s);
            if (!s.empty()) cur->data.diemToan = stof(s);
            cout << "  Diem Ly [" << cur->data.diemLy << "]: ";
            getline(cin, s);
            if (!s.empty()) cur->data.diemLy = stof(s);
            cout << "  Diem Hoa [" << cur->data.diemHoa << "]: ";
            getline(cin, s);
            if (!s.empty()) cur->data.diemHoa = stof(s);
            cur->data.diemTB  = tinhDiemTB(cur->data.diemToan, cur->data.diemLy, cur->data.diemHoa);
            cur->data.xepLoai = tinhXepLoai(cur->data.diemTB);
            cout << "  Da cap nhat.\n";
            return;
        }
    }
    cout << "  Khong tim thay ma SV: " << ma << "\n";
}

void xoaSV(NodeSV*& head) {
    string ma;
    cout << "Nhap ma SV can xoa: "; cin >> ma; cin.ignore();
    NodeSV* cur = head;
    NodeSV* prev = nullptr;
    while (cur) {
        if (cur->data.maSV == ma) {
            if (prev) prev->next = cur->next;
            else      head = cur->next;
            delete cur;
            cout << "  Da xoa sinh vien " << ma << ".\n";
            return;
        }
        prev = cur; cur = cur->next;
    }
    cout << "  Khong tim thay ma SV: " << ma << "\n";
}

void timTheoMaSV(NodeSV* head) {
    string ma;
    cout << "Nhap ma SV can tim: "; cin >> ma; cin.ignore();
    bool found = false;
    for (NodeSV* cur = head; cur; cur = cur->next) {
        if (cur->data.maSV == ma) {
            inTieuDe(); inMotSV(cur->data);
            found = true;
        }
    }
    if (!found) cout << "  Khong tim thay.\n";
}

void timTheoHoTen(NodeSV* head) {
    string ten;
    cout << "Nhap ho ten (hoac phan ten) can tim: "; getline(cin, ten);
    bool found = false;
    for (NodeSV* cur = head; cur; cur = cur->next) {
        string ht = cur->data.hoTen;
        transform(ht.begin(), ht.end(), ht.begin(), ::tolower);
        string t  = ten;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        if (ht.find(t) != string::npos) {
            if (!found) inTieuDe();
            inMotSV(cur->data);
            found = true;
        }
    }
    if (!found) cout << "  Khong tim thay.\n";
}

static void bubbleSortSV(NodeSV*& head, auto cmp) {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        for (NodeSV* cur = head; cur->next; cur = cur->next) {
            if (cmp(cur->next->data, cur->data)) {
                swap(cur->data, cur->next->data);
                swapped = true;
            }
        }
    } while (swapped);
}

void sapXepTheoMaSV(NodeSV*& head) {
    bubbleSortSV(head, [](const SinhVien& a, const SinhVien& b){ return a.maSV < b.maSV; });
    cout << "  Da sap xep theo ma SV.\n";
}

void sapXepTheoHoTen(NodeSV*& head) {
    bubbleSortSV(head, [](const SinhVien& a, const SinhVien& b){ return a.hoTen < b.hoTen; });
    cout << "  Da sap xep theo ho ten.\n";
}

void sapXepTheoDiemTBTang(NodeSV*& head) {
    bubbleSortSV(head, [](const SinhVien& a, const SinhVien& b){ return a.diemTB < b.diemTB; });
    cout << "  Da sap xep theo diem TB tang dan.\n";
}

void sapXepTheoDiemTBGiam(NodeSV*& head) {
    bubbleSortSV(head, [](const SinhVien& a, const SinhVien& b){ return a.diemTB > b.diemTB; });
    cout << "  Da sap xep theo diem TB giam dan.\n";
}

static void inKetQuaMaxMin(const string& label, NodeSV* node) {
    if (!node) { cout << "  Danh sach trong.\n"; return; }
    cout << "  " << label << ":\n";
    inTieuDe(); inMotSV(node->data);
}

void timDiemTBCaoNhat(NodeSV* head) {
    NodeSV* best = nullptr;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (!best || cur->data.diemTB > best->data.diemTB) best = cur;
    inKetQuaMaxMin("SV co diem TB cao nhat", best);
}

void timDiemTBThapNhat(NodeSV* head) {
    NodeSV* best = nullptr;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (!best || cur->data.diemTB < best->data.diemTB) best = cur;
    inKetQuaMaxMin("SV co diem TB thap nhat", best);
}

void timDiemToanCaoNhat(NodeSV* head) {
    NodeSV* best = nullptr;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (!best || cur->data.diemToan > best->data.diemToan) best = cur;
    inKetQuaMaxMin("SV co diem Toan cao nhat", best);
}

void timDiemToanThapNhat(NodeSV* head) {
    NodeSV* best = nullptr;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (!best || cur->data.diemToan < best->data.diemToan) best = cur;
    inKetQuaMaxMin("SV co diem Toan thap nhat", best);
}

float tongDiemTB(NodeSV* head) {
    float tong = 0;
    for (NodeSV* cur = head; cur; cur = cur->next) tong += cur->data.diemTB;
    return tong;
}

float trungBinhDiemTB(NodeSV* head) {
    int n = demTongSV(head);
    return n ? tongDiemTB(head) / n : 0;
}

int demTongSV(NodeSV* head) {
    int n = 0;
    for (NodeSV* cur = head; cur; cur = cur->next) n++;
    return n;
}

int demSVDat(NodeSV* head) {
    int n = 0;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (cur->data.diemTB >= 5.0f) n++;
    return n;
}

int demSVGioi(NodeSV* head) {
    int n = 0;
    for (NodeSV* cur = head; cur; cur = cur->next)
        if (cur->data.diemTB >= 8.0f) n++;
    return n;
}

void thongKeXepLoai(NodeSV* head) {
    int gioi = 0, kha = 0, tb = 0, yeu = 0;
    for (NodeSV* cur = head; cur; cur = cur->next) {
        const string& xl = cur->data.xepLoai;
        if (xl == "Gioi")       gioi++;
        else if (xl == "Kha")   kha++;
        else if (xl == "Trung Binh") tb++;
        else                    yeu++;
    }
    cout << "  Gioi (TB>=8.0)        : " << gioi << " SV\n";
    cout << "  Kha  (6.5<=TB<8.0)   : " << kha  << " SV\n";
    cout << "  Trung Binh (5<=TB<6.5): " << tb   << " SV\n";
    cout << "  Yeu  (TB<5.0)        : " << yeu  << " SV\n";
}

void thongKeSVTheoDieuKien(NodeSV* head) {
    int ch;
    do {
        cout << "\nChon dieu kien thong ke:\n"
             << "  1. SV xep loai Gioi\n"
             << "  2. SV xep loai Kha\n"
             << "  3. SV xep loai Trung Binh\n"
             << "  4. SV xep loai Yeu\n"
             << "  5. SV co diem Toan >= nguong X\n"
             << "  0. Quay lai\n"
             << "Lua chon: ";

        cin >> ch; cin.ignore();

        string label, loai;
        float nguong = 0;
        bool byLoai = true;

        switch (ch) {
            case 1: loai = "Gioi";       label = "SV xep loai Gioi"; break;
            case 2: loai = "Kha";        label = "SV xep loai Kha"; break;
            case 3: loai = "Trung Binh"; label = "SV xep loai Trung Binh"; break;
            case 4: loai = "Yeu";        label = "SV xep loai Yeu"; break;

            case 5:
                byLoai = false;
                cout << "Nhap nguong diem Toan: ";
                cin >> nguong; cin.ignore();
                label = "SV co diem Toan >= " + to_string((int)nguong);
                break;

            case 0:
                return;

            default:
                cout << "  Lua chon khong hop le.\n";
                continue; // quay lại menu con luôn
        }

        cout << "\n  " << label << ":\n";
        inTieuDe();

        int count = 0;
        for (NodeSV* cur = head; cur; cur = cur->next) {
            bool match = byLoai ? (cur->data.xepLoai == loai)
                                : (cur->data.diemToan >= nguong);
            if (match) {
                inMotSV(cur->data);
                count++;
            }
        }

        if (!count) cout << "  (Khong co sinh vien nao)\n";
        else cout << "  Tong: " << count << " sinh vien.\n";

    } while (true);
}

void xoaDanhSachSV(NodeSV*& head) {
    while (head) {
        NodeSV* tmp = head;
        head = head->next;
        delete tmp;
    }
}
