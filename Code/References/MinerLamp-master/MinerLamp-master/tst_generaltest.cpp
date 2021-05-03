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
    QFETCH(QTestEventList, input_Wallet);
    QFETCH(QTestEventList, input_Worker);
    QFETCH(QString, result_Wallet);
    QFETCH(QString, result_Worker);

    QLineEdit* lineEditWallet = w->ui->lineEditWallet;
    QLineEdit* lineEditWorker = w->ui->lineEditWorker;

    input_Wallet.simulate(lineEditWallet);
    input_Worker.simulate(lineEditWorker);

    QCOMPARE(lineEditWallet->text(), result_Wallet);
    QCOMPARE(lineEditWorker->text(), result_Worker);
}

void GeneralTest::test_ui_MiningArgsLineEdit_data()
{
    QString input_filename = "test_MiningArgsLineEdit_input.txt";
    QString result_filename = "test_MiningArgsLineEdit_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<QTestEventList>("input_Wallet");
    QTest::addColumn<QTestEventList>("input_Worker");
    QTest::addColumn<QString>("result_Wallet");
    QTest::addColumn<QString>("result_Worker");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList inputs = input[i].split(",");
        QStringList results = result[i].split(",");
        if (inputs.size() != 2 || results.size() != 2)
        {
            ShowDataError(input_filename, result_filename);
            break;
        }
        QTestEventList events_Wallet;
        events_Wallet.addKeyClick(Qt::Key_A, Qt::ControlModifier);
        events_Wallet.addKeyClick(Qt::Key_Backspace);
        events_Wallet.addKeyClicks(inputs[0]);
        QTestEventList events_Worker;
        events_Worker.addKeyClick(Qt::Key_A, Qt::ControlModifier);
        events_Worker.addKeyClick(Qt::Key_Backspace);
        events_Worker.addKeyClicks(inputs[1]);

        QTest::newRow(rowName.c_str())
                << events_Wallet << events_Worker
                << results[0] << results[1];
    }
}

void GeneralTest::test_ui_MiningArgsComboBox()
{
    QFETCH(QTestEventList, input_Wallet);
    QFETCH(QTestEventList, input_Worker);
    QFETCH(QString, result_Wallet);
    QFETCH(QString, result_Worker);

    QLineEdit* lineEditWallet = w->ui->lineEditWallet;
    QLineEdit* lineEditWorker = w->ui->lineEditWorker;

    input_Wallet.simulate(lineEditWallet);
    input_Worker.simulate(lineEditWorker);

    QCOMPARE(lineEditWallet->text(), result_Wallet);
    QCOMPARE(lineEditWorker->text(), result_Worker);
}

void GeneralTest::test_ui_MiningArgsComboBox_data()
{
    QString input_filename = "test_MiningArgsLineEdit_input.txt";
    QString result_filename = "test_MiningArgsLineEdit_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<QTestEventList>("input_Wallet");
    QTest::addColumn<QTestEventList>("input_Worker");
    QTest::addColumn<QString>("result_Wallet");
    QTest::addColumn<QString>("result_Worker");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList inputs = input[i].split(",");
        QStringList results = result[i].split(",");
        if (inputs.size() != 2 || results.size() != 2)
        {
            ShowDataError(input_filename, result_filename);
            break;
        }
        QTestEventList events_Wallet;
        events_Wallet.addKeyClick(Qt::Key_A, Qt::ControlModifier);
        events_Wallet.addKeyClick(Qt::Key_Backspace);
        events_Wallet.addKeyClicks(inputs[0]);
        QTestEventList events_Worker;
        events_Worker.addKeyClick(Qt::Key_A, Qt::ControlModifier);
        events_Worker.addKeyClick(Qt::Key_Backspace);
        events_Worker.addKeyClicks(inputs[1]);

        QTest::newRow(rowName.c_str())
                << events_Wallet << events_Worker
                << results[0] << results[1];
    }
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
    QString input_filename = "test_ParseJsonForPool_input.txt";
    QString result_filename = "test_ParseJsonForPool_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("currency");
    QTest::addColumn<float>("income");
    QTest::addColumn<float>("usd");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList results = result[i].split(",");
        if (results.size() != 3)
        {
            ShowDataError(input_filename, result_filename);
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
    QString input_filename = "test_ParseJsonForMining_input.txt";
    QString result_filename = "test_ParseJsonForMining_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<QString>("input");
    QTest::addColumn<unsigned int>("latency");
    QTest::addColumn<float>("gpu0_hashrate");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();
        QStringList results = result[i].split(",");
        if (results.size() != 2)
        {
            ShowDataError(input_filename, result_filename);
            break;
        }
        QTest::newRow(rowName.c_str())
                << input[i] << results[0].toUInt() << results[1].toFloat();
    }
}

void GeneralTest::ShowDataError(const QString& filename1, const QString& filename2)
{
    QString path1 = qApp->applicationDirPath() + "/test/" + filename1;
    QString path2 = qApp->applicationDirPath() + "/test/" + filename2;
    QMessageBox::warning(NULL, "warning",
                         QString("Corrupted test data in\n %1 \nand/or\n %2").arg(path1).arg(path2));
}


void GeneralTest::GetTestData(QList<QString> &input, QList<QString> &result,
                              const QString &in_filename, const QString &res_filename)
{
    QString input_path = qApp->applicationDirPath() + "/test/" + in_filename;
    input = helper.GetStringData(input_path);
    QString result_path = qApp->applicationDirPath() + "/test/" + res_filename;
    result = helper.GetStringData(result_path);
    if (input.size() != result.size())
    {
        ShowDataError(in_filename, res_filename);
    }
}

QTEST_MAIN(GeneralTest);

#include "tst_generaltest.moc"
