#!/bin/bash
# Comprehensive test: SinhVien + MonHoc - all menu features

rm -f sinhvien.txt monhoc.txt

PASS=0
FAIL=0

check() {
    local name="$1" expected="$2"
    if echo "$OUTPUT" | grep -qF "$expected"; then
        echo "  PASS: $name"
        ((PASS++))
    else
        echo "  FAIL: $name  (expected: '$expected')"
        ((FAIL++))
    fi
}

OUTPUT=$(./qldsv <<'EOF'
1
1
3
SV001
Nguyen Van An
01/01/2003
8.5
7.0
9.0
SV002
Tran Thi Bich
15/03/2002
7.0
6.0
7.0
SV003
Le Van Cuong
20/05/2001
4.0
3.5
5.0
2
4
5
SV004
Pham Thi Dao
10/10/2000
6.0
7.5
6.0
6
SV001




10.0
2
7
SV004
2
9
1
2
3
4
0
8
1
SV002
2
Cuong
0
10
1
2
3
4
5
6
7
8
9
10
11
1
0
4
3
2
0
2
1
2
MH001
Toan cao cap
4
MH002
Vat ly dai cuong
3
2
4
5
MH003
Hoa hoc co so
2
6
MH002
Vat ly nang cao
4
2
7
MH003
2
9
1
2
3
4
0
8
1
MH001
2
Toan
0
10
1
2
3
4
5
6
3
0
3
2
0
0
EOF
)

echo "=== SINH VIEN ==="

echo "-- Nhap / in danh sach --"
check "nhap SV001"              "SV001"
check "nhap SV002"              "SV002"
check "nhap SV003"              "SV003"
check "tinh xep loai Gioi"      "Gioi"
check "tinh xep loai Yeu"       "Yeu"

echo "-- Luu file --"
check "luu file SV"             "Da luu vao file: sinhvien.txt"

echo "-- Them SV --"
check "them SV004 Pham Thi Dao" "Pham Thi Dao"

echo "-- Sua SV --"
check "sua SV001 cap nhat"      "Da cap nhat"

echo "-- Kha sau sua SV002 --"
check "tinh xep loai Kha"       "Kha"

echo "-- Xoa SV --"
check "xoa SV004"               "Da xoa sinh vien SV004"

echo "-- Sap xep --"
check "sap xep theo ma SV"      "Da sap xep theo ma SV"
check "sap xep theo ho ten"     "Da sap xep theo ho ten"
check "sap xep theo TB tang"    "Da sap xep theo diem TB tang dan"
check "sap xep theo TB giam"    "Da sap xep theo diem TB giam dan"

echo "-- Tim kiem --"
check "tim theo ma SV002"       "Tran Thi Bich"
check "tim theo ho ten Cuong"   "Le Van Cuong"

echo "-- Thong ke --"
check "TB cao nhat"             "SV co diem TB cao nhat"
check "TB thap nhat"            "SV co diem TB thap nhat"
check "Toan cao nhat"           "SV co diem Toan cao nhat"
check "Toan thap nhat"          "SV co diem Toan thap nhat"
check "tong diem TB ca lop"     "Tong diem TB ca lop"
check "diem TB trung binh"      "Diem TB trung binh"
check "dem tong SV: 3"          "Tong so sinh vien  : 3"
check "dem SV dat: 2"           "So SV dat (TB>=5.0): 2"
check "dem SV Gioi: 1"          "So SV Gioi (TB>=8.0): 1"
check "xep loai Gioi: 1 SV"     "Gioi (TB>=8.0)        : 1 SV"
check "xep loai Kha: 1 SV"      "Kha  (6.5<=TB<8.0)   : 1 SV"
check "xep loai Yeu: 1 SV"      "Yeu  (TB<5.0)        : 1 SV"
check "dieu kien: Gioi label"   "SV xep loai Gioi"

echo "-- Doc file --"
check "doc file SV"             "Da doc tu file: sinhvien.txt"

echo ""
echo "=== MON HOC ==="

echo "-- Nhap / in danh sach --"
check "nhap MH001 Toan cao cap"     "Toan cao cap"
check "nhap MH002 Vat ly dai cuong" "Vat ly dai cuong"

echo "-- Luu file --"
check "luu file MH"                 "Da luu vao file: monhoc.txt"

echo "-- Them MH --"
check "them MH003 Hoa hoc co so"    "Hoa hoc co so"

echo "-- Sua MH --"
check "sua MH002 Vat ly nang cao"   "Vat ly nang cao"
check "sua MH002 cap nhat"          "Da cap nhat"

echo "-- Xoa MH --"
check "xoa MH003"                   "Da xoa mon hoc MH003"

echo "-- Sap xep --"
check "sap xep theo ma MH"          "Da sap xep theo ma MH"
check "sap xep theo ten MH"         "Da sap xep theo ten MH"
check "sap xep theo tin chi tang"   "Da sap xep theo so tin chi tang dan"
check "sap xep theo tin chi giam"   "Da sap xep theo so tin chi giam dan"

echo "-- Tim kiem --"
check "tim theo ma MH001"           "Toan cao cap"
check "tim theo ten Toan"           "Toan cao cap"

echo "-- Thong ke --"
check "tin chi cao nhat"            "Mon hoc co so tin chi cao nhat"
check "tin chi thap nhat"           "Mon hoc co so tin chi thap nhat"
check "tong tin chi: 8"             "Tong so tin chi      : 8"
check "TB tin chi: 4.0"             "So tin chi trung binh: 4.0"
check "dem tong MH: 2"              "Tong so mon hoc      : 2"
check "theo dieu kien tin chi"      "Mon hoc co so tin chi >= 3"

echo "-- Doc file --"
check "doc file MH"                 "Da doc tu file: monhoc.txt"

echo ""
echo "-- Thoat --"
check "thoat chuong trinh"          "Thoat chuong trinh"

echo ""
echo "=== KET QUA: PASS=$PASS  FAIL=$FAIL / $((PASS + FAIL)) ==="
[ "$FAIL" -eq 0 ] && exit 0 || exit 1
