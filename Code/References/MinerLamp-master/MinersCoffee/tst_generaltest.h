#ifndef TST_GENERALTEST_H
#define TST_GENERALTEST_H

#include "mainwindow.h"

#include <QtTest>
#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QSignalSpy>
#include <qtest.h>
#include <sstream>

#include "nvidianvml.h"
#include "jsonparser.h"
#include "structures.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helper.h"
#include "constants.h"
#include "urlapi.h"

namespace Ui {
class MainWindow;
}

class GeneralTest : public QObject
{
    Q_OBJECT

public:
    GeneralTest();
    ~GeneralTest();

private:
    void GetTestData(QList<QString>& input, QList<QString>& result, const QString& in_filename, const QString& res_filename);
    void ShowDataError(const QString& filename1, const QString& filename2);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_ParseJsonForMining();
    void test_ParseJsonForMining_data();
    void test_ParseJsonForPool();
    void test_ParseJsonForPool_data();
    void test_GetURLInternal();
    void test_ui_MiningArgsLineEdit();
    void test_ui_MiningArgsLineEdit_data();
    void test_ui_MiningArgsComboBox();
    void test_ui_MiningArgsComboBox_data();
    void test_ui_TempPieChart();
    void test_ui_TempPieChart_data();
    void test_ui_HashrateLineChart();
    void test_ui_HashrateLineChart_data();

    void test_TempPieChart();
    void test_HashrateLineChart();
    void test_MiningCore();
    void test_MiningArgs(); 
    void test_ParsePoolInfo();

    void test_FullSystem();


private:
    MainWindow* w;
    Helper helper;
};

#endif // TST_GENERALTEST_H
