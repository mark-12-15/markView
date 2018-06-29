#include "label.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QPushButton>

Label::Label(QWidget * parent, Qt::WindowFlags f) : QLabel(parent)
{
    setAcceptDrops(true);
}



void Label::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        event->accept();
    }

}

void Label::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString str;
        dataStream >> str;

        QPushButton *pushButton = new QPushButton(this);
        pushButton->setText(str);
        pushButton->show();


//        QLabel *newIcon = new QLabel(this);
//        newIcon->setPixmap(pixmap);
        pushButton->move(event->pos());
//        newIcon->show();
//        newIcon->setAttribute(Qt::WA_DeleteOnClose);

//        if (event->source() == this) {
//            event->setDropAction(Qt::MoveAction);
//            event->accept();
//        } else {
//            event->acceptProposedAction();
//        }
    }
}


