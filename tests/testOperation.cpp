#include "test.h"

#include "../src/stack.h"
#include "../src/operation.h"

using namespace CppUnit;
using namespace std;

class TestOperation : public TestFixture
{
	CPPUNIT_TEST_SUITE(TestOperation);
	CPPUNIT_TEST(testAddition);
	CPPUNIT_TEST(testSubtraction);
	CPPUNIT_TEST_SUITE_END();

void process(Operation*, long double, long double, long double);

public:
	void setUp();
	void tearDown();

protected:
	void testAddition();
	void testSubtraction();
};

void TestOperation::process(Operation* op, long double a, long double b, long double expected)
{
	Stack<long double> stack;
	stack.push(a);
	stack.push(b);
	CPPUNIT_ASSERT(op->complete(stack) == expected);
}

void TestOperation::testAddition()
{
	Stack<long double> stack;
	Operation *add = Operation::getOperation("+");

	long double a = 12.03, b = 14.1;
	process(add, a, b, a + b);

	a = 12.03;
	b = -12.0032;
	process(add, a, b, a + b);
}

void TestOperation::testSubtraction()
{
	Stack<long double> stack;
	Operation *sub = Operation::getOperation("-");

	long double a = 12.03, b = 14.1;
	process(sub, a, b, a - b);

	a = 12.03;
	b = -12.0032;
	process(sub, a, b, a - b);
}


void TestOperation::setUp(){}
void TestOperation::tearDown(){}

CPPUNIT_TEST_SUITE_REGISTRATION(TestOperation);

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

	ofstream xmlFileOut("cppTestOperationResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}
