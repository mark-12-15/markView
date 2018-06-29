#include "BCFaceWidget.h"
#include "ui_BCFaceWidget.h"

#include <QDebug>
#include "BCDecoder.h"
#include "BCControl.h"
#include "BCSignal.h"
#include "BCVideoControl.h"
#include "BCSystemplan.h"
#include "BCScene.h"
#include "BCMatrix.h"
#include "BCMatrixCut.h"
#include "BCMatrixInput.h"
#include "BCCutScreen.h"
#include "../Common/BCCommon.h"
#include "../Model/BCMChannel.h"
#include "../Model/BCMMatrix.h"

// 信号源结构体
struct SSigSrcObject {
    int type;   // 类型
    int valid;  // 是否可用
    int px;     // 最小像素高度
};

BCFaceWidget::BCFaceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCFaceWidget)
{
    ui->setupUi(this);

    Refresh();
}

BCFaceWidget::~BCFaceWidget()
{
    UpdateSignalSourceSort();

    delete ui;
}

QWidget* BCFaceWidget::GetWidget(MainWindow::SIGNALSOURCETYPE eType)
{
    QWidget *pWidget = NULL;
    for (int i = 0; i < ui->verticalLayout->count(); i++) {
        // 如果已经找到了则直接退出循环
        if (NULL != pWidget)
            break;

        // 当前item为空则进入下次循环
        QLayoutItem *pItem = ui->verticalLayout->itemAt( i );
        if (NULL == pItem)
            continue;

        // 根据参数判断强转成哪个类型
        switch ( eType ) {
        case MainWindow::INPUTCHANNELSSIGSRC: {
            pWidget = dynamic_cast<BCControl*>( pItem->widget() );
        }
            break;
        case MainWindow::CUSTINPUTCHANNELSSIGSRC: {
            pWidget = dynamic_cast<BCSignal*>( pItem->widget() );
        }
            break;
        case MainWindow::VIDEOCONTROLSIGSRC: {
            pWidget = dynamic_cast<BCVideoControl*>( pItem->widget() );
        }
            break;
        case MainWindow::SYSPLANSIGSRC: {
            pWidget = dynamic_cast<BCSystemplan*>( pItem->widget() );
        }
            break;
        case MainWindow::DECODERSIGSRC: {
            pWidget = dynamic_cast<BCDecoder*>( pItem->widget() );
        }
            break;
        case MainWindow::CATCHNETDISPLAYSIGSRC: {
            pWidget = dynamic_cast<BCCutScreen*>( pItem->widget() );
        }
            break;
        case MainWindow::MATRIXPANELSIGSRC: {
            pWidget = dynamic_cast<BCMatrix*>( pItem->widget() );
        }
            break;
        case MainWindow::MATRIXINPUTSIGSRC: {
            pWidget = dynamic_cast<BCMatrixInput*>( pItem->widget() );
        }
            break;
        case MainWindow::MATRIXSWAPSIGSRC: {
            pWidget = dynamic_cast<BCMatrixCut*>( pItem->widget() );
        }
            break;
        case MainWindow::WINDOWSCENESIGSRC: {
            pWidget = dynamic_cast<BCScene*>( pItem->widget() );
        }
            break;
        default:
            break;
        }
    }

    return pWidget;
}

void BCFaceWidget::RefreshChannelName(int type)
{
    if (0 == type) {
        BCControl *pWidget = dynamic_cast<BCControl*>( GetWidget( MainWindow::INPUTCHANNELSSIGSRC ) );
        if (NULL != pWidget)
            pWidget->RefreshInputChannelName();
    } else {
        BCSignal *pWidget = dynamic_cast<BCSignal*>( GetWidget( MainWindow::CUSTINPUTCHANNELSSIGSRC ) );
        if (NULL != pWidget)
            pWidget->RefreshInputChannelName();
    }
}

