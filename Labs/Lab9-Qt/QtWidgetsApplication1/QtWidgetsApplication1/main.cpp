#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <QTWidgets/qlabel.h>
#include <QTWidgets/qpushbutton.h>
#include <QTWidgets/qboxlayout.h>
#include <QtWidgets/qlistwidget.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w{};
    QHBoxLayout* ly = new QHBoxLayout{};
    w.setLayout(ly);

    ly->addWidget(new QLabel{ "" });
    ly->addWidget(new QListWidget{ nullptr });
    ly->addWidget(new QPushButton{ "" });
    ly->addWidget(new QPushButton{ "" });
    ly->addWidget(new QPushButton{ "" });
    w.show();
    return a.exec();
}
