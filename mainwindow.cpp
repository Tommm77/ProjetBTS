#include "mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

        Charts();

    }

MainWindow::~MainWindow()
{
}


void MainWindow::Charts(){
    //![1]
        QLineSeries *chart1 = new QLineSeries();
        QLineSeries *chart2 = new QLineSeries();
        QLineSeries *chart3 = new QLineSeries();
        QLineSeries *chart4 = new QLineSeries();
    //![1]

    //![2]
        chart1->append(0, 6);
        chart1->append(2, 4);
        chart1->append(3, 8);
        chart1->append(7, 4);
        chart1->append(10, 5);
       // *chart1 << QPointF(10, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

        chart2->append(0, 5);
        chart2->append(2, 3);
        chart2->append(3, 7);
        chart2->append(7, 3);
        chart2->append(10, 4);
      //  *chart2 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

        chart3->append(0, 4);
        chart3->append(2, 2);
        chart3->append(3, 6);
        chart3->append(7, 2);
        chart3->append(10, 3);
      //  *chart3 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

        chart4->append(0, 3);
        chart4->append(2, 1);
        chart4->append(3, 5);
        chart4->append(7, 1);
        chart4->append(10, 2);
      //  *chart4 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);*/
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->legend()->hide();
        if (checkBox->isChecked()){
        chart->addSeries(chart1);
        }
        if (checkBox_2->isChecked()){
        chart->addSeries(chart2);
        }
        if (checkBox_3->isChecked()){
        chart->addSeries(chart3);
        }
        if (checkBox_4->isChecked()){
        chart->addSeries(chart4);
        }
        chart->createDefaultAxes();
        chart->setTitle("Graphique");
    //![3]

    //![4]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![4]


    //![5]
        gridLayout->addWidget(chartView);

    //![5]
}


void MainWindow::on_pushButton_clicked(){
    tablewindow = new TableView(this);
    tablewindow->show();
}