void BCFaceWidget::Refresh(int nReconstruction)
{
    if (1 == nReconstruction)  {
        // 1.清空现有的Layout链表
        QLayoutItem *pSignalSrcItem = NULL;
        while( (pSignalSrcItem = ui->verticalLayout->takeAt(0)) !=0) {
            // 将LayoutItem内的Widget实例父类置空
            QWidget *pSignalSrcWidget = pSignalSrcItem->widget();
            if (NULL != pSignalSrcWidget)
                pSignalSrcWidget->setParent(NULL);

            // 删除LayoutItem
            delete pSignalSrcItem;
            pSignalSrcItem = NULL;
        }

        // 2.根据文件获得内部控件的排序
        QList<SSigSrcObject> lstSignalSource = GetSignalSourceSort();
        for (int i = 0; i < lstSignalSource.count(); i++) {
            SSigSrcObject obj = lstSignalSource.at(i);

            // pt的y值表示是否显示，1显示，0隐藏，-1不显示
            if (-1 == obj.valid)
                continue;

            // pt的x值表示控件的类型，类型具体含义参见类型定义
            MainWindow::SIGNALSOURCETYPE eType = (MainWindow::SIGNALSOURCETYPE)obj.type;
            switch ( eType ) {
            case MainWindow::INPUTCHANNELSSIGSRC: {
                ui->verticalLayout->addWidget(new BCControl((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::CUSTINPUTCHANNELSSIGSRC: {
                ui->verticalLayout->addWidget(new BCSignal((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::VIDEOCONTROLSIGSRC: {
                ui->verticalLayout->addWidget(new BCVideoControl((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::SYSPLANSIGSRC: {
                ui->verticalLayout->addWidget(new BCSystemplan((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::DECODERSIGSRC: {
                // 这里判断是否有IPV信号源，如果没有IPV信号源则隐藏
                MainWindow *pMainWindow = BCCommon::Application();
                QList<BCMChannel *> lstChannel = pMainWindow->GetInputChannels();
                for (int i = 0; i < lstChannel.count(); i++) {
                    BCMChannel *pChannel = lstChannel.at( i );
                    if (1 != pChannel->GetChannelType())
                        continue;

                    ui->verticalLayout->addWidget(new BCDecoder((bool)obj.valid, obj.px));
                    break;
                }
            }
                break;
            case MainWindow::CATCHNETDISPLAYSIGSRC: {
                ui->verticalLayout->addWidget(new BCCutScreen((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::MATRIXPANELSIGSRC: {
                // 这里判断是否有矩阵联控，有则显示
                if (-1 != BCCommon::g_nIsContainsMatrix) {
                    MainWindow *pMainWindow = BCCommon::Application();
                    QList<BCMMatrix *> lstMatrix = pMainWindow->GetMMatrix();
                    for (int i = 0; i < lstMatrix.count(); i++) {
                        BCMMatrix *pMatrix = lstMatrix.at( i );
                        if (1 != pMatrix->jointWithVP4000)
                            continue;

                        ui->verticalLayout->addWidget(new BCMatrix((bool)obj.valid, obj.px));
                        break;
                    }
                }
            }
                break;
            case MainWindow::MATRIXINPUTSIGSRC: {
                ui->verticalLayout->addWidget(new BCMatrixInput((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::MATRIXSWAPSIGSRC: {
                ui->verticalLayout->addWidget(new BCMatrixCut((bool)obj.valid, obj.px));
            }
                break;
            case MainWindow::WINDOWSCENESIGSRC: {
                ui->verticalLayout->addWidget(new BCScene((bool)obj.valid, obj.px));
            }
                break;
            default:
                break;
            }
        }
    } else {
        // 目前只刷新场景，因为其他都是全局对象，不需要刷新
        for (int i = 0; i < ui->verticalLayout->count(); i++) {
            // 当前item为空则进入下次循环
            QLayoutItem *pItem = ui->verticalLayout->itemAt( i );
            if (NULL == pItem)
                continue;

            BCScene *pSceneWidget = dynamic_cast<BCScene*>( pItem->widget() );
            if (NULL != pSceneWidget)
                pSceneWidget->Refresh();

            BCControl *pInputChannelWidget = dynamic_cast<BCControl*>( pItem->widget() );
            if (NULL != pInputChannelWidget)
                pInputChannelWidget->Refresh();
        }
    }
}

QList<SSigSrcObject> BCFaceWidget::GetSignalSourceSort()
{
    // 结果链表
    QList<SSigSrcObject> lstRes;

    QFile file( QString("../xml/BCSignalSourceConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "open BCSignalSourceConfig.xml error.";
        return lstRes;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile ) {
        qDebug() << "load BCSignalSourceConfig.xml error.";
        return lstRes;
    }

    // 二级链表
    QDomElement docElem = doc.documentElement();

    for (int i = 0; i < docElem.childNodes().count(); i++) {
        QDomNode nodeSortType = docElem.childNodes().at(i);

        // nodeName 分两种currentSort为当前排序，defaultSort为默认排序
        QString qsSortType = nodeSortType.nodeName();
        if (qsSortType != QString("currentSort"))
            continue;

        for (int j = 0; j < nodeSortType.childNodes().count(); j++) {
            QDomNode nodeType = nodeSortType.childNodes().at(j);
            if ( !nodeType.isElement() )
                continue;

            QDomElement eleType = nodeType.toElement();

            // 构造元对象并添加到链表
            SSigSrcObject obj;
            obj.type = eleType.attribute(QString("type")).toInt();
            obj.valid = eleType.attribute(QString("valid")).toInt();
            obj.px = eleType.attribute(QString("px")).toInt();
            lstRes.append( obj );
        }
    }

    return lstRes;
}

void BCFaceWidget::UpdateSignalSourceSort()
{
    // 1.构造信号源的链表
    QList<SSigSrcObject> lstSignalSources;

    bool bVisible = true;
    for (int i = 0; i < ui->verticalLayout->count(); i++) {
        // 当前item为空则进入下次循环
        QLayoutItem *pItem = ui->verticalLayout->itemAt( i );
        if (NULL == pItem)
            continue;

        // 根据参数判断强转成哪个类型
        SSigSrcObject obj;
        BCControl *pControl = dynamic_cast<BCControl*>( pItem->widget() );
        if (NULL != pControl) {
            obj.type = (int)MainWindow::INPUTCHANNELSSIGSRC;
            obj.valid = pControl->IsVisible() ? 1 : 0;
            obj.px = pControl->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCSignal *pSignal = dynamic_cast<BCSignal*>( pItem->widget() );
        if (NULL != pSignal) {
            obj.type = (int)MainWindow::CUSTINPUTCHANNELSSIGSRC;
            obj.valid = pSignal->IsVisible() ? 1 : 0;
            obj.px = pSignal->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCVideoControl *pVideoControl = dynamic_cast<BCVideoControl*>( pItem->widget() );
        if (NULL != pVideoControl) {
            obj.type = (int)MainWindow::VIDEOCONTROLSIGSRC;
            obj.valid = pVideoControl->IsVisible() ? 1 : 0;
            obj.px = pVideoControl->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCSystemplan *pSystemPlan = dynamic_cast<BCSystemplan*>( pItem->widget() );
        if (NULL != pSystemPlan) {
            obj.type = (int)MainWindow::SYSPLANSIGSRC;
            obj.valid = pSystemPlan->IsVisible() ? 1 : 0;
            obj.px = pSystemPlan->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCDecoder *pDecoder = dynamic_cast<BCDecoder*>( pItem->widget() );
        if (NULL != pDecoder) {
            obj.type = (int)MainWindow::DECODERSIGSRC;
            obj.valid = pDecoder->IsVisible() ? 1 : 0;
            obj.px = pDecoder->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCCutScreen *pCutScreen = dynamic_cast<BCCutScreen*>( pItem->widget() );
        if (NULL != pCutScreen) {
            obj.type = (int)MainWindow::CATCHNETDISPLAYSIGSRC;
            obj.valid = pCutScreen->IsVisible() ? 1 : 0;
            obj.px = pCutScreen->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCMatrix *pMatrix = dynamic_cast<BCMatrix*>( pItem->widget() );
        if (NULL != pMatrix) {
            obj.type = (int)MainWindow::MATRIXPANELSIGSRC;
            obj.valid = pMatrix->IsVisible() ? 1 : 0;
            obj.px = pMatrix->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCMatrixInput *pMatrixInput = dynamic_cast<BCMatrixInput*>( pItem->widget() );
        if (NULL != pMatrixInput) {
            obj.type = (int)MainWindow::MATRIXINPUTSIGSRC;
            obj.valid = pMatrixInput->IsVisible() ? 1 : 0;
            obj.px = pMatrixInput->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCMatrixCut *pMatrixCut = dynamic_cast<BCMatrixCut*>( pItem->widget() );
        if (NULL != pMatrixCut) {
            obj.type = (int)MainWindow::MATRIXSWAPSIGSRC;
            obj.valid = pMatrixCut->IsVisible() ? 1 : 0;
            obj.px = pMatrixCut->m_minHeight;
            lstSignalSources.append( obj );
        }

        BCScene *pScene = dynamic_cast<BCScene*>( pItem->widget() );
        if (NULL != pScene) {
            obj.type = (int)MainWindow::WINDOWSCENESIGSRC;
            obj.valid = pScene->IsVisible() ? 1 : 0;
            obj.px = pScene->m_minHeight;
            lstSignalSources.append( obj );
        }
    }

    // 2.写入文件
    QFile file( QString("../xml/BCSignalSourceConfig.xml") );
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    // 将文件内容读到QDomDocument中
    QDomDocument doc;
    bool bLoadFile = doc.setContent(&file);
    file.close();

    if ( !bLoadFile )
        return;

    // 二级链表
    QDomElement docElem = doc.documentElement();

    // 修改节点
    for (int j = 0; j < docElem.childNodes().count(); j++) {
        QDomNode sortNode = docElem.childNodes().at(j);
        if ( !sortNode.isElement() )
            continue;

        QDomElement eleCurrentSort = sortNode.toElement();
        if (eleCurrentSort.nodeName() != QString("currentSort"))
            continue;

        // 创建当前排序节点
        QListIterator<SSigSrcObject> it( lstSignalSources );
        while (it.hasNext()) {
            SSigSrcObject obj = it.next();

            // 找到节点
            for (int i = 0; i < eleCurrentSort.childNodes().count(); i++) {
                QDomNode node = eleCurrentSort.childNodes().at(i);
                if ( !node.isElement() )
                    continue;

                // 找到type相同的node
                QDomElement ele = node.toElement();
                int nCurrentType = ele.attribute("type").toInt();
                if (nCurrentType != obj.type)
                    continue;

                // 创建currentSort节点信息
                QDomElement eleNewNode = doc.createElement(QString("node"));
                eleNewNode.setAttribute(QString("type"), QString::number(obj.type));
                eleNewNode.setAttribute(QString("valid"), QString::number(obj.valid));
                eleNewNode.setAttribute(QString("px"), QString::number(obj.px));

                eleCurrentSort.replaceChild(eleNewNode, node);
                break;
            }
        }
    }

    // 写入文件
    if( !file.open(QIODevice::WriteOnly | QIODevice::Truncate) )
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

