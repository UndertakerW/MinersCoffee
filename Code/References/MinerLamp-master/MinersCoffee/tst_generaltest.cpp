#include "tst_generaltest.h"

GeneralTest::GeneralTest()
{

}

GeneralTest::~GeneralTest()
{

}

void GeneralTest::initTestCase()
{
    w = new MainWindow(true);
}

void GeneralTest::cleanupTestCase()
{
    w->StopMiningCore();
    delete w;
}

/* System Test */
void GeneralTest::test_FullSystem()
{
    w->SetUIRefresh(true);
    w->ui->comboBoxCoin->itemText(w->ui->comboBoxCoin->findText("ETH"));
    w->ui->comboBoxCore->itemText(w->ui->comboBoxCore->findText("NBMiner"));
    w->ui->comboBoxPool->itemText(w->ui->comboBoxPool->findText("sparkpool"));
    QTestEventList events_Wallet;
    events_Wallet.addKeyClick(Qt::Key_A, Qt::ControlModifier);
    events_Wallet.addKeyClick(Qt::Key_Backspace);
    events_Wallet.addKeyClicks("sp_utw2");
    events_Wallet.simulate(w->ui->lineEditWallet);
    QTestEventList events_Worker;
    events_Worker.addKeyClick(Qt::Key_A, Qt::ControlModifier);
    events_Worker.addKeyClick(Qt::Key_Backspace);
    events_Worker.addKeyClicks("MC_test");
    events_Worker.simulate(w->ui->lineEditWorker);

    if(!w->_isMinerRunning)
    {
        w->StartMiningCore();
    }
    else
    {
        w->StopMiningCore();
        QThread::sleep(5);
        w->StartMiningCore();
    }

    QString core_args = w->_current_core->cmds[w->_current_coin].arg(
                w->_current_pool->cmds[w->_current_coin]).arg(w->ui->lineEditWallet->text()).arg(w->ui->lineEditWorker->text());
    QString expected_args = "-a ethash -o ethproxy+tcp://cn.sparkpool.com:13333 -u sp_utw2.MC_test";

    QCOMPARE(core_args, expected_args);

    // Wait for initialization of mining
    // This could take longer on slow GPU
    QSignalSpy spy(w->_process, SIGNAL(emitMiningInfo(MiningInfo)));

    QElapsedTimer timer;

    timer.start();
    while(timer.elapsed() < 90000)
    {
        spy.wait(10); // event loop runs here
    }


    bool success = false;
    if (w->_miningInfo->gpuMiningInfos.size() > 0)
    {
        if (w->_miningInfo->gpuMiningInfos[0].hashrate > 1000)
            success = true;
    }

    w->StopMiningCore();

    QCOMPARE(success, true);

    test_TempPieChart();
    //test_HashrateLineChart();

}

/* Component/Subsystem Test */

void GeneralTest::test_MiningArgs()
{
    bool success1 = true;

    if (w->ui->comboBoxCoin->findText("ETH") != -1)
        w->ui->comboBoxCoin->setCurrentIndex(w->ui->comboBoxCoin->findText("ETH"));
    else success1 = false;
    if (w->ui->comboBoxCore->findText("NBMiner") != -1)
        w->ui->comboBoxCore->setCurrentIndex(w->ui->comboBoxCore->findText("NBMiner"));
    else success1 = false;
    if (w->ui->comboBoxPool->findText("sparkpool") != -1)
        w->ui->comboBoxPool->setCurrentIndex(w->ui->comboBoxPool->findText("sparkpool"));
    else success1 = false;

    QCOMPARE(success1, true);

    QTestEventList events_Wallet;
    events_Wallet.addKeyClick(Qt::Key_A, Qt::ControlModifier);
    events_Wallet.addKeyClick(Qt::Key_Backspace);
    events_Wallet.addKeyClicks("sp_utw2");
    events_Wallet.simulate(w->ui->lineEditWallet);
    QTestEventList events_Worker;
    events_Worker.addKeyClick(Qt::Key_A, Qt::ControlModifier);
    events_Worker.addKeyClick(Qt::Key_Backspace);
    events_Worker.addKeyClicks("MC_test");
    events_Worker.simulate(w->ui->lineEditWorker);

    w->SetMiningArgs();

    QString core_args = w->_current_core->cmds[w->_current_coin].arg(
                w->_current_pool->cmds[w->_current_coin]).arg(w->ui->lineEditWallet->text()).arg(w->ui->lineEditWorker->text());

    QString expected_args = "-a ethash -o ethproxy+tcp://cn.sparkpool.com:13333 -u sp_utw2.MC_test";

    QCOMPARE(core_args, expected_args);
}

