#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class GeneralTest : public QObject
{
    Q_OBJECT

public:
    GeneralTest();
    ~GeneralTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

GeneralTest::GeneralTest()
{

}

GeneralTest::~GeneralTest()
{

}

void GeneralTest::initTestCase()
{

}

void GeneralTest::cleanupTestCase()
{

}

void GeneralTest::test_case1()
{

}

QTEST_MAIN(GeneralTest)

#include "tst_generaltest.moc"
