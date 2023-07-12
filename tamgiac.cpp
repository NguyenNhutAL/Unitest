#include "pch.h"
#include <algorithm>
enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}

TEST(TestTamGiac, TH1) {
    LoaiTamGiac TamGiac= XacDinhLoaiTamGiac(0, 1,1);
    EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}
TEST(TestTamGiac, TH2) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(1, 0, 1);
    EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}
TEST(TestTamGiac, TH3) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(1, 1, 0);
    EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}
TEST(TestTamGiac, TH4) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(1, 1, 1);
    EXPECT_EQ(TamGiac, TamGiacDeu);
}
TEST(TestTamGiac, TH5) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(2,2,1);
    EXPECT_EQ(TamGiac, TamGiacCan);
}
TEST(TestTamGiac, TH6) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(2, 1, 2);
    EXPECT_EQ(TamGiac, TamGiacCan);
}
TEST(TestTamGiac, TH7) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(1, 2, 2);
    EXPECT_EQ(TamGiac, TamGiacCan);
}
TEST(TestTamGiac, TH8) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(3,4,5);
    EXPECT_EQ(TamGiac, TamGiacVuong);
}
TEST(TestTamGiac, TH9) {
    LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(3, 5, 7);
    EXPECT_EQ(TamGiac, TamGiacThuong);
}
