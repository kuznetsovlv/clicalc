#include "test.h"
#include "cmath"

#include "../src/stack.h"
#include "../src/simpleValueBuilder.h"

using namespace CppUnit;
using namespace std;

class TestSimpleValueBuilder : public TestFixture
{
	CPPUNIT_TEST_SUITE(TestSimpleValueBuilder);
	CPPUNIT_TEST(testZero);
	CPPUNIT_TEST(testInteger);
	CPPUNIT_TEST(testNegateInteger);
	CPPUNIT_TEST(testDecimal);
	CPPUNIT_TEST(testNegateDecimal);
	CPPUNIT_TEST(testExponentional);
	CPPUNIT_TEST(testNegateExponentional);
	CPPUNIT_TEST_SUITE_END();

	SimpleValueBuilder* builder;

public:
	void setUp();
	void tearDown();

protected:
	void testZero();
	void testInteger();
	void testNegateInteger();
	void testDecimal();
	void testNegateDecimal();
	void testExponentional();
	void testNegateExponentional();
};

void TestSimpleValueBuilder::setUp()
{
	builder = new SimpleValueBuilder();
}

void TestSimpleValueBuilder::tearDown()
{
	delete builder;
}

void TestSimpleValueBuilder::testZero()
{
	long double expected = 0;
	long double result = *(builder->with('0').build());

	CPPUNIT_ASSERT(result == expected);
}

void TestSimpleValueBuilder::testInteger()
{
	long double expected = 2380;
	long double result = *(builder->with('2').with('3').with('8').with('0').build());

	CPPUNIT_ASSERT(result == expected);
}

void TestSimpleValueBuilder::testNegateInteger()
{
	long double expected = -2380;
	long double result = *(builder->with('-').with('2').with('3').with('8').with('0').build());

	CPPUNIT_ASSERT(result == expected);
}

void TestSimpleValueBuilder::testDecimal()
{
	long double expected = 2380.002301;
	long double result = *(builder->with('2').with('3').with('8').with('0').with('.').with('0').with('0').with('2').with('3').with('0').with('1').build());

	CPPUNIT_ASSERT(result = expected);
}

void TestSimpleValueBuilder::testNegateDecimal()
{
	long double expected = -2380.45;
	long double result = *(builder->with('-').with('2').with('3').with('8').with('0').with('.').with('4').with('5').build());

	CPPUNIT_ASSERT(result = expected);
}

void TestSimpleValueBuilder::testExponentional()
{
	long double expected = 2.23e12;
	long double result = *(builder->with('2').with('.').with('2').with('3').with('e').with('1').with('2').build());

	CPPUNIT_ASSERT(result = expected);
}

void TestSimpleValueBuilder::testNegateExponentional()
{
	long double expected = -2.23e-12;
	long double result = *(builder->with('-').with('2').with('.').with('2').with('3').with('e').with('-').with('1').with('2').build());

	CPPUNIT_ASSERT(result = expected);
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestSimpleValueBuilder);

int main(int argc, char **argv)
{
	CPPUNIT_NS::TestResult testresult;
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener(&collectedresults);

	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener(&progress);

	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	testrunner.run(testresult);

	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write();

	ofstream xmlFileOut("cppTestSimpleValueBuilderResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}
