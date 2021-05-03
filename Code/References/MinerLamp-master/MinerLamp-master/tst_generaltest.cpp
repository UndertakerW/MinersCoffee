#include "tst_generaltest.h"

GeneralTest::GeneralTest()
{

}

GeneralTest::~GeneralTest()
{

}

void GeneralTest::initTestCase()
{
    w = new MainWindow();
}

void GeneralTest::cleanupTestCase()
{
    delete w;
}

void GeneralTest::test_ui_MiningArgsLineEdit()
{
    QFETCH(QTestEventList, event);
    QFETCH(QString, result);

    QLineEdit* lineEditWallet = w->ui->lineEditWallet;
    QLineEdit* lineEditWorker = w->ui->lineEditWorker;

    event.simulate(lineEditWallet);
    QCOMPARE(lineEditWallet->text(), result);
}

void GeneralTest::test_ui_MiningArgsLineEdit_data()
{
    QString input_path = qApp->applicationDirPath() + "/test/test_MiningArgsLineEdit_input.txt";
    QList<QString> input = GetStringData(input_path);
    QString result_path = qApp->applicationDirPath() + "/test/test_MiningArgsLineEdit_result.txt";
    QList<QString> result = GetStringData(result_path);

    QTest::addColumn<QTestEventList>("event");
    QTest::addColumn<QString>("result");

    QTestEventList list1;
    list1.addKeyClicks("hello world");
    QTest::newRow("item 0 ")<<list1<<QString("hello world");

    QTestEventList list2;
    list2.addKeyClicks("abs0");
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("item 1")<<list2<<QString("abs");
}

void GeneralTest::test_ParseJsonForPool()
{
    QFETCH(QString, input);
    QFETCH(QString, currency);
    QFETCH(float, income);
    QFETCH(float, usd);

    PoolJsonParser poolJsonParser;
    QList<PoolInfo> poolInfos = poolJsonParser.ParseJsonForPool(input.toStdString());

    QString out1;
    float out2 = 0;
    float out3 = 0;
    if (poolInfos.size() > 0)
    {
        out1 = poolInfos[0].currency;
        out2 = poolInfos[0].income;
        out3 = poolInfos[0].usd;
    }
    QCOMPARE(out1, currency);
    QCOMPARE(out2, income);
    QCOMPARE(out3, usd);

    QBENCHMARK {
        QList<PoolInfo> poolInfos = poolJsonParser.ParseJsonForPool(input.toStdString());
    }
}

void GeneralTest::test_ParseJsonForPool_data()
{
    QString input_path = qApp->applicationDirPath() + "/test/test_ParseJsonForPool_input.txt";
    QList<QString> input = GetStringData(input_path);
    QString result_path = qApp->applicationDirPath() + "/test/test_ParseJsonForPool_result.txt";
    QList<QString> result = GetStringData(result_path);
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("currency");
    QTest::addColumn<float>("income");
    QTest::addColumn<float>("usd");
    if (input.size() != result.size())
    {
        ShowDataError(input_path, result_path);
    }
    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList results = result[i].split(",");
        if (results.size() != 3)
        {
            ShowDataError(input_path, result_path);
            break;
        }
        QTest::newRow(rowName.c_str())
                << input[i] << results[0]
                << results[1].toFloat() << results[2].toFloat();
    }
}


void GeneralTest::test_ParseJsonForMining()
{
    QFETCH(QString, input);
    QFETCH(unsigned int, latency);
    QFETCH(float, gpu0_hashrate);
    NBMinerJsonParser nbMinerJsonParser;
    MiningInfo miningInfo = nbMinerJsonParser.ParseJsonForMining(input.toStdString());
    unsigned int out1 = miningInfo.latency;
    float out2 = 0;
    if (miningInfo.gpuMiningInfos.size() > 0)
    {
        out2 = miningInfo.gpuMiningInfos[0].hashrate;
    }
    QCOMPARE(out1, latency);
    QCOMPARE(out2, gpu0_hashrate);

    QBENCHMARK {
        MiningInfo miningInfo = nbMinerJsonParser.ParseJsonForMining(input.toStdString());
    }
}

void GeneralTest::test_ParseJsonForMining_data()
{
    QString input_path = qApp->applicationDirPath() + "/test/test_ParseJsonForMining_input.txt";
    QList<QString> input = GetStringData(input_path);
    QString result_path = qApp->applicationDirPath() + "/test/test_ParseJsonForMining_result.txt";
    QList<QString> result = GetStringData(result_path);

    QTest::addColumn<QString>("input");
    QTest::addColumn<unsigned int>("latency");
    QTest::addColumn<float>("gpu0_hashrate");
    if (input.size() != result.size())
    {
        ShowDataError(input_path, result_path);
    }
    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList results = result[i].split(",");
        if (results.size() != 2)
        {
            ShowDataError(input_path, result_path);
            break;
        }
        QTest::newRow(rowName.c_str())
                << input[i] << results[0].toUInt() << results[1].toFloat();
    }
}

void GeneralTest::ShowDataError(const QString& filename1, const QString& filename2)
{
    QMessageBox::warning(NULL, "warning",
                         QString("Corrupted test data in\n %1 \nand/or\n %2").arg(filename1).arg(filename2));
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
