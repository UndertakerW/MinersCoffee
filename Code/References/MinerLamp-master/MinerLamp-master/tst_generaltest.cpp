#include <QtTest>
#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <qtest.h>

#include "nvidianvml.h"
#include "jsonparser.h"
#include "structures.h"

class GeneralTest : public QObject
{
    Q_OBJECT

public:
    GeneralTest();
    ~GeneralTest();

private:
    QList<QString> GetStringData(const QString& path);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_ParseJsonForMining();
    void test_ParseJsonForMining_data();

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

void GeneralTest::test_ParseJsonForMining()
{
    QFETCH(QString, input);
    QFETCH(unsigned int, latency);
    QFETCH(float, GPU0_hashrate);
    NBMinerJsonParser nbMinerJsonParser;
    MiningInfo miningInfo = nbMinerJsonParser.ParseJsonForMining(input.toStdString());
    unsigned int out1 = miningInfo.latency;
    float out2 = 0;
    if (miningInfo.gpuMiningInfos.size() > 0)
    {
        out2 = miningInfo.gpuMiningInfos[0].hashrate;
    }
    QCOMPARE(out1, latency);
    QCOMPARE(out2, GPU0_hashrate);
    QBENCHMARK {
        MiningInfo miningInfo = nbMinerJsonParser.ParseJsonForMining(input.toStdString());
    }
}

void GeneralTest::test_ParseJsonForMining_data()
{
    QString input_path = qApp->applicationDirPath() + "/test/MiningJson.txt";
    QList<QString> input = GetStringData(input_path);
    QString result_path = qApp->applicationDirPath() + "/test/MiningJsonResult.txt";
    QList<QString> result = GetStringData(result_path);
    if (input.size()*2 != result.size())
    {
        QMessageBox::warning(NULL, "warning",
                             QString("Corrupted testing data in %1 and/or %2").arg(input_path).arg(result_path));
        return;
    }
    QTest::addColumn<QString>("input");
    QTest::addColumn<unsigned int>("latency");
    QTest::addColumn<float>("GPU0_hashrate");
    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QTest::newRow(rowName.c_str())
                << input[i] << result[i*2].toUInt() << result[i*2+1].toFloat();
    }

}

QList<QString> GeneralTest::GetStringData(const QString& path)
{

    QFile file(path);

    if (!file.exists())
    {
        QMessageBox::warning(NULL, "warning", QString("File %1 does not exist!").arg(path));
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, "warning", QString("Unable to open file：%1 (%2)").arg(path).arg(file.errorString()));
    }

    QTextStream in(&file);

    QList<QString> data;

    QString line;

    while (1)
    {
        line = in.readLine();
        if (line == "")
            break;

        data.append(line);
    }

    file.close();

    return data;
}

QTEST_MAIN(GeneralTest);

#include "tst_generaltest.moc"
