#include "test.h"
#include "cmath"

#include "../src/stack.h"
#include "../src/operationBuilder.h"
#include "../src/operation.h"

using namespace CppUnit;
using namespace std;

class TestOperationBuilder : public TestFixture
{
	CPPUNIT_TEST_SUITE(TestOperationBuilder);
	CPPUNIT_TEST(testPower);
	CPPUNIT_TEST(testMult);
	CPPUNIT_TEST(testDiv);
	CPPUNIT_TEST(testAddition);
	CPPUNIT_TEST(testSubtraction);
	CPPUNIT_TEST(testAbs);
	CPPUNIT_TEST_SUITE_END();

void process(Operation*, long double, long double, long double);
void process(Operation*, long double, long double);

public:
	void setUp();
	void tearDown();

protected:
	void testPower();
	void testMult();
	void testDiv();
	void testAddition();
	void testSubtraction();
	void testAbs();
};

void TestOperationBuilder::process(Operation* op, long double a, long double b, long double expected)
{
	Stack<long double> stack;
	stack.push(a);
	stack.push(b);
	CPPUNIT_ASSERT(op->complete(stack) == expected);
}

void TestOperationBuilder::process(Operation* op, long double a, long double expected)
{
	Stack<long double> stack;
	stack.push(a);
	CPPUNIT_ASSERT(op->complete(stack) == expected);
}

void TestOperationBuilder::testPower()
{
	Operation *powOp = (new OperationBuilder())->with('^').build();
	CPPUNIT_ASSERT(powOp->getPriority() == primary);

	long double a = 12.04, b = 18.3;
	process(powOp, a, b, pow(a, b));

	a = 3.1023;
	b = -.123;
	process(powOp, a, b, pow(a, b));
}

void TestOperationBuilder::testMult()
{
	Operation *mult = (new OperationBuilder())->with('*').build();
	CPPUNIT_ASSERT(mult->getPriority() == secondary);

	long double a = 5.23, b = 0.45;
	process(mult, a, b, a * b);

	a = 23.4;
	b = -14.8903;
	process(mult, a, b, a * b);
}

void TestOperationBuilder::testDiv()
{
	Operation *div = (new OperationBuilder())->with('/').build();
	CPPUNIT_ASSERT(div->getPriority() == secondary);

	long double a = 14.23, b = 12.42;
	process(div, a, b, a / b);

	a = -1.23;
	b = 0.14;
	process(div, a, b, a / b);
}

void TestOperationBuilder::testAddition()
{
	Operation *add = (new OperationBuilder())->with('+').build();
	CPPUNIT_ASSERT(add->getPriority()  == last);

	long double a = 12.03, b = 14.1;
	process(add, a, b, a + b);

	a = 12.03;
	b = -12.0032;
	process(add, a, b, a + b);
}

void TestOperationBuilder::testSubtraction()
{
	Operation *sub = (new OperationBuilder())->with('-').build();
	CPPUNIT_ASSERT(sub->getPriority() == last);

	long double a = 12.03, b = 14.1;
	process(sub, a, b, a - b);

	a = 12.03;
	b = -12.0032;
	process(sub, a, b, a - b);
}

void TestOperationBuilder::testAbs()
{
	Operation *absOp = (new OperationBuilder)->with('a').with('b').with('s').build();
	CPPUNIT_ASSERT(absOp->getPriority() == primary);

	long double a = 12.34;
	process(absOp, a, a);
	process(absOp, -a, a);
}


void TestOperationBuilder::setUp(){}
void TestOperationBuilder::tearDown(){}

CPPUNIT_TEST_SUITE_REGISTRATION(TestOperationBuilder);

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

	ofstream xmlFileOut("cppTestOperationBuilderResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();

	return collectedresults.wasSuccessful() ? 0 : 1;
}
