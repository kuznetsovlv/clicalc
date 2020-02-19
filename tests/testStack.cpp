#include "test.h"

#include "../src/stack.h"

using namespace CppUnit;
using namespace std;

class TestStack : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestStack);
	CPPUNIT_TEST(testWithLongDouble);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void testWithLongDouble();
};

void TestStack::testWithLongDouble()
{
	Stack<long double> stack;

	stack.push(0);
	stack.push(12.56);
	stack.push(-1.23);
	stack.push(3.6709E-123);

	CPPUNIT_ASSERT(3.6709E-123 == stack.pop());
	CPPUNIT_ASSERT(-1.23 == stack.pop());
	CPPUNIT_ASSERT(12.56 == stack.pop());
	CPPUNIT_ASSERT(0 == stack.pop());
}

void TestStack::setUp(){}
void TestStack::tearDown(){}

CPPUNIT_TEST_SUITE_REGISTRATION(TestStack);

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

	ofstream xmlFileOut("cppTestStackResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}
