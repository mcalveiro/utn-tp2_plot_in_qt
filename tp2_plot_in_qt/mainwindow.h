#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"  // Asegúrate de que la ruta sea correcta

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void salir();
private:
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;
};
#endif // MAINWINDOW_H
