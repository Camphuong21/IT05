#include "MonHoc.h"
#include <iomanip>

static MonHoc nhapMotMH() {
    MonHoc mh;
    cout << "  Ma MH      : "; cin >> mh.maMH; cin.ignore();
    cout << "  Ten MH     : "; getline(cin, mh.tenMH);
    cout << "  So tin chi : "; cin >> mh.soTinChi; cin.ignore();
    return mh;
}

static void inTieuDeMH() {
    cout << left
         << setw(10) << "Ma MH"
         << setw(30) << "Ten Mon Hoc"
         << setw(12) << "So Tin Chi"
         << "\n";
    cout << string(52, '-') << "\n";
}

static void inMotMH(const MonHoc& mh) {
    cout << left
         << setw(10) << mh.maMH
         << setw(30) << mh.tenMH
         << setw(12) << mh.soTinChi
         << "\n";
}

static void appendMH(NodeMH*& head, MonHoc mh) {
    NodeMH* node = new NodeMH{ mh, nullptr };
    if (!head) { head = node; return; }
    NodeMH* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

void nhapDanhSachMH(NodeMH*& head, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Mon hoc " << i + 1 << ":\n";
        appendMH(head, nhapMotMH());
    }
}

void inDanhSachMH(NodeMH* head) {
    if (!head) { cout << "  Danh sach trong.\n"; return; }
    inTieuDeMH();
    for (NodeMH* cur = head; cur; cur = cur->next)
        inMotMH(cur->data);
}

void taiFileMH(NodeMH*& head, const string& filename) {
    ifstream f(filename);
    if (!f) return;
    xoaDanhSachMH(head);
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        MonHoc mh;
        size_t p = 0, q;
        auto next = [&]() {
            q = line.find('|', p);
            string token = (q == string::npos) ? line.substr(p) : line.substr(p, q - p);
            p = (q == string::npos) ? line.size() : q + 1;
            return token;
        };
        mh.maMH     = next();
        mh.tenMH    = next();
        mh.soTinChi = stoi(next());
        appendMH(head, mh);
    }
}

void docFileMH(NodeMH*& head, const string& filename) {
    ifstream f(filename);
    if (!f) { cout << "  Khong mo duoc file: " << filename << "\n"; return; }
    NodeMH* tmp = nullptr;
    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;
        MonHoc mh;
        size_t p = 0, q;
        auto next = [&]() {
            q = line.find('|', p);
            string token = (q == string::npos) ? line.substr(p) : line.substr(p, q - p);
            p = (q == string::npos) ? line.size() : q + 1;
            return token;
        };
        mh.maMH     = next();
        mh.tenMH    = next();
        mh.soTinChi = stoi(next());
        appendMH(tmp, mh);
    }
    cout << "  Da doc tu file: " << filename << "\n";
    inDanhSachMH(tmp);
    xoaDanhSachMH(tmp);
}

void luuFileMH(NodeMH* head, const string& filename) {
    ofstream f(filename);
    if (!f) { cout << "  Khong mo duoc file: " << filename << "\n"; return; }
    for (NodeMH* cur = head; cur; cur = cur->next)
        f << cur->data.maMH << "|" << cur->data.tenMH << "|" << cur->data.soTinChi << "\n";
    cout << "  Da luu vao file: " << filename << "\n";
}

void themMH(NodeMH*& head) {
    cout << "Nhap thong tin mon hoc moi:\n";
    appendMH(head, nhapMotMH());
    cout << "  Da them mon hoc.\n";
}

void suaMH(NodeMH* head) {
    string ma;
    cout << "Nhap ma MH can sua: "; cin >> ma; cin.ignore();
    for (NodeMH* cur = head; cur; cur = cur->next) {
        if (cur->data.maMH == ma) {
            cout << "  Ten MH [" << cur->data.tenMH << "]: ";
            string s; getline(cin, s);
            if (!s.empty()) cur->data.tenMH = s;
            cout << "  So tin chi [" << cur->data.soTinChi << "]: ";
            getline(cin, s);
            if (!s.empty()) cur->data.soTinChi = stoi(s);
            cout << "  Da cap nhat.\n";
            return;
        }
    }
    cout << "  Khong tim thay ma MH: " << ma << "\n";
}

void xoaMH(NodeMH*& head) {
    string ma;
    cout << "Nhap ma MH can xoa: "; cin >> ma; cin.ignore();
    NodeMH* cur = head, *prev = nullptr;
    while (cur) {
        if (cur->data.maMH == ma) {
            if (prev) prev->next = cur->next;
            else      head = cur->next;
            delete cur;
            cout << "  Da xoa mon hoc " << ma << ".\n";
            return;
        }
        prev = cur; cur = cur->next;
    }
    cout << "  Khong tim thay ma MH: " << ma << "\n";
}

