#include "tableview.h"
#include "mainwindow.h"

TableView::TableView(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    const QString DRIVER("QSQLITE");

    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

    db.setDatabaseName("C:/Users/user/Dropbox/PC/Desktop/PROJET BTS/QtBDD/db_donnee_kart.db");

    if(db.open()) {
        qDebug() << "Ok - ouverture de la base de donnée";
       TableCourse();
       TableTest();
        TablePilote();
        TableMesure();
}
}
    void TableView::TableTest(){
        QSqlQuery requete; int ligne(0);
        requete.exec("select count (*) from test");
        while(requete.next()){
            ligne = requete.value(0).toInt();
        }
        modele = new QStandardItemModel (ligne,4);
        int row(0);
        requete.exec("select test, test1, test2, test3 from test");
        while (requete.next()){
            for(int j=0;j<4;j++)
            {
                QStandardItem *item= new QStandardItem(requete.value(j).toString());
                modele->setItem(row,j,item);
            }
            row++;
        }
        modele->setHeaderData(0,Qt::Horizontal,"test");
        modele->setHeaderData(1,Qt::Horizontal,"test1");
        modele->setHeaderData(2,Qt::Horizontal,"test2");
        modele->setHeaderData(3,Qt::Horizontal,"test3");

        tableView_2->setModel(modele);
    }




    void TableView::TableCourse(){
        QSqlQuery requete; int ligne(0);
        requete.exec("select count (*) from course");
        while(requete.next()){
            ligne = requete.value(0).toInt();
        }
        modele = new QStandardItemModel (ligne,4);
        int row(0);
        requete.exec("select * from course");
        while (requete.next()){
            for(int j=0;j<4;j++)
            {
                QStandardItem *item= new QStandardItem(requete.value(j).toString());
                modele->setItem(row,j,item);
            }
            row++;
        }
        modele->setHeaderData(0,Qt::Horizontal,"id_course");
        modele->setHeaderData(1,Qt::Horizontal,"vitesse");
        modele->setHeaderData(2,Qt::Horizontal,"distance_parcourue");
        modele->setHeaderData(3,Qt::Horizontal,"pente");

        tableView->setModel(modele);
    }




    void TableView::TablePilote(){
        QSqlQuery requete; int ligne(0);
        requete.exec("select count (*) from pilote");
        while(requete.next()){
            ligne = requete.value(0).toInt();
        }
        modele = new QStandardItemModel (ligne,4);
        int row(0);
        requete.exec("select * from pilote");
        while (requete.next()){
            for(int j=0;j<4;j++)
            {
                QStandardItem *item= new QStandardItem(requete.value(j).toString());
                modele->setItem(row,j,item);
            }
            row++;
        }
        modele->setHeaderData(0,Qt::Horizontal,"id_pilote");
        modele->setHeaderData(1,Qt::Horizontal,"pseudo_pilote");
        modele->setHeaderData(2,Qt::Horizontal,"temps_course");
        modele->setHeaderData(3,Qt::Horizontal,"masse_pilote");

        tableView_3->setModel(modele);
    }




    void TableView::TableMesure(){
        QSqlQuery requete; int ligne(0);
        requete.exec("select count (*) from mesure");
        while(requete.next()){
            ligne = requete.value(0).toInt();
        }
        modele = new QStandardItemModel (ligne,7);
        int row(0);
        requete.exec("select * from mesure");
        while (requete.next()){
            for(int j=0;j<7;j++)
            {
                QStandardItem *item= new QStandardItem(requete.value(j).toString());
                modele->setItem(row,j,item);
            }
            row++;
        }
        modele->setHeaderData(0,Qt::Horizontal,"id_mesure");
        modele->setHeaderData(1,Qt::Horizontal,"tensions_batteries");
        modele->setHeaderData(2,Qt::Horizontal,"decharges_batteries");
        modele->setHeaderData(3,Qt::Horizontal,"courant");
        modele->setHeaderData(4,Qt::Horizontal,"couple_moteur");
        modele->setHeaderData(5,Qt::Horizontal,"vitesse_moteur");
        modele->setHeaderData(6,Qt::Horizontal,"puissances_batteries");
        tableView_4->setModel(modele);

    }
