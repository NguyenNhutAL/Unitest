#include "pch.h"
class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Hoán đổi giá trị của hai phần tử
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
TEST(TestArraySorter, TestArray) {
    int Array[5] = { 9,3,8,0,1 };
    ArraySorter Sort(Array, 5);
    Sort.BubbleSort();
    EXPECT_EQ(Array[0], 0);
    EXPECT_EQ(Array[1], 1);
    EXPECT_EQ(Array[2], 3);
    EXPECT_EQ(Array[3], 8);
    EXPECT_EQ(Array[4], 9);
}