void GeneralTest::test_MiningCore()
{
    bool success1 = true;

    if (w->ui->comboBoxCoin->findText("ETH") != -1)
        w->ui->comboBoxCoin->setCurrentIndex(w->ui->comboBoxCoin->findText("ETH"));
    else success1 = false;
    if (w->ui->comboBoxCore->findText("NBMiner") != -1)
        w->ui->comboBoxCore->setCurrentIndex(w->ui->comboBoxCore->findText("NBMiner"));
    else success1 = false;
    if (w->ui->comboBoxPool->findText("sparkpool") != -1)
        w->ui->comboBoxPool->setCurrentIndex(w->ui->comboBoxPool->findText("sparkpool"));
    else success1 = false;

    QCOMPARE(success1, true);

    w->ui->lineEditWallet->setText("sp_utw2");
    w->ui->lineEditWorker->setText("MC_test");


    if(!w->_isMinerRunning)
    {
        w->StartMiningCore();
    }
    else
    {
        w->StopMiningCore();
        QThread::sleep(5);
        w->StartMiningCore();
    }
    // Wait for initialization of mining
    // This could take longer on slow GPU
    QSignalSpy spy(w->_process, SIGNAL(emitMiningInfo(MiningInfo)));

    QElapsedTimer timer;

    timer.start();
    while(timer.elapsed() < 90000)
    {
        spy.wait(10); // event loop runs here
    }

    bool success2 = false;
    if (w->_miningInfo->gpuMiningInfos.size() > 0)
    {
        if (w->_miningInfo->gpuMiningInfos[0].hashrate > 1000)
            success2 = true;
    }

    w->StopMiningCore();

    QCOMPARE(success2, true);
}

void GeneralTest::test_TempPieChart()
{
    w->SetUIRefresh(true);

    QList<QPieSlice*>* pieSlices = w->_tempPieSlices;

    QSignalSpy spy(w->_nvMonitorThrd, SIGNAL(
                       gpuInfoSignal(unsigned int, unsigned int, unsigned int,
                                     unsigned int, unsigned int, unsigned int,
                                     unsigned int, unsigned int, unsigned int,
                                     unsigned int, unsigned int, unsigned int)));

    QElapsedTimer timer;

    // Wait for refresh
    // A 100 ms delay guarantees that the refresh is finished
    timer.start();
    while(timer.elapsed() < abs(QDateTime::currentDateTime().msecsTo(w->_nvMonitorThrd->last_refresh))+100)
    {
        spy.wait(10); // event loop runs here
    }

    float temp_api = w->_nvMonitorThrd->nvml->getHigherTemp();

    float temp_ui = pieSlices->at(0)->value();

    QCOMPARE(temp_ui, temp_api);
}

