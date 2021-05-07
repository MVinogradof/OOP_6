#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

#include <graph.h>

namespace Ui {
class canvas;
}

class canvas : public QWidget
{
    Q_OBJECT

public:
    canvas(graph*);
    ~canvas();

protected:
    void paintEvent(QPaintEvent*);

private:
    Ui::canvas *ui;
    graph *g;
};

#endif // CANVAS_H
