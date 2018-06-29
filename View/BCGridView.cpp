#include "BCGridView.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include "BCRapidWindowOpenningView.h"
#include "BCSubBoxView.h"
BCGridView::BCGridView(QWidget *parent, int count) : QWidget(parent)
{

    this->creatSubViews(count);

}

void BCGridView::setRadioButton(QRadioButton *radBut)
{
    if(radBut->text() == "四分割")
    {
        m_radioBut = radBut;
    }
    else if(radBut->text() == "六分割")
    {
        m_radioButSix = radBut;
    }
    else if(radBut->text() == "八分割")
    {
        m_radioButEight = radBut;
    }
    else if(radBut->text() == "九分割")
    {
        m_radioButNine = radBut;
    }
    else if(radBut->text() == "十二分割")
    {
        m_radioButTwelve = radBut;
    }
    else
    {
        m_radioButSixteen = radBut;
    }

    connect(radBut,SIGNAL(clicked(bool)),this,SLOT(clickRadioBut()));
}

void BCGridView::test()
{
    this->deleateSubView();

}
void BCGridView::deleateSubView()
{

    for(int i = 0; i < this->children().count(); i++)
    {
         delete this->children().at(i);

    }
    if(this->children().count() > 0)
    {
        this->deleateSubView();
    }
}

void BCGridView::clickRadioBut()
{
  BCRapidWindowOpenningView *graph = static_cast<BCRapidWindowOpenningView *> (this->parent()->parent());
  QRadioButton *radBut = static_cast <QRadioButton *> (sender());
  int count = 4;
  if(radBut->text() == "四分割")
  {
     count = 4;
  }
  else if(radBut->text() == "六分割")
  {
      count = 6;
  }
  else if(radBut->text() == "八分割")
  {
     count = 8;
  }
  else if(radBut->text() == "九分割")
  {
      count = 9;
  }
  else if(radBut->text() == "十二分割")
  {
     count = 12;
  }
  else
  {
      count = 16;
  }

  //graph->changeGridView(count);


}

void BCGridView::creatSubViews(int count)
{

    deleateSubView();
    int cloumn = 4;  //几列
   if(count == 6 || count == 9)
    {
         cloumn = 3;
    }
    else if(count == 4)
    {
        cloumn  = 2;
    }
    m_mousePress = false;

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->setSpacing(0);
    vLay->setMargin(0);

    QList<QVariant> layouts;

    int row = count/cloumn;
    for( int i = 0; i < row; i++)
    {
        QHBoxLayout *botmLay = new QHBoxLayout;
         botmLay->setSpacing(0);
         vLay->addLayout(botmLay);
         QVariant var;
         var.setValue(botmLay);
         layouts.append(var);

    }
    int currentRow = 0;
     QHBoxLayout *topLay;
    for(int i = 0; i < count; i++)
    {
        BCSubBoxView *label_cell = new BCSubBoxView(this);
        label_cell->_index = QPoint(i / cloumn,i % cloumn);
        if( i % cloumn == 0)
        {
         topLay = layouts.at(currentRow).value<QHBoxLayout *>();

          currentRow ++;

        }
        topLay->addWidget(label_cell);
    }
    this->setLayout(vLay);
}


