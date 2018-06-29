#include "BCSettingDisplayInfoDlg.h"
#include "ui_BCSettingDisplayInfoDlg.h"
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include "../Common/BCCommon.h"
#include "../Common/BCLocalServer.h"

BCSettingDisplayInfoDlg::BCSettingDisplayInfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCSettingDisplayInfoDlg)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowTitle(tr("屏幕信息"));
    this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

    QLabel *subLabel = new QLabel(this);
    float width = 857;
    float height = 210;
    float x = 0;
    float y = 1;
    subLabel->resize(width,height);
    subLabel->move(x,y);
    subLabel->setStyleSheet("background-color:gray; color: black;");
    //创建具体的小块label和but
       int count = 27;
       int clomCount = 9;
       float margin = 0;
       float width_cell = (width - 4 * margin)/clomCount;
       float height_cell = width_cell-25;
       qDebug()<<width_cell<<height_cell;
       //如果手动设置了小块的宽高以设置的为标准
       float setWidth = 95.22;
       float setHeight = 70.22;
       for(int i = 0; i < count;i++){

               QLabel *label_cell = new QLabel(subLabel);

                if(setWidth != 0){
                    width_cell = setWidth;
                    height_cell = setHeight;
                  }

                label_cell->resize(width_cell,height_cell);
                 label_cell->move((i%clomCount)*(width_cell + margin) + margin,(i/clomCount)*(height_cell + margin) + margin);


               //label_cell->setStyleSheet( "border-radius: 0px;  border: 0.5px groove white;");
               label_cell->setStyleSheet("QLabel{color: red;  " " border-radius: 0px;  border: 0.5px groove white;}");
               label_cell->setText(tr("无设备"));

              label_cell->setAlignment(Qt::AlignCenter);

       }

       subLabel->resize(clomCount * width_cell,count/clomCount * height_cell+2);
       this->setFixedSize(clomCount * width_cell,count/clomCount * height_cell * 2.0241546);
       ui->listView->resize(clomCount * width_cell,count/clomCount * height_cell * 1.0241546 - 52);
       ui->listView->move(0,count/clomCount * height_cell+2);
       ui->listView->setEnabled(true);
     subLabel->show();

//     BCLocalServer *pLocalServer = BCLocalServer::Application();
//     pLocalServer->GetDisplayInfo();

}

BCSettingDisplayInfoDlg::~BCSettingDisplayInfoDlg()
{
    delete ui;
}

void BCSettingDisplayInfoDlg::on_pushButton_2_clicked()
{
    close();
}

void BCSettingDisplayInfoDlg::on_pushButton_clicked()
{
    close();
}
