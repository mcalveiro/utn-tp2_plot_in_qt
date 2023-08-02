#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"  // Asegúrate de que la ruta sea correcta

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Establecer un tamaño fijo para la ventana (por ejemplo, 800x600)
    setFixedSize(800, 600);

    // Configurar el objeto QCustomPlot
    customPlot = new QCustomPlot(this);
    setCentralWidget(customPlot);

    // Configurar los ejes y etiquetas
    customPlot->xAxis->setLabel("X Axis");
    customPlot->yAxis->setLabel("Y Axis");

    // Agregar un gráfico de barras de ejemplo
    QVector<double> xData = {1, 2, 3, 4, 5};
    QVector<double> yData = {3, 5, 8, 2, 7};
    customPlot->addGraph();
    customPlot->graph(0)->setData(xData, yData);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    // Autoescalar los ejes y mostrar el gráfico
    customPlot->rescaleAxes();
    customPlot->replot();

    // Crear el botón "Salir"
    QPushButton *pushButtonSalir = new QPushButton("Salir", this);
    pushButtonSalir->setGeometry(700 - 10, 570 - 10, 100, 30);

    // Conectar el botón "Salir" a la función para cerrar la aplicación
    connect(pushButtonSalir, &QPushButton::clicked, this, &MainWindow::salir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::salir()
{
    qApp->quit(); // Cerrar la aplicación
}
