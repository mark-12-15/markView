#include "BCScreenBtn.h"
#include "BCScreenName.h"

BCScreenBtn::BCScreenBtn(QWidget *parent)
    :QPushButton(parent)
{
    m_num = 0;
    m_name = "";
    this->setMinimumSize(50,50);
    this->setIcon(QIcon(":/Image/1.png"));
    //this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   // connect(this,SIGNAL(rightButtonClicked()),this,SLOT(on_rightButtonClicked()));

    //创建右键菜单
    m_menu = new QMenu();
    m_change_action = new QAction(tr("修改名称"),this);
    m_delete_action = new QAction(tr("删除场景"),this);
    connect(m_change_action, SIGNAL(triggered(bool)), this, SLOT(on_changeaction(bool)));
    connect(m_delete_action, SIGNAL(triggered(bool)), this, SLOT(on_deleteaction(bool)));

}

BCScreenBtn::~BCScreenBtn(){

}

void BCScreenBtn::mouseReleaseEvent(QMouseEvent *e){
   if (Qt::RightButton == e->button())
   {
       emit rightButtonClicked();
   }
   QPushButton::mousePressEvent(e);
}

void BCScreenBtn::on_deleteaction(bool){
    emit signal_close(m_num);
}

void BCScreenBtn::setName(const QString name){
    m_name = name;
}

void BCScreenBtn::on_changeaction(bool){
//    BCScreenName* name = new BCScreenName(m_name);
//    if(name->exec() == QDialog::Accepted){
//            m_name = name->name;
//            this->setText(m_name);
//    }
}

void BCScreenBtn::setNum(const int index){
    m_num = index;
}

int BCScreenBtn::getNum(){
    return m_num;
}

void BCScreenBtn::contextMenuEvent(QContextMenuEvent* event){

   m_menu->clear();
   m_menu->addAction(m_change_action);
   m_menu->addAction(m_delete_action);

   //菜单出现的位置为当前鼠标的位置
   m_menu->exec(QCursor::pos());
   event->accept();
}
