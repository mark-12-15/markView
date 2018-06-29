#include "BCSetingCustomSkin.h"
#include "ui_BCSetingCustomSkin.h"
#include "../Common/BCCommon.h"
#include <QColorDialog>

BCSetingCustomSkin::BCSetingCustomSkin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BCSetingCustomSkin)
{
        ui->setupUi(this);
        this->setFixedSize(250,100);
        setWindowTitle(tr("皮肤设置"));
        this->setWindowIcon(QIcon(BCCommon::g_qsImageFilePrefix + BCCommon::g_qsApplicationIcon));

        UILabel *colorLabel = new UILabel(this);
                 colorLabel->resize(70,25);
                 colorLabel->move(127,40);
                 colorLabel->setStyleSheet( "border:1px groove gray;border-radius:35px;");
                 connect(colorLabel,SIGNAL(Clicked(UILabel*)),this,SLOT(selectColor(UILabel*)));
}

BCSetingCustomSkin::~BCSetingCustomSkin()
{
        delete ui;
}

/*
*选择颜色信号槽
 */
void BCSetingCustomSkin::selectColor(UILabel *label)
{
       QColorDialog dialog(Qt::red,this);
       dialog.setOption(QColorDialog::ShowAlphaChannel);
       dialog.exec();

       QColor color = dialog.currentColor();
       QPalette myPalette;
       QColor myColor(color.rgb());
       myColor.setAlphaF(color.alphaF());
       myPalette.setBrush(backgroundRole(),myColor);
       label->setPalette(myPalette);
       label->setAutoFillBackground(true);

}
/*
*cancel按钮
*/
void BCSetingCustomSkin::on_pushButton_cancel_clicked()
{
       close();
}
