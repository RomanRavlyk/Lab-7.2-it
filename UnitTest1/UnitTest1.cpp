#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.2 it/Lab 7.2 it.cpp" // ϳ�������� ��� �������� ����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int n = 5;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];
            Create(a, n, 7, 65);

            // �������� ���� ������� (SearchEl) � ��������� �����
            int minAboveSecondaryDiagonal, maxBelowSecondaryDiagonal, sum;
            SearchEl(a, n, minAboveSecondaryDiagonal, maxBelowSecondaryDiagonal, sum);

            // ���������, �� ��������� ������� ����������� ����������
            Assert::AreEqual(7, minAboveSecondaryDiagonal);
            Assert::AreEqual(63, maxBelowSecondaryDiagonal);
            Assert::AreEqual(70, sum);

            // ��������� ������� ���'��
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
