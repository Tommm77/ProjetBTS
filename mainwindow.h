#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "tableview.h"

/*#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSqlDriver>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>*/

class ui_themewidgetform;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void BuildWindow();
    TableView *tablewindow;


private slots:
    void on_pushButton_clicked();
    void Charts();


};
#endif // MAINWINDOW_H
