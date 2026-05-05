# Hệ Thống Quản Lý Điểm Sinh Viên

## Giới Thiệu

Đây là **Bài Tập Lớn (BTL) - Cấu Trúc Dữ Liệu và Giải Thuật** - một ứng dụng quản lý điểm sinh viên được xây dựng bằng **C++** với cấu trúc dữ liệu **Danh sách liên kết đơn (Linked List)**. Ứng dụng cung cấp các chức năng toàn diện để quản lý thông tin sinh viên, điểm số, và các môn học.

## Cấu Trúc Dự Án

```
CTDL_BTL_04/
│
├── Source Code (Mã nguồn)
│   ├── main.cpp              # File chương trình chính - Menu quản lý
│   ├── SinhVien.h            # Header - Khai báo hàm quản lý sinh viên
│   ├── SinhVien.cpp          # Implementation - Cài đặt tất cả chức năng SV
│   ├── MonHoc.h              # Header - Khai báo hàm quản lý môn học
│   └── MonHoc.cpp            # Implementation - Cài đặt tất cả chức năng MH
│
├── Data Files (File dữ liệu)
│   ├── sinhvien.txt          # Dữ liệu sinh viên (format: maSV|tên|...)
│   └── monhoc.txt            # Dữ liệu môn học (format: maMH|tên|...)
│
├── Test & Build
│   ├── test.sh               # Script test tự động toàn bộ chức năng
│   └── qldsv                 # Executable (file chạy sau khi biên dịch)
│
└── Documentation
    └── README.md             # File hướng dẫn này
```

### Chi Tiết Các Module

**SinhVien Module** (SinhVien.h/cpp):
- Cấu trúc: `struct SinhVien` + `struct NodeSV` (Linked List node)
- Chức năng: Nhập, in, lưu/tải file, thêm/sửa/xóa, tìm kiếm, sắp xếp, thống kê

**MonHoc Module** (MonHoc.h/cpp):
- Cấu trúc: `struct MonHoc` + `struct NodeMH` (Linked List node)
- Chức năng: Nhập, in, lưu/tải file, thêm/sửa/xóa, tìm kiếm, sắp xếp, thống kê

**Main Program** (main.cpp):
- Menu chính cấp 1: Quản lý Sinh Viên / Quản lý Môn Học
- Menu cấp 2 cho SV: Nhập, In, File, CRUD, Tìm kiếm, Sắp xếp, Thống kê
- Menu cấp 3 cho MH: Nhập, In, File, CRUD, Tìm kiếm, Sắp xếp, Thống kê

---

## Tính Năng Chính

### Quản Lý Sinh Viên

1. **Nhập/In danh sách** - Thêm mới sinh viên hoặc hiển thị danh sách
2. **Lưu/Đọc file** - Lưu trữ và tải dữ liệu từ file
3. **Thêm/Sửa/Xóa** - CRUD operations cơ bản
4. **Tìm kiếm** - Tìm theo mã SV và họ tên
5. **Sắp xếp** - Theo mã SV, tên, điểm TB tăng/giảm
6. **Tìm cực trị** - Điểm TB cao/thấp nhất, Toán cao/thấp nhất
7. **Thống kê** - Tổng điểm TB, trung bình điểm, đếm SV
8. **Phân loại** - SV đạt (≥5.0), Giỏi (≥8.0), theo xếp loại
9. **Điều kiện** - Thống kê theo nhiều điều kiện khác nhau

### Quản Lý Môn Học

1. **Quản lý danh sách môn học**
2. **Thêm/Sửa/Xóa môn học**
3. **Tìm kiếm** - Theo mã MH và tên MH
4. **Sắp xếp** - Theo mã, tên, tín chỉ tăng/giảm
5. **Tìm cực trị** - Tín chỉ cao/thấp nhất
6. **Tính toán** - Tổng tín chỉ, trung bình tín chỉ, đếm môn
7. **Thống kê** - Theo ngưỡng tín chỉ

---

## Cách Chạy Dự Án

### Yêu Cầu

- **Compiler**: G++ (GCC) hoặc bất kỳ C++ compiler nào hỗ trợ C++11 trở lên
- **OS**: Linux, macOS, hoặc Windows (với MinGW)

### 1. Biên Dịch

```bash
# Biên dịch toàn bộ dự án
g++ -o qldsv main.cpp SinhVien.cpp MonHoc.cpp

# Hoặc với cờ tối ưu
g++ -O2 -o qldsv main.cpp SinhVien.cpp MonHoc.cpp
```

### 2. Chạy Ứng Dụng

```bash
# Chạy chương trình
./qldsv
```

### 3. Chạy Test

```bash
# Cấp quyền thực thi cho script test
chmod +x test.sh

# Chạy các test tự động
./test.sh
```

---

## Hướng Dẫn Sử Dụng

