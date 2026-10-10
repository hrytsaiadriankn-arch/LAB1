#include "pch.h"
#include "CppUnitTest.h"
#include "D:/2 курс 1 семестр/LAB 1.6/Project1/Real.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestRoot)
        {
            Real r;
            Real::Number n;
            n.Init(27);
            r.Init(n);

            Assert::AreEqual(3.0, r.Root(3), 0.0001);
        }

        TEST_METHOD(TestSquareRoot)
        {
            Real r;
            Real::Number n;
            n.Init(25);
            r.Init(n);

            Assert::AreEqual(5.0, r.Root(2), 0.0001);
        }

        TEST_METHOD(TestPiPower)
        {
            Real r;
            Real::Number n;
            n.Init(0);
            r.Init(n);

            Assert::AreEqual(9.8696044, r.PiPower(2), 0.0001);
        }

        TEST_METHOD(TestNegativeRoot)
        {
            Real r;
            Real::Number n;
            n.Init(-8);
            r.Init(n);

            Assert::AreEqual(-2.0, r.Root(3), 0.0001);
        }

        TEST_METHOD(TestInvalidRoot)
        {
            Real r;
            Real::Number n;
            n.Init(-16);
            r.Init(n);

            Assert::IsTrue(std::isnan(r.Root(2)));
        }
    };
}