void GeneralTest::test_HashrateLineChart()
{
    bool success1 = true;

    if (w->ui->comboBoxCoin->findText("ETH") != -1)
        w->ui->comboBoxCoin->setCurrentIndex(w->ui->comboBoxCoin->findText("ETH"));
    else success1 = false;
    if (w->ui->comboBoxCore->findText("NBMiner") != -1)
        w->ui->comboBoxCore->setCurrentIndex(w->ui->comboBoxCore->findText("NBMiner"));
    else success1 = false;
    if (w->ui->comboBoxPool->findText("sparkpool") != -1)
        w->ui->comboBoxPool->setCurrentIndex(w->ui->comboBoxPool->findText("sparkpool"));
    else success1 = false;

    QCOMPARE(success1, true);

    w->ui->lineEditWallet->setText("sp_utw2");
    w->ui->lineEditWorker->setText("MC_test");


    if(!w->_isMinerRunning)
    {
        w->StartMiningCore();
    }
    else
    {
        w->StopMiningCore();
        QThread::sleep(5);
        w->StartMiningCore();
    }

    w->SetUIRefresh(true);

    QLineSeries* lineSeries = w->_series;

    QSignalSpy spy(w->_process, SIGNAL(emitMiningInfo(MiningInfo)));

    QElapsedTimer timer;

    // Wait for initialization of miner

    timer.start();
    while(timer.elapsed() < 90000)
    {
        spy.wait(10); // event loop runs here
    }

    // Wait for refresh
    // A 100 ms delay guarantees that the refresh is finished
    timer.start();
    while(timer.elapsed() < abs(QDateTime::currentDateTime().msecsTo(w->_nvMonitorThrd->last_refresh))+100)
    {
        spy.wait(10); // event loop runs here
    }

    float hashrate_api = 0;

    for (int i = 0; i < w->_miningInfo->gpuMiningInfos.size(); i++)
    {
        hashrate_api += w->_miningInfo->gpuMiningInfos[i].hashrate;
    }

    hashrate_api /= (1024 * 1024);

    float hashrate_ui = lineSeries->at(lineSeries->count()-1).y();

    w->StopMiningCore();

    QCOMPARE(hashrate_ui, hashrate_api);
}

void GeneralTest::test_ParsePoolInfo()
{
    bool success1 = false;
    UrlAPI urlAPI;
    std::string buffer;
    LPCSTR url = "https://www.sparkpool.com/v1/pool/stats";
    urlAPI.GetURLInternal(url, buffer);
    if (buffer.size() > 0)
        success1 = true;
    QCOMPARE(success1, true);

    PoolJsonParser poolJsonParser;
    QList<PoolInfo> poolInfos = poolJsonParser.ParseJsonForPool(buffer);

    bool success2 = false;

    if (poolInfos.size() > 0)
    {
        if (poolInfos[0].usd > 0)
        {
            success2 = true;
        }
    }
    QCOMPARE(success2, true);
}

/* Unit Test */

void GeneralTest::test_ui_HashrateLineChart()
{
    w->SetUIRefresh(false);

    QFETCH(float, input);
    QFETCH(float, result);

    QLineSeries* lineSeries = w->_series;

    lineSeries->append(QDateTime::currentDateTime().toMSecsSinceEpoch(), input);

    float hashrate_ui = lineSeries->at(lineSeries->count()-1).y();

    QCOMPARE(hashrate_ui, result);
}

void GeneralTest::test_ui_HashrateLineChart_data()
{
    QString input_filename = "test_ui_HashrateLineChart_input.txt";
    QString result_filename = "test_ui_HashrateLineChart_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<float>("input");
    QTest::addColumn<float>("result");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();

        QTest::newRow(rowName.c_str())
                << input[i].toFloat() << result[i].toFloat();
    }
}

void GeneralTest::test_ui_TempPieChart()
{
    w->SetUIRefresh(false);

    QFETCH(float, input);
    QFETCH(float, result);

    QList<QPieSlice*>* pieSlices = w->_tempPieSlices;

    pieSlices->at(0)->setValue(input);

    QCOMPARE(pieSlices->at(0)->value(), result);
}