Khi khởi động ứng dụng, bạn sẽ thấy menu chính:

```
========== QUAN LY DIEM SINH VIEN ==========
  1. Quan ly Sinh Vien
  2. Quan ly Mon Hoc
  0. Quay lai / Thoat
Lua chon:
```

### Ví Dụ: Thêm Sinh Viên

```
1. Quan ly Sinh Vien
→ 1. Nhap danh sach sinh vien
→ 5. Them sinh vien
  Ma SV    : SV001
  Ho ten   : Nguyen Van An
  Ngay sinh: 01/01/2003
  Diem Toan: 8.5
  Diem Ly  : 7.0
  Diem Hoa : 9.0
```

---

## Format Dữ Liệu

### sinhvien.txt

```
maSV|hoTen|ngaySinh|diemToan|diemLy|diemHoa
01|hoa|1/1/2000|8|8|9
```

### monhoc.txt

```
maMH|tenMH|soTinChi
MH001|Toan cao cap|4
MH002|Vat ly dai cuong|3
```

---

## Cấu Trúc Dữ Liệu

### Struct SinhVien

```cpp
struct SinhVien {
    string maSV;        // Mã sinh viên
    string hoTen;       // Họ tên
    string ngaySinh;    // Ngày sinh
    float diemToan;     // Điểm Toán
    float diemLy;       // Điểm Lý
    float diemHoa;      // Điểm Hóa
    float diemTB;       // Điểm trung bình
    string xepLoai;     // Xếp loại (Giỏi/Khá/Trung Bình/Yếu)
};
```

### Struct MonHoc

```cpp
struct MonHoc {
    string maMH;        // Mã môn học
    string tenMH;       // Tên môn học
    int soTinChi;       // Số tín chỉ
};
```

---

## Tiêu Chí Xếp Loại

| Xếp Loại       | Điểm Trung Bình |
| -------------- | --------------- |
| **Giỏi**       | ≥ 8.0           |
| **Khá**        | 6.5 - 7.9       |
| **Trung Bình** | 5.0 - 6.4       |
| **Yếu**        | < 5.0           |

---

## Ghi Chú

- Dữ liệu được lưu trữ trong file text với định dạng phân cách bằng `|`
- Sử dụng Linked List để quản lý dữ liệu động
- Bubble Sort được dùng để sắp xếp dữ liệu
- Tất cả hàm xử lý lỗi input hợp lệ

---

## Troubleshooting

### Lỗi biên dịch

Nếu gặp lỗi khi biên dịch, đảm bảo:

- Tất cả các file `.h` và `.cpp` nằm cùng thư mục
- Compiler hỗ trợ C++11 trở lên
- Không có lỗi syntax trong code

### File không tìm thấy

- Đảm bảo chạy lệnh từ thư mục chứa source code
- Sau khi biên dịch, file dữ liệu sẽ được tạo tự động nếu chưa tồn tại

---

## Thông Tin Phát Triển

- **Ngôn ngữ**: C++11
- **Cấu trúc dữ liệu**: Danh sách liên kết đơn (Singly Linked List)
- **Thuật toán sắp xếp**: Bubble Sort
- **Định dạng file**: Text (phân cách bằng `|`)
- **Loại bài tập**: Bài Tập Lớn (BTL) - Cấu Trúc Dữ Liệu và Giải Thuật

---

## Danh Sách Kiểm Tra Yêu Cầu

Các yêu cầu đề bài BTL và tính năng tương ứng:

| Yêu Cầu                              | Tính Năng                                   | Trạng Thái |
| ------------------------------------ | ------------------------------------------- | ---------- |
| Tổ chức bằng Linked List             | Dùng NodeSV, NodeMH                         | ✓          |
| Quản lý 2+ đối tượng                 | SinhVien + MonHoc                           | ✓          |
| Nhập - In danh sách                  | Menu 1,2 (SV/MH)                            | ✓          |
| Đọc - Lưu file                       | Menu 3,4 (SV/MH)                            | ✓          |
| Thêm - Sửa - Xóa                     | Menu 5,6,7 (SV/MH)                          | ✓          |
| Tìm kiếm (2+ yêu cầu)                | Mã SV, Tên SV, Mã MH, Tên MH                | ✓          |
| Sắp xếp (4+ yêu cầu)                 | Mã, Tên, Điểm TB, Tín chỉ                   | ✓          |
| Cực trị (4+ yêu cầu)                 | TB max/min, Toán max/min, TinChi max/min    | ✓          |
| Tính toán (5+ yêu cầu)               | Tổng, TB, Đếm SV, Đếm MH, Đếm Tín chỉ       | ✓          |
| Thống kê theo điều kiện (5+ yêu cầu) | Xếp loại, SV đạt, Giỏi, Yếu, Theo điều kiện | ✓          |
| Menu chính gọi hàm                   | main() gọi menu lần lượt                    | ✓          |

---
