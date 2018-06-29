#include "BCSubBoxView.h"
#include <QMouseEvent>
#include <QDebug>
#include "BCRapidWindowOpenningView.h"
#include "../Common/BCCommon.h"

QList<QVariant> g_selected;


BCSubBoxView::BCSubBoxView(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);

    SetActiveBackGround( false );

}

void BCSubBoxView::SetActiveBackGround(bool b)
{
    if (b) {
        setStyleSheet(QString("QLabel{background-color:rgb(%1, %2, %3, %4);color: black;border-radius: 0px; border: 1px groove white;}")
                      .arg(BCCommon::g_nVirtualRectFillColorR)
                      .arg(BCCommon::g_nVirtualRectFillColorG)
                      .arg(BCCommon::g_nVirtualRectFillColorB)
                      .arg(255));
    } else {
        setStyleSheet(QString("QLabel{background-color:rgb(%1, %2, %3, %4);color: black;border-radius: 0px; border: 1px groove white;}")
                      .arg(BCCommon::g_nSingleDisplayFillColorR)
                      .arg(BCCommon::g_nSingleDisplayFillColorG)
                      .arg(BCCommon::g_nSingleDisplayFillColorB)
                      .arg(BCCommon::g_nSingleDisplayFillColorA));
    }
}

void BCSubBoxView::mouseMoveEvent(QMouseEvent *event)
{
    if(g_mousePressed == true)
    {
    QPoint current_pos = mapTo(static_cast<QWidget *>(this->parent()),event->pos());
       for(int i = 0; i < this->parent()->children().count();i++)
       {

           if(this->parent()->children().at(i)->inherits("QLabel"))
           {
               float bigX = current_pos.x();
               float samllX = beginPoint.x();
               float bigY = current_pos.y();
               float samllY = beginPoint.y();
               if(samllY > bigY)
               {
                 bigY = beginPoint.y();
                 samllY = current_pos.y();
               }
               if(samllX > bigX)
               {
                   bigX = beginPoint.x();
                   samllX = current_pos.x();
               }
                BCSubBoxView *self = static_cast<BCSubBoxView *> (this->parent()->children().at(i));
              if(self->frameGeometry().x() <= bigX && self->frameGeometry().x() + self->frameGeometry().width() > samllX)
              {
                  if(self->frameGeometry().y() <= bigY && self->frameGeometry().y() + self->frameGeometry().height() >= samllY)
                  {
                      self->SetActiveBackGround( true );
                      //在这获得滑动后组合起来的矩形大小
                      QVariant var;
                      var.setValue(self);
                      if(g_selected.contains(var) == false)
                      {
                         g_selected.append(var);
                      }
                  }else{
                      self->SetActiveBackGround( false );
                      QVariant var;
                      var.setValue(self);
                      g_selected.removeOne(var) == true;


                  }
              }else{

                  self->SetActiveBackGround( false );
                  QVariant var;
                  var.setValue(self);
                 g_selected.removeOne(var);


              }
            }
   }
}

}


void BCSubBoxView::mousePressEvent(QMouseEvent *event)
{

    g_mousePressed = true;

    beginPoint = mapTo(static_cast<QWidget *>(this->parent()),event->pos());

    for(int i = 0; i < this->parent()->children().count(); i++)
    {
        if(this->parent()->children().at(i)->inherits("QLabel"))
        {
            BCSubBoxView *self = static_cast <BCSubBoxView *> (this->parent()->children().at(i));
              self->SetActiveBackGround( false );
        }

    }
    g_selected.clear();
    QVariant var;
    var.setValue(this);
    g_selected.append(var);
    SetActiveBackGround( true );
}

void BCSubBoxView::mouseReleaseEvent(QMouseEvent */*event*/)
{

     BCRapidWindowOpenningView *graph = static_cast<BCRapidWindowOpenningView *> (this->parent()->parent()->parent());
     QPoint firstIndex = g_selected.at(0).value<BCSubBoxView *>()->_index;
     int clomns = 0;   //鼠标滑动圈起来的列数
     int F_clomn = 0; //为了找出数组中的第一个label在第几列
     for(int i = 0; i < g_selected.count();i++)
     {
        for(int j = 0; j < g_selected.count() - i - 1;j++)
        {
            if(g_selected.at(j).value<BCSubBoxView *>()->_index.x() > g_selected.at(j+1).value<BCSubBoxView *>()->_index.x())
            {
                g_selected.move(j,j+1);

            }
        }

     }
     //根据数组个数算出当前有几行几列  、 以及左上角的X、Y值
     for(int i = 0; i < g_selected.count();i++)
     {
         if(g_selected.at(i).value<BCSubBoxView *>()->_index.x() == firstIndex.x())
         {
            clomns ++;
            if(g_selected.at(i).value<BCSubBoxView *>()->_index.y() > firstIndex.y())
            {
                F_clomn ++;
            }
         }
     }
    QPoint  slot_first = g_selected.at(0).value<BCSubBoxView *>()->_index;
    //graph->moveSignalWindow(QPoint(slot_first.x(),firstIndex.y() - (clomns - F_clomn - 1)),clomns,g_selected.count()/clomns);
     g_mousePressed = false;
}
