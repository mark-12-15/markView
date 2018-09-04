#include "BCExProcessDialog.h"
#include "ui_BCExProcessDialog.h"
#include <QFileDialog>
#include <QFileIconProvider>
#include <QDebug>
#include <QProcess>
#include "../Common/BCCommon.h"

BCExProcessDialog::BCExProcessDialog(QStringList list,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BCExProcessDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setWindowTitle(tr("外部工具管理"));
    setWindowIcon( QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon) );

    //tablewidget初始化
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //选择整行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //自适应调整
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);  //失去焦点，防止删除不选中的误删

    QStringList header;
    header.append(tr("标题"));
    header.append(tr("文件路径"));
    ui->tableWidget->setHorizontalHeaderLabels(header);


    if(list.isEmpty()){
        m_list.clear();
    }else{
        m_list = list;
    }

    //显示m_list
    DataShow();
}



BCExProcessDialog::~BCExProcessDialog()
{
    delete ui;
}



void BCExProcessDialog::SetTabelWidget(uint row,uint column,QTableWidgetItem* item){
    ui->tableWidget->setItem(row,column,item);

}

void BCExProcessDialog::DataShow(){
    //清空
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();


    //排列
    for(int i = 0 ; i < m_list.size(); i++){
        ui->tableWidget->setRowCount(i + 1);

        QFileInfo fileinfo(m_list.at(i));
        QFileIconProvider icon_provider;
        QIcon icon = icon_provider.icon(fileinfo);

        QTableWidgetItem* item =  new QTableWidgetItem();
        item->setIcon(icon);
        item->setText(fileinfo.baseName());
        ui->tableWidget->setItem(i,0,item);
        qDebug()<<fileinfo.baseName();

        QTableWidgetItem* item1 =  new QTableWidgetItem();
        item1->setText(m_list.at(i));
        ui->tableWidget->setItem(i,1,item1);
        qDebug()<<m_list.at(i);
    }
}

void BCExProcessDialog::on_pushButton_1_clicked()
{
    //添加外部程序
    QString m_path;

    QFileDialog *file = new QFileDialog();
    file->setWindowTitle(tr("打开"));
    file->setDirectory(".");

    file->setNameFilter(tr("Exe Files(*.exe)"));
    if(file->exec() == QDialog::Accepted) {
           m_path = file->selectedFiles().at(0);

           //自动增加行数
           uint index = ui->tableWidget->rowCount() + 1;
           ui->tableWidget->setRowCount(index);

           //添加数据
           QFileInfo fileinfo(m_path);
           QFileIconProvider icon_provider;
           QIcon icon = icon_provider.icon(fileinfo);

           QTableWidgetItem* item = new QTableWidgetItem();
           item->setIcon(icon);
           item->setText(fileinfo.baseName());
           this->SetTabelWidget(index - 1,0,item);


           QTableWidgetItem* item1 = new QTableWidgetItem();
           item1->setText(m_path);
           this->SetTabelWidget(index - 1,1,item1);
           m_list.append(m_path);

    }
}

void BCExProcessDialog::on_pushButton_2_clicked()
{
    int index = ui->tableWidget->currentRow();
    qDebug()<<index;
    if(index != -1){
        ui->tableWidget->removeRow(index);
        m_list.removeAt( index );
    }
}

//上移
void BCExProcessDialog::on_pushButton_3_clicked()
{
    int index = ui->tableWidget->currentRow();
    if((index - 1) >= 0){
        QString tempdown = m_list.at( index);
        QString tempup = m_list.at( index - 1);
        m_list.replace( index - 1 , tempdown );
        m_list.replace( index , tempup );

        DataShow();
    }

}

//下移
void BCExProcessDialog::on_pushButton_4_clicked()
{
    int index = ui->tableWidget->currentRow();
    int count = m_list.size()- 2;

    if((index != -1) && (index <= count)) {
        QString tempdown = m_list.at( index);
        QString tempup = m_list.at( index + 1);
        m_list.replace( index + 1 , tempdown );
        m_list.replace( index , tempup );

        //清空
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();


        //排列
        for(int i = 0 ; i < m_list.size(); i++){
            ui->tableWidget->setRowCount(i + 1);

            QFileInfo fileinfo(m_list.at(i));
            QFileIconProvider icon_provider;
            QIcon icon = icon_provider.icon(fileinfo);

            QTableWidgetItem* item =  new QTableWidgetItem();
            item->setIcon(icon);
            item->setText(fileinfo.baseName());
            ui->tableWidget->setItem(i,0,item);
            qDebug()<<fileinfo.baseName();

            QTableWidgetItem* item1 =  new QTableWidgetItem();
            item1->setText(m_list.at(i));
            ui->tableWidget->setItem(i,1,item1);
            qDebug()<<m_list.at(i);
        }
    }
}

//外部run接口
void BCExProcessDialog::Run(uint index){
    QProcess *myProcess = new QProcess();
    QString str;
    QDir dir;
    str = dir.toNativeSeparators(m_list.at(index));
    str = "\""+str+"\"";
    myProcess->start(str);
}
//外部获取显示接口
QString BCExProcessDialog::GetPath(uint index){
    return m_list.at(index);
}

// liuwl 20150528
#include "../Common/BCCommon.h"
#include "../View/BCRibbonMainToolBar.h"
//#include "../View/BCToolBar.h"
//#include "../View/BCToolButton.h"
//#include "../View/BCMainToolBarGroupBox.h"
void BCExProcessDialog::on_buttonBox_accepted()
{
    MainWindow *pApplication = BCCommon::Application();
    BCRibbonMainToolBar *pRibbonToolBar = pApplication->GetRibbonMainToolBar();
    pRibbonToolBar->SetExtendButtonPath( m_list );
    pRibbonToolBar->RefreshExtendGroup();

//    BCToolButton *pBtn = dynamic_cast<BCToolButton *>( this->parentWidget() );
//    if (NULL == pBtn)
//        return;

//    pBtn->SetExtendButtonPath( m_list );
//    BCMainToolBarGroupBox *pGroup = dynamic_cast<BCMainToolBarGroupBox *>( pBtn->parentWidget()->parentWidget() );
//    if (NULL == pGroup)
//        return;

//    pGroup->ClearButton();
//    for (int i = 0; i < m_list.count(); i++) {
//        pGroup->AddButton(BCToolButton::EXTEND, m_list.at(i));
//    }
}

void BCExProcessDialog::on_m_pOKBtn_clicked()
{
    MainWindow *pApplication = BCCommon::Application();
    BCRibbonMainToolBar *pRibbonToolBar = pApplication->GetRibbonMainToolBar();
    pRibbonToolBar->SetExtendButtonPath( m_list );
    pRibbonToolBar->RefreshExtendGroup();

    this->accept();
}

void BCExProcessDialog::on_m_pCancelBtn_clicked()
{
    this->reject();
}
