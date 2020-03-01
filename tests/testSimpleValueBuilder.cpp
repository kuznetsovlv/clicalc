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
	CPPUNIT_TEST_SUITE_END();

	SimpleValueBuilder* builder;

public:
	void setUp();
	void tearDown();

protected:
	void testZero();
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

	cout << result << endl;
	CPPUNIT_ASSERT(result == expected);
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
