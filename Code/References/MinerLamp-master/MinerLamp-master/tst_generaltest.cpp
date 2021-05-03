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
void GeneralTest::test_Database_getAdvice(){
    QFETCH(QString, type);
    QFETCH(int, gpu_clock);
    QFETCH(int, mem_clock);
    //QFETCH(unsigned int, power);
    //QFETCH(unsigned int, prediction);
    Database db;
    db.start();
    QStringList info=db.getAdvice(type.toStdString().c_str());
    int str=atoi(info.front().toStdString().c_str());
    int out1=str;
    info.pop_front();
    str=atoi(info.front().toStdString().c_str());
    int out2=str;
    //str=atoi(info.front().toStdString().c_str());
    QCOMPARE(out1, gpu_clock);
    QCOMPARE(out2, mem_clock);
    QBENCHMARK {
        QStringList info=db.getAdvice(type.toStdString().c_str());
    }
}
void GeneralTest::test_Database_getAdvice_data(){
    QTest::addColumn<QString>("type");
    QTest::addColumn<int>("gpu_clock");
    QTest::addColumn<int>("mem_clock");
    QTest::newRow("3090") << "3090" << -300<< 1000;
    QTest::newRow("3080") << "3080" << -150<< 900;
    QTest::newRow("3070") << "3070" << -500<< 1100;
    QTest::newRow("3060Ti") << "3060Ti" << -500<< 1200;
    QTest::newRow("2080Ti") << "2080Ti" << -200<< 1100;
    QTest::newRow("2080super") << "2080super" << -50<< 1000;
    QTest::newRow("2080") << "2080" << -50<< 800;
    QTest::newRow("2070super") << "2070super" << -50<< 800;
    QTest::newRow("2070") << "2070" << -50<< 800;
    QTest::newRow("2060super") << "2060super" << -50<< 850;
    QTest::newRow("2060") << "2060" << -50<< 700;
}
void GeneralTest::test_Database_InsertDataNew(){
    QFETCH(int, sizegap);
    Database db;
    int size1=db.count();
    db.InsertDataNew();
    int size2=db.count();
    int sizegap1=size2-size1;
    QCOMPARE(sizegap1,sizegap);
    QBENCHMARK {
        db.InsertDataNew();
    }
}
void GeneralTest::test_Database_InsertDataNew_data(){
    QTest::addColumn<int>("sizegap");
    QTest::addColumn<int>("sizegap1");
    QTest::newRow("1")  << 1<< 1;
    QTest::newRow("2")  << 1<< 1;
    QTest::newRow("3")  << 1<< 1;
    QTest::newRow("4")  << 1<< 1;
    QTest::newRow("5")  << 1<< 1;

}
/*void GeneralTest::test_Database_Get_HistoryNew(){
    QFETCH(int, num);
    QFETCH(QString, date1);
    QFETCH(QString, date2);
    Database db;
    db.Get_HistoryNew(date1.toStdString().c_str(),date2.toStdString().c_str(),num);
}
void GeneralTest::test_Database_Get_HistoryNew_data(){

}

void GeneralTest::ShowDataError(const QString& filename1, const QString& filename2)
{
    QString path1 = qApp->applicationDirPath() + "/test/" + filename1;
    QString path2 = qApp->applicationDirPath() + "/test/" + filename2;
    QMessageBox::warning(NULL, "warning",
                         QString("Corrupted test data in\n %1 \nand/or\n %2").arg(path1).arg(path2));
}*/


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
