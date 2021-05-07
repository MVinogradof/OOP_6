#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::interface)
{
    ui->setupUi(this);
}

interface::~interface()
{
    delete ui;
}

void interface::on_File_clicked()
{
    QString tmp = QFileDialog::getOpenFileName(this, "Select file", "../OOP_6/data", "*.txt");
    ui->Path->setText(tmp);
}

void interface::on_Show_clicked()
{
    QFile f(ui->Path->text());
    f.open(QIODevice::ReadOnly);
    QTextStream buf(&f);
    qDebug() << "Read to buf";
    int size;
    buf >> size;
    qDebug() << "Read size" << size;
    g = new graph;
    g->new_matrix(size);
    qDebug() << "matrix";
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            int a;
            buf >> a;
            g->set_a(a, i, j);
            qDebug() << i << j;
        }
    }
    c = new canvas(g);
    c->show();
}
