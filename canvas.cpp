#include "canvas.h"
#include "ui_canvas.h"

canvas::canvas(graph* gr)
{
    g = gr;
    ui->setupUi(this);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    int n = g->get_n();
    qreal centX = 0.5*rect().width();
    qreal centY = 0.5*rect().height();
    qreal R_big = 0.7*(centX>centY?centY:centX);
    qreal font_sz = R_big/n;
    qreal angle = 2.0*acos(-1.0)/n;
    QPointF *t = new QPointF[n];

    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    QFont font;
    font.setPointSize(font_sz);
    painter.setFont(font);

    for (int i=0; i<n; i++)
    {
        t[i] = QPointF(centX+R_big*sin(i*angle), centY-R_big*cos(i*angle));
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(t[i], R_big/(5*n), R_big/(5*n));
        QLine R(centX, centY, t[i].rx(), t[i].ry());
        int offsX, offsY;
        offsX = abs(R.dx()*0.15);
        offsY = abs(R.dy()*0.15);
        if(t[i].rx() < centX)
            offsX = -offsX;
        if(t[i].ry() < centY)
            offsY = -offsY;
        painter.drawText(t[i].rx()-font_sz/2+offsX, t[i].ry()+font_sz/2+offsY, QString().setNum(i+1));
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if ((g->get_a(i, j) != 0) && (i != j))
                painter.drawLine(t[i], t[j]);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if ((g->get_a(i, j) != 0) && (i != j))
            {
                QLineF tmp(t[i].rx(),t[i].ry(),t[j].rx(),t[j].ry());
                painter.setBrush(QBrush(Qt::gray));
                painter.drawPie(t[i].rx()-0.2*R_big, t[i].ry()-0.2*R_big, 0.4*R_big, 0.4*R_big, -6*16+tmp.angle()*16, 12*16);
            }


    delete [] t;
}
