
#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    setAttribute(Qt::WA_Hover);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

bool ClickableLabel::event(QEvent * e)
{
    switch(e->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(e));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

void ClickableLabel::hoverEnter(QHoverEvent * event)
{
    emit s_hoverEnter();
    //qDebug() << Q_FUNC_INFO << event->type();
}

void ClickableLabel::hoverLeave(QHoverEvent * event)
{
    emit s_hoverLeave();
    //m_count = 0;
    //qDebug() << Q_FUNC_INFO << event->type();
    //this->setText(QString::number(m_count));
}

void ClickableLabel::hoverMove(QHoverEvent * event)
{
    emit s_hoverMove();
    //m_count++;
    //qDebug() << Q_FUNC_INFO << event->type() << m_count;
    //this->setText(QString::number(m_count));
}

