#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    std::cout << "Hello World!" << std::endl;
//    SYSTEM_INFO si;
//    GetSystemInfo(&si);
//    DWORD ch = si.dwNumberOfProcessors;
//    std::cout << "processor numbers: " << ch << std::endl;

    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);

    ui->label_total_ram->setText( QString::number( ram.total() ) + " Mb");
    ui->label_used_ram->setText( QString::number( ram.used() ) + " Mb ("+QString::number(ram.memoryLoad())+"%)");
    ui->label_available_ram->setText( QString::number( ram.available() ) + " Mb");
    ui->label_ram_speed->setText( QString::fromStdString( ram.speed() ) + " МГц");
}

MainWindow::~MainWindow()
{
    delete ui;
}

