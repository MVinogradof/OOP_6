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
    QPainter painter(this);
    QFont font;

    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.7*(cw>ch?ch:cw);
    qreal cs = 1.5 * cr/g->get_n();
    qreal cf = 0.7 * cs;
    qreal a = 2.0*acos(-1.0)/g->get_n();
    QPointF *t = new QPointF[g->get_n()];

    painter.setPen(QPen(Qt::black));
    font.setPointSize(cf);
    painter.setFont(font);

    for (int i=0; i<g->get_n(); i++)
    {
        t[i] = QPointF(cw+cr*sin(i*a),ch-cr*cos(i*a));
        painter.drawEllipse(t[i],cs,cs);
        painter.drawText(t[i].rx()-cs/4-cs*((i>9?0.25:0)),t[i].ry()+cs/4,QString().setNum(i+1));
    }

    for (int i = 0; i < g->get_n(); i++)
        for (int j = 0; j < g->get_n(); j++)
        {
            if ((g->get_a(i, j))&&(i!=j))
            {
                QLine tmp(t[i].rx(),t[i].ry(),t[j].rx(),t[j].ry());
                double dx=tmp.dx(), dy=tmp.dy(),tmpd,dyp,dxp;
                tmpd=cs/(sqrt(dx*dx+dy*dy));
                dx*=tmpd;
                dy*=tmpd;
                painter.drawLine(t[i]+QPointF(dx,dy),t[j]-QPointF(dx,dy));

                QPointF *arrow = new QPointF[3];

                if ((abs(dy)<1)||(abs(dx)<1))
                {
                    dyp=dx;
                    dxp=dy;
                }
                else
                {
                    dyp=dy;
                    dxp=-(dy*dyp)/dx;
                }

                tmpd=cs/(sqrt(dxp*dxp+dyp*dyp));
                dxp*=tmpd;
                dyp*=tmpd;

                arrow[0]=t[j]-QPointF(dx,dy);
                arrow[1]=t[j]-QPointF(dx,dy)-0.2*QPointF(dx,dy)+0.1*QPointF(dxp,dyp);
                arrow[2]=t[j]-QPointF(dx,dy)-0.2*QPointF(dx,dy)-0.1*QPointF(dxp,dyp);

                painter.setBrush(QBrush(Qt::black));

                painter.drawPolygon(arrow,3);

                painter.setBrush(QBrush(Qt::white));

                delete [] arrow;
            }
        }

    delete [] t;
}