void timTheoMaMH(NodeMH* head) {
    string ma;
    cout << "Nhap ma MH can tim: "; cin >> ma; cin.ignore();
    bool found = false;
    for (NodeMH* cur = head; cur; cur = cur->next) {
        if (cur->data.maMH == ma) {
            if (!found) inTieuDeMH();
            inMotMH(cur->data);
            found = true;
        }
    }
    if (!found) cout << "  Khong tim thay.\n";
}

void timTheoTenMH(NodeMH* head) {
    string ten;
    cout << "Nhap ten (hoac phan ten) can tim: "; getline(cin, ten);
    bool found = false;
    for (NodeMH* cur = head; cur; cur = cur->next) {
        if (cur->data.tenMH.find(ten) != string::npos) {
            if (!found) inTieuDeMH();
            inMotMH(cur->data);
            found = true;
        }
    }
    if (!found) cout << "  Khong tim thay.\n";
}

static void bubbleSortMH(NodeMH*& head, auto cmp) {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        for (NodeMH* cur = head; cur->next; cur = cur->next) {
            if (cmp(cur->next->data, cur->data)) {
                swap(cur->data, cur->next->data);
                swapped = true;
            }
        }
    } while (swapped);
}

void sapXepTheoMaMH(NodeMH*& head) {
    bubbleSortMH(head, [](const MonHoc& a, const MonHoc& b){ return a.maMH < b.maMH; });
    cout << "  Da sap xep theo ma MH.\n";
}

void sapXepTheoTenMH(NodeMH*& head) {
    bubbleSortMH(head, [](const MonHoc& a, const MonHoc& b){ return a.tenMH < b.tenMH; });
    cout << "  Da sap xep theo ten MH.\n";
}

void sapXepTheoTinChiTang(NodeMH*& head) {
    bubbleSortMH(head, [](const MonHoc& a, const MonHoc& b){ return a.soTinChi < b.soTinChi; });
    cout << "  Da sap xep theo so tin chi tang dan.\n";
}

void sapXepTheoTinChiGiam(NodeMH*& head) {
    bubbleSortMH(head, [](const MonHoc& a, const MonHoc& b){ return a.soTinChi > b.soTinChi; });
    cout << "  Da sap xep theo so tin chi giam dan.\n";
}

void timTinChiCaoNhat(NodeMH* head) {
    if (!head) { cout << "  Danh sach trong.\n"; return; }
    NodeMH* best = head;
    for (NodeMH* cur = head->next; cur; cur = cur->next)
        if (cur->data.soTinChi > best->data.soTinChi) best = cur;
    cout << "  Mon hoc co so tin chi cao nhat:\n";
    inTieuDeMH(); inMotMH(best->data);
}

void timTinChiThapNhat(NodeMH* head) {
    if (!head) { cout << "  Danh sach trong.\n"; return; }
    NodeMH* best = head;
    for (NodeMH* cur = head->next; cur; cur = cur->next)
        if (cur->data.soTinChi < best->data.soTinChi) best = cur;
    cout << "  Mon hoc co so tin chi thap nhat:\n";
    inTieuDeMH(); inMotMH(best->data);
}

int tongTinChi(NodeMH* head) {
    int tong = 0;
    for (NodeMH* cur = head; cur; cur = cur->next) tong += cur->data.soTinChi;
    return tong;
}

float trungBinhTinChi(NodeMH* head) {
    int n = demTongMH(head);
    return n ? (float)tongTinChi(head) / n : 0;
}

int demTongMH(NodeMH* head) {
    int n = 0;
    for (NodeMH* cur = head; cur; cur = cur->next) n++;
    return n;
}

void thongKeMHTheoDieuKien(NodeMH* head) {
    int nguong;
    cout << "Nhap nguong so tin chi can thong ke (>= nguong): "; cin >> nguong; cin.ignore();
    cout << "  Mon hoc co so tin chi >= " << nguong << ":\n";
    inTieuDeMH();
    int count = 0;
    for (NodeMH* cur = head; cur; cur = cur->next) {
        if (cur->data.soTinChi >= nguong) { inMotMH(cur->data); count++; }
    }
    if (!count) cout << "  (Khong co mon hoc nao)\n";
    else cout << "  Tong: " << count << " mon hoc.\n";
}

void xoaDanhSachMH(NodeMH*& head) {
    while (head) {
        NodeMH* tmp = head;
        head = head->next;
        delete tmp;
    }
}