void GeneralTest::test_ui_TempPieChart_data()
{
    QString input_filename = "test_ui_TempPieChart_input.txt";
    QString result_filename = "test_ui_TempPieChart_result.txt";
    QList<QString> input, result;
    GetTestData(input, result, input_filename, result_filename);

    QTest::addColumn<float>("input");
    QTest::addColumn<float>("result");

    for (int i = 0; i < input.size(); i++)
    {
        std::string rowName = QString("Case %1").arg(i).toStdString();

        QTest::newRow(rowName.c_str())
                << input[i].toFloat() << result[i].toFloat();
    }
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
    QString input_filename = "test_ui_MiningArgsLineEdit_input.txt";
    QString result_filename = "test_ui_MiningArgsLineEdit_result.txt";
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
    // Currently, MinersCoffee supports only ETH as coin and NBMiner as core.
    // Therefore, comboBoxCoin and comboBoxCore needs no testing at this stage.

    QFETCH(QTestEventList, input_Pool);
    QFETCH(QString, result_Pool);

    QComboBox* comboBoxPool = w->ui->comboBoxPool;

    input_Pool.simulate(comboBoxPool);

    QCOMPARE(comboBoxPool->currentText(), result_Pool);
}

void GeneralTest::test_ui_MiningArgsComboBox_data()
{

    // QString pools_filename = "pools.txt";
    // QString pools_path = qApp->applicationDirPath() + "/data/" + pools_filename;
    // QList<QString> pools = helper.GetStringData(pools_path)

    QList<QString> pool_names;

    QTest::addColumn<QTestEventList>("input_Pool");
    QTest::addColumn<QString>("result_Pool");

    // Test ETH Pools
    w->ui->comboBoxCoin->setCurrentIndex(w->ui->comboBoxCoin->findText("ETH"));
    if (w->ui->comboBoxPool->count() < 7) return;

    for (int i = 0; i < w->ui->comboBoxPool->count(); i++)
    {
        pool_names.append(w->ui->comboBoxPool->itemText(i));
    }

    // second pool
    QTestEventList events_Pool1;
    events_Pool1.addMouseClick(Qt::LeftButton);
    for (int i = 0; i < w->ui->comboBoxPool->count(); i++)
    {
        events_Pool1.addKeyClick(Qt::Key_Up);
    }
    events_Pool1.addKeyClick(Qt::Key_Down);
    events_Pool1.addKeyClick(Qt::Key_Enter);
    QTest::newRow("Case 0")
            << events_Pool1 << pool_names[1];

    // third pool
    QTestEventList events_Pool2;
    events_Pool2.addMouseClick(Qt::LeftButton);
    events_Pool2.addKeyClick(Qt::Key_Down);
    events_Pool2.addKeyClick(Qt::Key_Down);
    events_Pool2.addKeyClick(Qt::Key_Up);
    events_Pool2.addKeyClick(Qt::Key_Enter);
    QTest::newRow("Case 1")
            << events_Pool2 << pool_names[2];

    // fifth pool
    QTestEventList events_Pool3;
    events_Pool3.addMouseClick(Qt::LeftButton);
    events_Pool3.addKeyClick(Qt::Key_Up);
    events_Pool3.addKeyClick(Qt::Key_Down);
    events_Pool3.addKeyClick(Qt::Key_Left);
    events_Pool3.addKeyClick(Qt::Key_Right);
    events_Pool3.addKeyClick(Qt::Key_Down);
    events_Pool3.addKeyClick(Qt::Key_Backspace);
    events_Pool3.addKeyClick(Qt::Key_S);
    events_Pool3.addKeyClick(Qt::Key_Down);
    events_Pool3.addKeyClick(Qt::Key_Enter);
    QTest::newRow("Case 2")
            << events_Pool3 << pool_names[4];
}

void GeneralTest::test_GetURLInternal()
{
    bool success = false;
    UrlAPI urlAPI;
    std::string buffer;
    LPCSTR url = "https://www.sparkpool.com/v1/pool/stats";
    urlAPI.GetURLInternal(url, buffer);
    if (buffer.size() > 0)
        success = true;
    QCOMPARE(success, true);
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
