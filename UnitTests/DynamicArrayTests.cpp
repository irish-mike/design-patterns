#include "pch.h"
#include "CppUnitTest.h"
#include "../DesignPatterns/Include/DataStructures/DynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTests
{
    TEST_CLASS(DynamicArrayTests)
    {
    public:

        TEST_METHOD(Insert_WithValidValue_UpdatesArray)
        {
            DynamicArray arr;

            arr.insert(-10);
            arr.insert(0);
            arr.insert(10);

            Assert::AreEqual(0, arr.indexOf(-10));
            Assert::AreEqual(1, arr.indexOf(0));
            Assert::AreEqual(2, arr.indexOf(10));
        }

        TEST_METHOD(Resize_WithInsertingMoreThanInitialSize_ExpandsArray)
        {
            DynamicArray arr;

            for (int i = 0; i < 15; i++) {
                arr.insert(i);
            }

            Assert::AreEqual(14, arr.indexOf(14));
        }
        TEST_METHOD(RemoveAt_WithValidIndex_RemovesElement)
        {
            DynamicArray arr;

            arr.insert(10);
            arr.insert(20);

            arr.removeAt(0);

            Assert::IsTrue(arr.indexOf(20) != 1);
            Assert::IsFalse(arr.indexOf(10) != -1);
        }

        TEST_METHOD(RemoveAt_WithInvalidIndex_ThrowsInvalidArgumentException)
        {
            try {
                DynamicArray dynamicArray;
                dynamicArray.insert(42);
                dynamicArray.removeAt(-1);
                Assert::Fail(L"Exception not thrown");
            }
            catch (const std::invalid_argument&) {
                // Exception expected
            }
        }

        TEST_METHOD(RemoveAt_FromEmptyArray_ThrowsOutOfRangeException)
        {
            try {
                DynamicArray dynamicArray;
                dynamicArray.removeAt(0);
                Assert::Fail(L"Exception not thrown");
            }
            catch (const std::out_of_range&) {
                // Exception expected
            }
        }
        TEST_METHOD(IndexOf_WithExistingValue_ReturnsCorrectIndex)
        {
            DynamicArray arr;
            arr.insert(10);
            arr.insert(20);

            Assert::AreEqual(1, arr.indexOf(20));
        }
        TEST_METHOD(IndexOf_WithNonExistingValue_ReturnsNegativeOne)
        {
            DynamicArray arr;
            arr.insert(10);

            Assert::AreEqual(-1, arr.indexOf(20));
        }
    };
}
