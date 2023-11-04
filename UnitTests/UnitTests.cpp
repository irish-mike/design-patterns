#include "pch.h"
#include "CppUnitTest.h"
#include "../DesignPatterns/Include/DataStructures/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
    TEST_CLASS(LinkedListTests)
    {
    public:
        TEST_METHOD(AddFirst)
        {
            LinkedList list;

            list.addFirst(10);
            Assert::AreEqual((size_t)0, list.indexOf(10));

            list.addFirst(20);
            Assert::AreEqual((size_t)0, list.indexOf(20));
        }

        TEST_METHOD(AddLast)
        {
            LinkedList list;

            list.addLast(30);
            Assert::AreEqual((size_t)0, list.indexOf(30));

            list.addLast(40);
            Assert::AreEqual((size_t)1, list.indexOf(40));

        }

        TEST_METHOD(DeleteFirst)
        {
            LinkedList list;

            list.addFirst(50);
            Assert::AreEqual((size_t)0, list.indexOf(50));

            list.deleteFirst();
            Assert::IsFalse(list.contains(50));
        }

        TEST_METHOD(DeleteLast)
        {
            LinkedList list;

            list.addLast(60);
            Assert::IsTrue(list.contains(60));
            list.deleteLast();
            Assert::IsFalse(list.contains(60));
        }

        TEST_METHOD(IndexOf)
        {
            LinkedList list;

            list.addFirst(50);
            Assert::AreEqual((size_t)0, list.indexOf(50));
        }

        TEST_METHOD(Contains)
        {
            LinkedList list;

            list.addLast(100);
            list.addLast(200);
            list.addLast(300);
            Assert::IsTrue(list.contains(100));
            Assert::IsFalse(list.contains(4000));
        }

        TEST_METHOD(IsEmpty)
        {
            LinkedList list;

            Assert::IsTrue(list.isEmpty());
            list.addLast(10);
            Assert::IsFalse(list.isEmpty());
        }

        TEST_METHOD(DeleteFromEmptyList)
        {
            LinkedList list;
            try {
                list.deleteFirst();
                Assert::Fail(L"Exception not thrown");
            }
            catch (std::runtime_error&) {
                // Exception expected
            }
        }

        TEST_METHOD(DeleteLastFromOneElementList)
        {
            LinkedList list;
            list.addLast(10);
            list.deleteLast();
            Assert::IsTrue(list.isEmpty());
        }

        // Add more edge case tests as needed

    };
}
