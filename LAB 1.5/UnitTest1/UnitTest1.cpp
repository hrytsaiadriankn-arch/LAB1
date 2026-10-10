#include "pch.h"
#include "CppUnitTest.h"
#include "D:/2 курс 1 семестр/LAB 1.5/Project1/Number.h"
#include "D:/2 курс 1 семестр/LAB 1.5/Project1/Real.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMultiply)
        {
            Number n;
            n.Init(8.0);
            n.Multiply(3.0);

            Assert::AreEqual(24.0, n.getValue(), 0.0001);
        }

        TEST_METHOD(TestSubtract)
        {
            Number n;
            n.Init(24.0);
            n.Subtract(4.0);

            Assert::AreEqual(20.0, n.getValue(), 0.0001);
        }

        TEST_METHOD(TestRoot)
        {
            Number n;
            n.Init(8.0);

            Real r;
            r.Init(n);

            Assert::AreEqual(2.0, r.Root(3), 0.0001);
        }

        TEST_METHOD(TestRootNegativeNumber)
        {
            Number n;
            n.Init(-8.0);

            Real r;
            r.Init(n);

            Assert::AreEqual(-2.0, r.Root(3), 0.0001);
        }

        TEST_METHOD(TestRootInvalidDegree)
        {
            Number n;
            n.Init(8.0);

            Real r;
            r.Init(n);

            Assert::IsTrue(std::isnan(r.Root(0)));
        }

        TEST_METHOD(TestPiPower)
        {
            Number n;
            n.Init(8.0);

            Real r;
            r.Init(n);

            Assert::AreEqual(9.8696044011, r.PiPower(2), 0.0001);
        }
    };
}
