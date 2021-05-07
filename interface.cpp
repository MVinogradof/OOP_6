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
    int size;
    buf >> size;
    if(size <= 0)
    {
        QMessageBox::warning(this,"Error","Incorrect data");
        return;
    }
    g = new graph;
    g->new_matrix(size);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(buf.atEnd())
            {
                QMessageBox::warning(this,"Error","Incorrect data");
                delete g;
                return;
            }
            int a;
            buf >> a;
            if(a != 1 && a != 0)
            {
                QMessageBox::warning(this,"Error","Incorrect data");
                delete g;
                return;
            }
            g->set_a(a, i, j);
        }
    }
    if(!buf.atEnd())
    {
        QMessageBox::warning(this,"Error","Incorrect data");
        delete g;
        return;
    }
    c = new canvas(g);
    c->show();
}
