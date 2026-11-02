#include "pch.h"
#include "CppUnitTest.h"
#include "LongLong.h"
#include "Rational.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(LongLongTests)
    {
    public:

        TEST_METHOD(TestConstructor)
        {
            LongLong a(12345);
            Assert::IsTrue(a.ToInt64() == 12345);
        }

        TEST_METHOD(TestArithmetic)
        {
            LongLong a(20);
            LongLong b(5);

            Assert::IsTrue((a + b).ToInt64() == 25);
            Assert::IsTrue((a - b).ToInt64() == 15);
            Assert::IsTrue((a * b).ToInt64() == 100);
            Assert::IsTrue((a / b).ToInt64() == 4);
            Assert::IsTrue((a % b).ToInt64() == 0);
        }

        TEST_METHOD(TestComparison)
        {
            LongLong a(10);
            LongLong b(20);

            Assert::IsTrue(a < b);
            Assert::IsTrue(b > a);
            Assert::IsTrue(a != b);
            Assert::IsTrue(a == LongLong(10));
            Assert::IsTrue(a <= b);
            Assert::IsTrue(b >= a);
        }

        TEST_METHOD(TestToString)
        {
            LongLong a(123);

            Assert::IsTrue(a.toString() == "123");
        }
    };

    TEST_CLASS(RationalTests)
    {
    public:

        TEST_METHOD(TestConstructorAndReduction)
        {
            Rational a(2, 4);

            Assert::IsTrue(a.toString() == "1/2");
        }

        TEST_METHOD(TestAddition)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Assert::IsTrue(a.add(b).toString() == "5/6");
        }

        TEST_METHOD(TestSubtraction)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Assert::IsTrue(a.sub(b).toString() == "1/6");
        }

        TEST_METHOD(TestMultiplication)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Assert::IsTrue(a.mul(b).toString() == "1/6");
        }

        TEST_METHOD(TestDivision)
        {
            Rational a(1, 2);
            Rational b(1, 3);

            Assert::IsTrue(a.div(b).toString() == "3/2");
        }

        TEST_METHOD(TestComparison)
        {
            Rational a(1, 2);
            Rational b(2, 3);

            Assert::IsTrue(a.less(b));
            Assert::IsTrue(b.great(a));
            Assert::IsTrue(a.equal(Rational(2, 4)));
        }

        TEST_METHOD(TestInvalidDenominator)
        {
            Rational a;

            Assert::IsTrue(!a.Init(1, 0));
            Assert::IsTrue(!a.SetB(LongLong(0)));
        }
    };
}