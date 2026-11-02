#include "pch.h"
#include "CppUnitTest.h"

#include "D:/2 курс 1 семестр/LAB 1.8/Project1/Rational.h"
#include "D:/2 курс 1 семестр/LAB 1.8/Project1/LongLong.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestRationalInit)
        {
            Rational r(2, 4);

            Assert::AreEqual((int64_t)1, r.GetNumerator());
            Assert::AreEqual((int64_t)2, r.GetDenominator());
        }

        TEST_METHOD(TestRationalAddition)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Rational result = a.add(b);

            Assert::AreEqual((int64_t)5, result.GetNumerator());
            Assert::AreEqual((int64_t)6, result.GetDenominator());
        }

        TEST_METHOD(TestRationalSubtraction)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Rational result = a.sub(b);

            Assert::AreEqual((int64_t)1, result.GetNumerator());
            Assert::AreEqual((int64_t)6, result.GetDenominator());
        }

        TEST_METHOD(TestRationalMultiplication)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Rational result = a.mul(b);

            Assert::AreEqual((int64_t)1, result.GetNumerator());
            Assert::AreEqual((int64_t)6, result.GetDenominator());
        }

        TEST_METHOD(TestRationalDivision)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Rational result = a.div(b);

            Assert::AreEqual((int64_t)3, result.GetNumerator());
            Assert::AreEqual((int64_t)2, result.GetDenominator());
        }

        TEST_METHOD(TestRationalComparison)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Assert::IsFalse(a.equal(b));
            Assert::IsTrue(a.great(b));
            Assert::IsFalse(a.less(b));
        }

        TEST_METHOD(TestRationalNegativeDenominator)
        {
            Rational r(1, -2);

            Assert::AreEqual((int64_t)-1, r.GetNumerator());
            Assert::AreEqual((int64_t)2, r.GetDenominator());
        }

        TEST_METHOD(TestLongLongAddition)
        {
            LongLong a(10);
            LongLong b(20);

            LongLong result = a + b;

            Assert::AreEqual((int64_t)30, result.GetValue());
        }

        TEST_METHOD(TestLongLongSubtraction)
        {
            LongLong a(20);
            LongLong b(10);

            LongLong result = a - b;

            Assert::AreEqual((int64_t)10, result.GetValue());
        }

        TEST_METHOD(TestLongLongComparison)
        {
            LongLong a(20);
            LongLong b(10);

            Assert::IsTrue(a > b);
            Assert::IsFalse(a < b);
            Assert::IsFalse(a == b);
        }
    };
}
