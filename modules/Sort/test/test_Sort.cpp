// Copyright 2017 Mitrokhin Nikita

#include <gtest/gtest.h>
#include <include/Sort.h>

TEST(Sort, Can_Compare_Result) {
    // Arrange
    const int N = 6;
    const int Array[N] = { 5, 2, 1, 4, 3, 6 };
    Sort Array1(Array, N);
    Sort Array2(Array, N);

    // Act
    const bool expected_true = Array1 == Array2;

    // Assert
    EXPECT_TRUE(expected_true);
}

TEST(Sort, Can_Compare_Result_False) {
    // Arrange
    const int N = 10;
    const int M = 5;
    const int Arr1[N] = { 3457, 7, 5, 12, 56, 4, 1, 33, 27, 1040 };
    const int Arr2[M] = { 5, 2, 1, 4, 3 };
    Sort Array1(Arr1, N);
    Sort Array2(Arr2, M);

    // Act
    const bool expected_false = Array1 == Array2;

    // Assert
    EXPECT_FALSE(expected_false);
}

TEST(Sort, Can_Do_Paste_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 23, 14, 12, 63, 127, 8, 412 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { 8, 12, 14, 23, 63, 127, 412 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 111, 2321, 15, 43, 927, 432, 1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 15, 43, 111, 432, 927, 2321 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Paste_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 23, 14, 23, 63, 14, 8, 8 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { 8, 8, 14, 14, 23, 23, 63 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 111, 43, 15, 43, 111, 42, 1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 15, 42, 43, 43, 111, 111 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -111, -2321, -15, -43, -927, -432, -1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { -2321, -927, -432, -111, -43, -15, -1 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Paste_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -23, -14, -3, -63, -4, -8, -18 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { -63, -23, -18, -14, -8, -4, -3 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}
