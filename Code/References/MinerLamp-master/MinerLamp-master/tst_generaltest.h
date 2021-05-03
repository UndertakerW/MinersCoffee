#ifndef TST_GENERALTEST_H
#define TST_GENERALTEST_H

#include "mainwindow.h"

#include <QtTest>
#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <qtest.h>
#include <sstream>

#include "nvidianvml.h"
#include "jsonparser.h"
#include "structures.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helper.h"

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
    void test_ui_MiningArgsLineEdit();
    void test_ui_MiningArgsLineEdit_data();
    void test_ui_MiningArgsComboBox();
    void test_ui_MiningArgsComboBox_data();
    void test_Database_getAdvice();
    void test_Database_getAdvice_data();
    void test_Database_InsertDataNew();
    void test_Database_InsertDataNew_data();
    void test_Database_Get_HistoryNew();
    void test_Database_Get_HistoryNew_data();

private:
    MainWindow* w;
    Helper helper;
};

#endif // TST_GENERALTEST_H
