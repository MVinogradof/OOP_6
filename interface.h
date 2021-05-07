#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

#include <canvas.h>

QT_BEGIN_NAMESPACE
namespace Ui { class interface; }
QT_END_NAMESPACE

class interface : public QWidget
{
    Q_OBJECT

public:
    interface(QWidget *parent = nullptr);
    ~interface();

private slots:
    void on_File_clicked();
    void on_Show_clicked();

private:
    Ui::interface *ui;
    canvas* c;
    graph* g;
};
#endif // INTERFACE_H
