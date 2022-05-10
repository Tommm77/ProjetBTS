#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include "ui_tableview.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include <QStandardItemModel>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

//#include <QDebug>
//#include <QFileInfo>
//#include <QSqlError>
//#include <QMessageBox>
//#include <QSqlDriver>

class TableView : public QDialog, private Ui::TableView
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
private:
    void BuildWindow();

    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    QStandardItemModel *modele;
    QStandardItemModel *modelee;

private slots:
    void TableCourse();
    void TableTest();
    void TablePilote();
    void TableMesure();


};

#endif // TABLEVIEW_H
