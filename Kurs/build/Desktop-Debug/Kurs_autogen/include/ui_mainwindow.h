/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *ListPlants;
    QPushButton *Delete;
    QLineEdit *InputPlant;
    QPushButton *Add;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *PlantImage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *PlantInfo;
    QLabel *PlantName;
    QLabel *Header;
    QLabel *RegionInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1099, 819);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: black"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #DCE1DB"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        ListPlants = new QListWidget(centralwidget);
        ListPlants->setObjectName("ListPlants");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ListPlants->sizePolicy().hasHeightForWidth());
        ListPlants->setSizePolicy(sizePolicy1);
        ListPlants->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"        font: 500 16pt \"Ubuntu Sans\";\n"
"        border: none;\n"
"    }\n"
"    QListWidget::item {\n"
"        color: #000000;\n"
"        background-color:#DCE1DB;\n"
"        border: 1px solid #dcdcdc;\n"
"        margin: 5px;\n"
"        border-radius:  5px;\n"
"    }\n"
"    QListWidget::item:hover {\n"
"        background-color: #f0f0f0;\n"
"    }\n"
"    QListWidget::item:selected {\n"
"        color: #ffffff;\n"
"        background-color: #535A53;\n"
"    }"));

        gridLayout->addWidget(ListPlants, 1, 0, 3, 1);

        Delete = new QPushButton(centralwidget);
        Delete->setObjectName("Delete");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Delete->sizePolicy().hasHeightForWidth());
        Delete->setSizePolicy(sizePolicy2);
        Delete->setStyleSheet(QString::fromUtf8("color:black"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/bin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Delete->setIcon(icon);
        Delete->setIconSize(QSize(32, 32));
        Delete->setAutoDefault(false);
        Delete->setFlat(false);

        gridLayout->addWidget(Delete, 4, 0, 1, 1);

        InputPlant = new QLineEdit(centralwidget);
        InputPlant->setObjectName("InputPlant");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(5);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(InputPlant->sizePolicy().hasHeightForWidth());
        InputPlant->setSizePolicy(sizePolicy3);
        InputPlant->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(InputPlant, 4, 1, 1, 2);

        Add = new QPushButton(centralwidget);
        Add->setObjectName("Add");
        sizePolicy.setHeightForWidth(Add->sizePolicy().hasHeightForWidth());
        Add->setSizePolicy(sizePolicy);
        Add->setStyleSheet(QString::fromUtf8("color: black"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/plus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Add->setIcon(icon1);
        Add->setIconSize(QSize(32, 32));
        Add->setCheckable(false);
        Add->setAutoDefault(false);
        Add->setFlat(false);

        gridLayout->addWidget(Add, 4, 3, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        PlantImage = new QLabel(widget);
        PlantImage->setObjectName("PlantImage");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(5);
        sizePolicy5.setHeightForWidth(PlantImage->sizePolicy().hasHeightForWidth());
        PlantImage->setSizePolicy(sizePolicy5);
        PlantImage->setAlignment(Qt::AlignCenter);
        PlantImage->setWordWrap(true);

        gridLayout_2->addWidget(PlantImage, 1, 0, 1, 1);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(2);
        sizePolicy6.setVerticalStretch(6);
        sizePolicy6.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy6);
        scrollArea->setStyleSheet(QString::fromUtf8("border:no"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 568, 601));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        PlantInfo = new QLabel(scrollAreaWidgetContents);
        PlantInfo->setObjectName("PlantInfo");
        sizePolicy.setHeightForWidth(PlantInfo->sizePolicy().hasHeightForWidth());
        PlantInfo->setSizePolicy(sizePolicy);
        PlantInfo->setMinimumSize(QSize(0, 0));
        PlantInfo->setMaximumSize(QSize(1400, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu Sans Mono")});
        font1.setPointSize(12);
        font1.setBold(false);
        PlantInfo->setFont(font1);
        PlantInfo->setStyleSheet(QString::fromUtf8("color:black"));
        PlantInfo->setTextFormat(Qt::AutoText);
        PlantInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        PlantInfo->setWordWrap(true);

        verticalLayout_2->addWidget(PlantInfo);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 1, 1, 1);

        PlantName = new QLabel(widget);
        PlantName->setObjectName("PlantName");
        sizePolicy.setHeightForWidth(PlantName->sizePolicy().hasHeightForWidth());
        PlantName->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(true);
        PlantName->setFont(font2);
        PlantName->setStyleSheet(QString::fromUtf8("color:black"));
        PlantName->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(PlantName, 0, 0, 1, 2);


        gridLayout->addWidget(widget, 3, 1, 1, 3);

        Header = new QLabel(centralwidget);
        Header->setObjectName("Header");
        sizePolicy.setHeightForWidth(Header->sizePolicy().hasHeightForWidth());
        Header->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(30);
        Header->setFont(font3);
        Header->setStyleSheet(QString::fromUtf8("color:black"));
        Header->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Header, 1, 1, 1, 3);

        RegionInfo = new QLabel(centralwidget);
        RegionInfo->setObjectName("RegionInfo");
        sizePolicy.setHeightForWidth(RegionInfo->sizePolicy().hasHeightForWidth());
        RegionInfo->setSizePolicy(sizePolicy);
        RegionInfo->setFont(font);
        RegionInfo->setStyleSheet(QString::fromUtf8("color:black"));
        RegionInfo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(RegionInfo, 2, 1, 1, 3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        Add->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        PlantInfo->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265 &quot;\320\255\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\321\217 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\320\271&quot;. </p><p><br/></p><p>\320\222 \321\215\321\202\320\276\320\274 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\262\321\213 \321\201\320\274\320\276\320\266\320\265\321\202\320\265 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\321\202\321\214 \320\262 \321\201\320\262\320\276\321\216 \321\215\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\321\216 \320\275\320\276\320\262\321\213\320\265 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\321\217: \320\270\321\205 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217"
                        ", \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\270 \320\272\321\200\320\260\321\202\320\272\321\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\275\320\270\321\205.<br/><br/>\320\242\320\260\320\272\320\266\320\265, \320\262\321\213 \321\201\320\274\320\276\320\266\320\265\321\202\320\265 \320\277\321\200\320\276\321\201\320\274\320\260\321\202\321\200\320\270\320\262\320\260\321\202\321\214 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\321\217, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \321\203\320\266\320\265 \321\205\321\200\320\260\320\275\321\217\321\202\321\201\321\217 \320\262 \320\262\320\260\321\210\320\265\320\271 \321\215\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\320\270. \320\224\320\273\321\217 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260 \321\202\320\265\320\272\321\203\321\211\320\270\321\205 \321\200"
                        "\320\260\321\201\321\202\320\265\320\275\320\270\320\271 \320\275\320\260\320\266\320\270\320\274\320\260\320\271\321\202\320\265 \320\275\320\260 \320\270\320\267 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 \320\262 \320\273\320\265\320\262\320\276\320\271 \320\272\320\276\320\273\320\276\320\275\320\272\320\265.<br/><br/>\320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \321\203\320\264\320\260\320\273\321\217\321\202\321\214 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\321\217 \320\270\320\267 \321\201\320\262\320\276\320\271 \321\215\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\320\270. \320\237\321\200\320\276\321\201\321\202\320\276 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\320\265 \321\201\320\273\320\265\320\262\320\260, \320\277\320\276\321\201\320\273\320\265 \321\207\320\265\320\263\320\276 \320\275\320\260\320\266\320\274\320\270"
                        "\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 &quot;\320\243\320\264\320\260\320\273\320\270\321\202\321\214&quot; \321\201\320\273\320\265\320\262\320\260 \321\201\320\275\320\270\320\267\321\203.<br/><br/>\320\224\320\273\321\217 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\321\217 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\321\217 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \321\202\320\265\320\272\321\201\321\202 \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \320\237\320\232\320\234 (\320\277\321\200\320\260\320\262\320\276\320\271 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 \320\274\321\213\321\210\320\270) \320\277\320\276\321\201\320\273\320\265 \321\207\320\265\320\263\320\276 \320\275\320"
                        "\260 \320\262\321\201\320\277\320\273\321\213\320\262\320\260\321\216\321\211\320\265\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 &quot;\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214&quot; \320\270 \320\262\321\213 \321\201\320\274\320\276\320\266\320\265\321\202\320\265 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202. </p><p>\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\233\320\232\320\234 (\320\273\320\265\320\262\321\203\321\216 \320\272\320\275\320\276\320\277\320\272\321\203 \320\274\321\213\321\210\320\270) \320\277\320\276 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\321\216 \321\207\321\202\320\276\320\261\321\213 \320\276\321\202\320\272\321\200\321\213\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\262 \320\276\321\202\320\264\320\265\320\273\321"
                        "\214\320\275\320\276\320\274 \320\276\320\272\320\275\320\265.</p></body></html>", nullptr));
        PlantName->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        Header->setText(QCoreApplication::translate("MainWindow", "\320\255\320\275\321\206\320\270\320\272\320\273\320\276\320\277\320\265\320\264\320\270\321\217 \321\200\320\260\321\201\321\202\320\265\320\275\320\270\320\271", nullptr));
        RegionInfo->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\321\201\321\201\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
