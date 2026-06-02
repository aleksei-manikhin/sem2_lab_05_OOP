/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QGroupBox *visualPanelGroup;
    QGridLayout *visualLayout;
    QVBoxLayout *floorInfoLayout5;
    QSpacerItem *floorInfoTopSpacer5;
    QLabel *floorNumberLabel5;
    QLabel *floorCaptionLabel5;
    QSpacerItem *floorInfoBottomSpacer5;
    QVBoxLayout *floorInfoLayout4;
    QSpacerItem *floorInfoTopSpacer4;
    QLabel *floorNumberLabel4;
    QLabel *floorCaptionLabel4;
    QSpacerItem *floorInfoBottomSpacer4;
    QVBoxLayout *floorInfoLayout3;
    QSpacerItem *floorInfoTopSpacer3;
    QLabel *floorNumberLabel3;
    QLabel *floorCaptionLabel3;
    QSpacerItem *floorInfoBottomSpacer3;
    QVBoxLayout *floorInfoLayout2;
    QSpacerItem *floorInfoTopSpacer2;
    QLabel *floorNumberLabel2;
    QLabel *floorCaptionLabel2;
    QSpacerItem *floorInfoBottomSpacer2;
    QVBoxLayout *floorInfoLayout1;
    QSpacerItem *floorInfoTopSpacer1;
    QLabel *floorNumberLabel1;
    QLabel *floorCaptionLabel1;
    QSpacerItem *floorInfoBottomSpacer1;
    QFrame *shaftFrame;
    QFrame *leftRailFrame;
    QFrame *rightRailFrame;
    QFrame *floorDividerFrame5;
    QFrame *floorDividerFrame4;
    QFrame *floorDividerFrame3;
    QFrame *floorDividerFrame2;
    QFrame *elevatorCabinFrame;
    QFrame *leftDoorFrame;
    QFrame *rightDoorFrame;
    QHBoxLayout *callButtonsLayout5;
    QSpacerItem *callLeftSpacer5;
    QPushButton *callDownButton5;
    QSpacerItem *callRightSpacer5;
    QHBoxLayout *callButtonsLayout4;
    QSpacerItem *callLeftSpacer4;
    QPushButton *callUpButton4;
    QPushButton *callDownButton4;
    QSpacerItem *callRightSpacer4;
    QHBoxLayout *callButtonsLayout3;
    QSpacerItem *callLeftSpacer3;
    QPushButton *callUpButton3;
    QPushButton *callDownButton3;
    QSpacerItem *callRightSpacer3;
    QHBoxLayout *callButtonsLayout2;
    QSpacerItem *callLeftSpacer2;
    QPushButton *callUpButton2;
    QPushButton *callDownButton2;
    QSpacerItem *callRightSpacer2;
    QHBoxLayout *callButtonsLayout1;
    QSpacerItem *callLeftSpacer1;
    QPushButton *callUpButton1;
    QSpacerItem *callRightSpacer1;
    QVBoxLayout *controlPanelLayout;
    QGroupBox *cabinPanelGroup;
    QVBoxLayout *cabinPanelLayout;
    QLabel *chooseFloorLabel;
    QHBoxLayout *cabinFloorButtonsLayout;
    QPushButton *cabinFloorButton1;
    QPushButton *cabinFloorButton2;
    QPushButton *cabinFloorButton3;
    QPushButton *cabinFloorButton4;
    QPushButton *cabinFloorButton5;
    QHBoxLayout *doorButtonsLayout;
    QPushButton *openDoorsButton;
    QPushButton *closeDoorsButton;
    QGroupBox *statusGroup;
    QFormLayout *statusLayout;
    QLabel *currentFloorTitleLabel;
    QLabel *currentFloorValueLabel;
    QLabel *directionTitleLabel;
    QLabel *directionValueLabel;
    QLabel *cabinStateTitleLabel;
    QLabel *cabinStateValueLabel;
    QLabel *doorsStateTitleLabel;
    QLabel *doorsStateValueLabel;
    QLabel *targetFloorTitleLabel;
    QLabel *targetFloorValueLabel;
    QGroupBox *logGroup;
    QVBoxLayout *logLayout;
    QPlainTextEdit *eventLogEdit;
    QHBoxLayout *clearLogLayout;
    QSpacerItem *clearLogSpacer;
    QPushButton *clearLogButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 680);
        MainWindow->setMinimumSize(QSize(1000, 680));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: #f6f8fb;\n"
"}\n"
"\n"
"QWidget {\n"
"    color: #1f2933;\n"
"    font-family: \"Segoe UI\", \"Arial\";\n"
"    font-size: 15px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background: #ffffff;\n"
"    border: 1px solid #d7dde5;\n"
"    border-radius: 8px;\n"
"    margin-top: 18px;\n"
"    font-weight: 600;\n"
"    color: #1555b3;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    left: 12px;\n"
"    padding: 0 6px;\n"
"    background: #ffffff;\n"
"    color: #1555b3;\n"
"    font-size: 18px;\n"
"    font-weight: 700;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background: #ffffff;\n"
"    border: 1px solid #c9d1dc;\n"
"    border-radius: 7px;\n"
"    color: #1f2933;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #f3f7fd;\n"
"    border-color: #9bb7df;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #dceaff;\n"
"    border-color: #1f5fbf;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    bac"
                        "kground: #e7f0ff;\n"
"    border: 2px solid #1f5fbf;\n"
"    color: #174a9c;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background: #edf0f3;\n"
"    border-color: #d2d7de;\n"
"    color: #98a1ad;\n"
"}\n"
"\n"
"QLabel {\n"
"    background: transparent;\n"
"}\n"
"\n"
"#visualPanelGroup,\n"
"#cabinPanelGroup,\n"
"#statusGroup,\n"
"#logGroup {\n"
"    background: #ffffff;\n"
"}\n"
"\n"
"#floorNumberLabel1,\n"
"#floorNumberLabel2,\n"
"#floorNumberLabel3,\n"
"#floorNumberLabel4,\n"
"#floorNumberLabel5 {\n"
"    color: #174a9c;\n"
"    font-size: 34px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#floorCaptionLabel1,\n"
"#floorCaptionLabel2,\n"
"#floorCaptionLabel3,\n"
"#floorCaptionLabel4,\n"
"#floorCaptionLabel5 {\n"
"    color: #2f3741;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"#shaftFrame {\n"
"    background: #dde5ee;\n"
"    border: 2px solid #2d3742;\n"
"    border-radius: 0;\n"
"}\n"
"\n"
"#leftRailFrame,\n"
"#rightRailFrame {\n"
"    background: #8798a8;\n"
"    border: 1px solid #25313b;\n"
"}\n"
"\n"
"#floor"
                        "DividerFrame2,\n"
"#floorDividerFrame3,\n"
"#floorDividerFrame4,\n"
"#floorDividerFrame5 {\n"
"    color: #303a44;\n"
"    background: #303a44;\n"
"}\n"
"\n"
"#elevatorCabinFrame {\n"
"    background: #cfd9e4;\n"
"    border: 2px solid #111827;\n"
"}\n"
"\n"
"#leftDoorFrame,\n"
"#rightDoorFrame {\n"
"    background: #d7e1eb;\n"
"    border: 1px solid #1f2933;\n"
"}\n"
"\n"
"#callUpButton1,\n"
"#callUpButton2,\n"
"#callUpButton3,\n"
"#callUpButton4 {\n"
"    color: #168821;\n"
"    font-size: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#callDownButton2,\n"
"#callDownButton3,\n"
"#callDownButton4,\n"
"#callDownButton5 {\n"
"    color: #111827;\n"
"    font-size: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#callUpButton1:checked,\n"
"#callUpButton2:checked,\n"
"#callUpButton3:checked,\n"
"#callUpButton4:checked {\n"
"    background: #e8f8eb;\n"
"    border: 2px solid #168821;\n"
"    color: #0f7a1a;\n"
"}\n"
"\n"
"#callDownButton2:checked,\n"
"#callDownButton3:checked,\n"
"#callDownButton4:checked,\n"
"#cal"
                        "lDownButton5:checked {\n"
"    background: #e7f0ff;\n"
"    border: 2px solid #174a9c;\n"
"    color: #174a9c;\n"
"}\n"
"\n"
"#cabinFloorButton1,\n"
"#cabinFloorButton2,\n"
"#cabinFloorButton3,\n"
"#cabinFloorButton4,\n"
"#cabinFloorButton5 {\n"
"    color: #174a9c;\n"
"    font-size: 32px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#cabinFloorButton1:checked,\n"
"#cabinFloorButton2:checked,\n"
"#cabinFloorButton3:checked,\n"
"#cabinFloorButton4:checked,\n"
"#cabinFloorButton5:checked {\n"
"    background: #e7f0ff;\n"
"    border: 2px solid #174a9c;\n"
"}\n"
"\n"
"#openDoorsButton,\n"
"#closeDoorsButton {\n"
"    font-size: 16px;\n"
"    min-height: 54px;\n"
"}\n"
"\n"
"#currentFloorValueLabel,\n"
"#targetFloorValueLabel {\n"
"    color: #174a9c;\n"
"    font-size: 18px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"#directionValueLabel,\n"
"#cabinStateValueLabel {\n"
"    color: #4b5563;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"#doorsStateValueLabel {\n"
"    color: #168821;\n"
"    font-weight: 700;\n"
"}\n"
"\n"
""
                        "#eventLogEdit {\n"
"    background: #fbfcfe;\n"
"    border: 1px solid #c9d1dc;\n"
"    border-radius: 6px;\n"
"    color: #1f2933;\n"
"    font-family: \"Consolas\", \"Courier New\", monospace;\n"
"    font-size: 14px;\n"
"    selection-background-color: #cfe0ff;\n"
"}\n"
"\n"
"#clearLogButton {\n"
"    min-height: 34px;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(12, 12, 12, 12);
        visualPanelGroup = new QGroupBox(centralwidget);
        visualPanelGroup->setObjectName("visualPanelGroup");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(visualPanelGroup->sizePolicy().hasHeightForWidth());
        visualPanelGroup->setSizePolicy(sizePolicy);
        visualPanelGroup->setMinimumSize(QSize(560, 620));
        visualLayout = new QGridLayout(visualPanelGroup);
        visualLayout->setObjectName("visualLayout");
        visualLayout->setHorizontalSpacing(12);
        visualLayout->setVerticalSpacing(0);
        visualLayout->setContentsMargins(12, 18, 12, 12);
        floorInfoLayout5 = new QVBoxLayout();
        floorInfoLayout5->setSpacing(2);
        floorInfoLayout5->setObjectName("floorInfoLayout5");
        floorInfoTopSpacer5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout5->addItem(floorInfoTopSpacer5);

        floorNumberLabel5 = new QLabel(visualPanelGroup);
        floorNumberLabel5->setObjectName("floorNumberLabel5");
        floorNumberLabel5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout5->addWidget(floorNumberLabel5);

        floorCaptionLabel5 = new QLabel(visualPanelGroup);
        floorCaptionLabel5->setObjectName("floorCaptionLabel5");
        floorCaptionLabel5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout5->addWidget(floorCaptionLabel5);

        floorInfoBottomSpacer5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout5->addItem(floorInfoBottomSpacer5);


        visualLayout->addLayout(floorInfoLayout5, 0, 0, 1, 1);

        floorInfoLayout4 = new QVBoxLayout();
        floorInfoLayout4->setSpacing(2);
        floorInfoLayout4->setObjectName("floorInfoLayout4");
        floorInfoTopSpacer4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout4->addItem(floorInfoTopSpacer4);

        floorNumberLabel4 = new QLabel(visualPanelGroup);
        floorNumberLabel4->setObjectName("floorNumberLabel4");
        floorNumberLabel4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout4->addWidget(floorNumberLabel4);

        floorCaptionLabel4 = new QLabel(visualPanelGroup);
        floorCaptionLabel4->setObjectName("floorCaptionLabel4");
        floorCaptionLabel4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout4->addWidget(floorCaptionLabel4);

        floorInfoBottomSpacer4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout4->addItem(floorInfoBottomSpacer4);


        visualLayout->addLayout(floorInfoLayout4, 1, 0, 1, 1);

        floorInfoLayout3 = new QVBoxLayout();
        floorInfoLayout3->setSpacing(2);
        floorInfoLayout3->setObjectName("floorInfoLayout3");
        floorInfoTopSpacer3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout3->addItem(floorInfoTopSpacer3);

        floorNumberLabel3 = new QLabel(visualPanelGroup);
        floorNumberLabel3->setObjectName("floorNumberLabel3");
        floorNumberLabel3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout3->addWidget(floorNumberLabel3);

        floorCaptionLabel3 = new QLabel(visualPanelGroup);
        floorCaptionLabel3->setObjectName("floorCaptionLabel3");
        floorCaptionLabel3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout3->addWidget(floorCaptionLabel3);

        floorInfoBottomSpacer3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout3->addItem(floorInfoBottomSpacer3);


        visualLayout->addLayout(floorInfoLayout3, 2, 0, 1, 1);

        floorInfoLayout2 = new QVBoxLayout();
        floorInfoLayout2->setSpacing(2);
        floorInfoLayout2->setObjectName("floorInfoLayout2");
        floorInfoTopSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout2->addItem(floorInfoTopSpacer2);

        floorNumberLabel2 = new QLabel(visualPanelGroup);
        floorNumberLabel2->setObjectName("floorNumberLabel2");
        floorNumberLabel2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout2->addWidget(floorNumberLabel2);

        floorCaptionLabel2 = new QLabel(visualPanelGroup);
        floorCaptionLabel2->setObjectName("floorCaptionLabel2");
        floorCaptionLabel2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout2->addWidget(floorCaptionLabel2);

        floorInfoBottomSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout2->addItem(floorInfoBottomSpacer2);


        visualLayout->addLayout(floorInfoLayout2, 3, 0, 1, 1);

        floorInfoLayout1 = new QVBoxLayout();
        floorInfoLayout1->setSpacing(2);
        floorInfoLayout1->setObjectName("floorInfoLayout1");
        floorInfoTopSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout1->addItem(floorInfoTopSpacer1);

        floorNumberLabel1 = new QLabel(visualPanelGroup);
        floorNumberLabel1->setObjectName("floorNumberLabel1");
        floorNumberLabel1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout1->addWidget(floorNumberLabel1);

        floorCaptionLabel1 = new QLabel(visualPanelGroup);
        floorCaptionLabel1->setObjectName("floorCaptionLabel1");
        floorCaptionLabel1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        floorInfoLayout1->addWidget(floorCaptionLabel1);

        floorInfoBottomSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        floorInfoLayout1->addItem(floorInfoBottomSpacer1);


        visualLayout->addLayout(floorInfoLayout1, 4, 0, 1, 1);

        shaftFrame = new QFrame(visualPanelGroup);
        shaftFrame->setObjectName("shaftFrame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shaftFrame->sizePolicy().hasHeightForWidth());
        shaftFrame->setSizePolicy(sizePolicy1);
        shaftFrame->setMinimumSize(QSize(260, 560));
        shaftFrame->setMaximumSize(QSize(260, 560));
        shaftFrame->setFrameShape(QFrame::Shape::Box);
        shaftFrame->setFrameShadow(QFrame::Shadow::Plain);
        leftRailFrame = new QFrame(shaftFrame);
        leftRailFrame->setObjectName("leftRailFrame");
        leftRailFrame->setGeometry(QRect(42, 10, 14, 540));
        leftRailFrame->setFrameShape(QFrame::Shape::Box);
        rightRailFrame = new QFrame(shaftFrame);
        rightRailFrame->setObjectName("rightRailFrame");
        rightRailFrame->setGeometry(QRect(204, 10, 14, 540));
        rightRailFrame->setFrameShape(QFrame::Shape::Box);
        floorDividerFrame5 = new QFrame(shaftFrame);
        floorDividerFrame5->setObjectName("floorDividerFrame5");
        floorDividerFrame5->setGeometry(QRect(20, 112, 220, 3));
        floorDividerFrame5->setFrameShape(QFrame::Shape::HLine);
        floorDividerFrame5->setFrameShadow(QFrame::Shadow::Sunken);
        floorDividerFrame4 = new QFrame(shaftFrame);
        floorDividerFrame4->setObjectName("floorDividerFrame4");
        floorDividerFrame4->setGeometry(QRect(20, 224, 220, 3));
        floorDividerFrame4->setFrameShape(QFrame::Shape::HLine);
        floorDividerFrame4->setFrameShadow(QFrame::Shadow::Sunken);
        floorDividerFrame3 = new QFrame(shaftFrame);
        floorDividerFrame3->setObjectName("floorDividerFrame3");
        floorDividerFrame3->setGeometry(QRect(20, 336, 220, 3));
        floorDividerFrame3->setFrameShape(QFrame::Shape::HLine);
        floorDividerFrame3->setFrameShadow(QFrame::Shadow::Sunken);
        floorDividerFrame2 = new QFrame(shaftFrame);
        floorDividerFrame2->setObjectName("floorDividerFrame2");
        floorDividerFrame2->setGeometry(QRect(20, 448, 220, 3));
        floorDividerFrame2->setFrameShape(QFrame::Shape::HLine);
        floorDividerFrame2->setFrameShadow(QFrame::Shadow::Sunken);
        elevatorCabinFrame = new QFrame(shaftFrame);
        elevatorCabinFrame->setObjectName("elevatorCabinFrame");
        elevatorCabinFrame->setGeometry(QRect(66, 456, 128, 96));
        elevatorCabinFrame->setMinimumSize(QSize(120, 90));
        elevatorCabinFrame->setFrameShape(QFrame::Shape::Box);
        elevatorCabinFrame->setFrameShadow(QFrame::Shadow::Raised);
        leftDoorFrame = new QFrame(elevatorCabinFrame);
        leftDoorFrame->setObjectName("leftDoorFrame");
        leftDoorFrame->setGeometry(QRect(0, 0, 64, 96));
        leftDoorFrame->setFrameShape(QFrame::Shape::Box);
        leftDoorFrame->setFrameShadow(QFrame::Shadow::Plain);
        rightDoorFrame = new QFrame(elevatorCabinFrame);
        rightDoorFrame->setObjectName("rightDoorFrame");
        rightDoorFrame->setGeometry(QRect(64, 0, 64, 96));
        rightDoorFrame->setFrameShape(QFrame::Shape::Box);
        rightDoorFrame->setFrameShadow(QFrame::Shadow::Plain);

        visualLayout->addWidget(shaftFrame, 0, 1, 5, 1);

        callButtonsLayout5 = new QHBoxLayout();
        callButtonsLayout5->setObjectName("callButtonsLayout5");
        callLeftSpacer5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout5->addItem(callLeftSpacer5);

        callDownButton5 = new QPushButton(visualPanelGroup);
        callDownButton5->setObjectName("callDownButton5");
        callDownButton5->setMinimumSize(QSize(44, 44));
        callDownButton5->setCheckable(true);

        callButtonsLayout5->addWidget(callDownButton5);

        callRightSpacer5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout5->addItem(callRightSpacer5);


        visualLayout->addLayout(callButtonsLayout5, 0, 2, 1, 1);

        callButtonsLayout4 = new QHBoxLayout();
        callButtonsLayout4->setObjectName("callButtonsLayout4");
        callLeftSpacer4 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout4->addItem(callLeftSpacer4);

        callUpButton4 = new QPushButton(visualPanelGroup);
        callUpButton4->setObjectName("callUpButton4");
        callUpButton4->setMinimumSize(QSize(44, 44));
        callUpButton4->setCheckable(true);

        callButtonsLayout4->addWidget(callUpButton4);

        callDownButton4 = new QPushButton(visualPanelGroup);
        callDownButton4->setObjectName("callDownButton4");
        callDownButton4->setMinimumSize(QSize(44, 44));
        callDownButton4->setCheckable(true);

        callButtonsLayout4->addWidget(callDownButton4);

        callRightSpacer4 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout4->addItem(callRightSpacer4);


        visualLayout->addLayout(callButtonsLayout4, 1, 2, 1, 1);

        callButtonsLayout3 = new QHBoxLayout();
        callButtonsLayout3->setObjectName("callButtonsLayout3");
        callLeftSpacer3 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout3->addItem(callLeftSpacer3);

        callUpButton3 = new QPushButton(visualPanelGroup);
        callUpButton3->setObjectName("callUpButton3");
        callUpButton3->setMinimumSize(QSize(44, 44));
        callUpButton3->setCheckable(true);

        callButtonsLayout3->addWidget(callUpButton3);

        callDownButton3 = new QPushButton(visualPanelGroup);
        callDownButton3->setObjectName("callDownButton3");
        callDownButton3->setMinimumSize(QSize(44, 44));
        callDownButton3->setCheckable(true);

        callButtonsLayout3->addWidget(callDownButton3);

        callRightSpacer3 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout3->addItem(callRightSpacer3);


        visualLayout->addLayout(callButtonsLayout3, 2, 2, 1, 1);

        callButtonsLayout2 = new QHBoxLayout();
        callButtonsLayout2->setObjectName("callButtonsLayout2");
        callLeftSpacer2 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout2->addItem(callLeftSpacer2);

        callUpButton2 = new QPushButton(visualPanelGroup);
        callUpButton2->setObjectName("callUpButton2");
        callUpButton2->setMinimumSize(QSize(44, 44));
        callUpButton2->setCheckable(true);

        callButtonsLayout2->addWidget(callUpButton2);

        callDownButton2 = new QPushButton(visualPanelGroup);
        callDownButton2->setObjectName("callDownButton2");
        callDownButton2->setMinimumSize(QSize(44, 44));
        callDownButton2->setCheckable(true);

        callButtonsLayout2->addWidget(callDownButton2);

        callRightSpacer2 = new QSpacerItem(12, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout2->addItem(callRightSpacer2);


        visualLayout->addLayout(callButtonsLayout2, 3, 2, 1, 1);

        callButtonsLayout1 = new QHBoxLayout();
        callButtonsLayout1->setObjectName("callButtonsLayout1");
        callLeftSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout1->addItem(callLeftSpacer1);

        callUpButton1 = new QPushButton(visualPanelGroup);
        callUpButton1->setObjectName("callUpButton1");
        callUpButton1->setMinimumSize(QSize(44, 44));
        callUpButton1->setCheckable(true);

        callButtonsLayout1->addWidget(callUpButton1);

        callRightSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        callButtonsLayout1->addItem(callRightSpacer1);


        visualLayout->addLayout(callButtonsLayout1, 4, 2, 1, 1);


        mainLayout->addWidget(visualPanelGroup);

        controlPanelLayout = new QVBoxLayout();
        controlPanelLayout->setSpacing(12);
        controlPanelLayout->setObjectName("controlPanelLayout");
        controlPanelLayout->setContentsMargins(0, 0, 0, 0);
        cabinPanelGroup = new QGroupBox(centralwidget);
        cabinPanelGroup->setObjectName("cabinPanelGroup");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cabinPanelGroup->sizePolicy().hasHeightForWidth());
        cabinPanelGroup->setSizePolicy(sizePolicy2);
        cabinPanelLayout = new QVBoxLayout(cabinPanelGroup);
        cabinPanelLayout->setSpacing(12);
        cabinPanelLayout->setObjectName("cabinPanelLayout");
        chooseFloorLabel = new QLabel(cabinPanelGroup);
        chooseFloorLabel->setObjectName("chooseFloorLabel");

        cabinPanelLayout->addWidget(chooseFloorLabel);

        cabinFloorButtonsLayout = new QHBoxLayout();
        cabinFloorButtonsLayout->setSpacing(8);
        cabinFloorButtonsLayout->setObjectName("cabinFloorButtonsLayout");
        cabinFloorButton1 = new QPushButton(cabinPanelGroup);
        cabinFloorButton1->setObjectName("cabinFloorButton1");
        cabinFloorButton1->setMinimumSize(QSize(64, 64));
        cabinFloorButton1->setCheckable(true);

        cabinFloorButtonsLayout->addWidget(cabinFloorButton1);

        cabinFloorButton2 = new QPushButton(cabinPanelGroup);
        cabinFloorButton2->setObjectName("cabinFloorButton2");
        cabinFloorButton2->setMinimumSize(QSize(64, 64));
        cabinFloorButton2->setCheckable(true);

        cabinFloorButtonsLayout->addWidget(cabinFloorButton2);

        cabinFloorButton3 = new QPushButton(cabinPanelGroup);
        cabinFloorButton3->setObjectName("cabinFloorButton3");
        cabinFloorButton3->setMinimumSize(QSize(64, 64));
        cabinFloorButton3->setCheckable(true);

        cabinFloorButtonsLayout->addWidget(cabinFloorButton3);

        cabinFloorButton4 = new QPushButton(cabinPanelGroup);
        cabinFloorButton4->setObjectName("cabinFloorButton4");
        cabinFloorButton4->setMinimumSize(QSize(64, 64));
        cabinFloorButton4->setCheckable(true);

        cabinFloorButtonsLayout->addWidget(cabinFloorButton4);

        cabinFloorButton5 = new QPushButton(cabinPanelGroup);
        cabinFloorButton5->setObjectName("cabinFloorButton5");
        cabinFloorButton5->setMinimumSize(QSize(64, 64));
        cabinFloorButton5->setCheckable(true);

        cabinFloorButtonsLayout->addWidget(cabinFloorButton5);


        cabinPanelLayout->addLayout(cabinFloorButtonsLayout);

        doorButtonsLayout = new QHBoxLayout();
        doorButtonsLayout->setSpacing(10);
        doorButtonsLayout->setObjectName("doorButtonsLayout");
        openDoorsButton = new QPushButton(cabinPanelGroup);
        openDoorsButton->setObjectName("openDoorsButton");
        openDoorsButton->setMinimumSize(QSize(0, 56));

        doorButtonsLayout->addWidget(openDoorsButton);

        closeDoorsButton = new QPushButton(cabinPanelGroup);
        closeDoorsButton->setObjectName("closeDoorsButton");
        closeDoorsButton->setMinimumSize(QSize(0, 56));

        doorButtonsLayout->addWidget(closeDoorsButton);


        cabinPanelLayout->addLayout(doorButtonsLayout);


        controlPanelLayout->addWidget(cabinPanelGroup);

        statusGroup = new QGroupBox(centralwidget);
        statusGroup->setObjectName("statusGroup");
        sizePolicy2.setHeightForWidth(statusGroup->sizePolicy().hasHeightForWidth());
        statusGroup->setSizePolicy(sizePolicy2);
        statusLayout = new QFormLayout(statusGroup);
        statusLayout->setObjectName("statusLayout");
        statusLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::AllNonFixedFieldsGrow);
        statusLayout->setLabelAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        statusLayout->setFormAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        statusLayout->setHorizontalSpacing(18);
        statusLayout->setVerticalSpacing(10);
        currentFloorTitleLabel = new QLabel(statusGroup);
        currentFloorTitleLabel->setObjectName("currentFloorTitleLabel");

        statusLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, currentFloorTitleLabel);

        currentFloorValueLabel = new QLabel(statusGroup);
        currentFloorValueLabel->setObjectName("currentFloorValueLabel");

        statusLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, currentFloorValueLabel);

        directionTitleLabel = new QLabel(statusGroup);
        directionTitleLabel->setObjectName("directionTitleLabel");

        statusLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, directionTitleLabel);

        directionValueLabel = new QLabel(statusGroup);
        directionValueLabel->setObjectName("directionValueLabel");

        statusLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, directionValueLabel);

        cabinStateTitleLabel = new QLabel(statusGroup);
        cabinStateTitleLabel->setObjectName("cabinStateTitleLabel");

        statusLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, cabinStateTitleLabel);

        cabinStateValueLabel = new QLabel(statusGroup);
        cabinStateValueLabel->setObjectName("cabinStateValueLabel");

        statusLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, cabinStateValueLabel);

        doorsStateTitleLabel = new QLabel(statusGroup);
        doorsStateTitleLabel->setObjectName("doorsStateTitleLabel");

        statusLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, doorsStateTitleLabel);

        doorsStateValueLabel = new QLabel(statusGroup);
        doorsStateValueLabel->setObjectName("doorsStateValueLabel");

        statusLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, doorsStateValueLabel);

        targetFloorTitleLabel = new QLabel(statusGroup);
        targetFloorTitleLabel->setObjectName("targetFloorTitleLabel");

        statusLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, targetFloorTitleLabel);

        targetFloorValueLabel = new QLabel(statusGroup);
        targetFloorValueLabel->setObjectName("targetFloorValueLabel");

        statusLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, targetFloorValueLabel);


        controlPanelLayout->addWidget(statusGroup);

        logGroup = new QGroupBox(centralwidget);
        logGroup->setObjectName("logGroup");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(logGroup->sizePolicy().hasHeightForWidth());
        logGroup->setSizePolicy(sizePolicy3);
        logLayout = new QVBoxLayout(logGroup);
        logLayout->setSpacing(8);
        logLayout->setObjectName("logLayout");
        eventLogEdit = new QPlainTextEdit(logGroup);
        eventLogEdit->setObjectName("eventLogEdit");
        sizePolicy3.setHeightForWidth(eventLogEdit->sizePolicy().hasHeightForWidth());
        eventLogEdit->setSizePolicy(sizePolicy3);
        eventLogEdit->setMinimumSize(QSize(0, 160));
        eventLogEdit->setReadOnly(true);

        logLayout->addWidget(eventLogEdit);

        clearLogLayout = new QHBoxLayout();
        clearLogLayout->setObjectName("clearLogLayout");
        clearLogSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        clearLogLayout->addItem(clearLogSpacer);

        clearLogButton = new QPushButton(logGroup);
        clearLogButton->setObjectName("clearLogButton");
        clearLogButton->setMinimumSize(QSize(150, 36));

        clearLogLayout->addWidget(clearLogButton);


        logLayout->addLayout(clearLogLayout);


        controlPanelLayout->addWidget(logGroup);


        mainLayout->addLayout(controlPanelLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\270\320\274\321\203\320\273\321\217\321\202\320\276\321\200 \320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\321\201\320\272\320\276\320\263\320\276 \320\273\320\270\321\204\321\202\320\260 \342\200\224 5 \321\215\321\202\320\260\320\266\320\265\320\271", nullptr));
        visualPanelGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\273\320\270\321\204\321\202\320\260", nullptr));
        floorNumberLabel5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        floorCaptionLabel5->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266 5", nullptr));
        floorNumberLabel4->setText(QCoreApplication::translate("MainWindow", "67", nullptr));
        floorCaptionLabel4->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266 67", nullptr));
        floorNumberLabel3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        floorCaptionLabel3->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266 3", nullptr));
        floorNumberLabel2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        floorCaptionLabel2->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266 2", nullptr));
        floorNumberLabel1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        floorCaptionLabel1->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266 1", nullptr));
        callDownButton5->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        callUpButton4->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        callDownButton4->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        callUpButton3->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        callDownButton3->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        callUpButton2->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        callDownButton2->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        callUpButton1->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        cabinPanelGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\272\320\260\320\261\320\270\320\275\321\213", nullptr));
        chooseFloorLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\215\321\202\320\260\320\266", nullptr));
        cabinFloorButton1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        cabinFloorButton2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        cabinFloorButton3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        cabinFloorButton4->setText(QCoreApplication::translate("MainWindow", "67", nullptr));
        cabinFloorButton5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        openDoorsButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\262\320\265\321\200\320\270", nullptr));
        closeDoorsButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\264\320\262\320\265\321\200\320\270", nullptr));
        statusGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\273\320\270\321\204\321\202\320\260", nullptr));
        currentFloorTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\215\321\202\320\260\320\266:", nullptr));
        currentFloorValueLabel->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        directionTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265:", nullptr));
        directionValueLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260", nullptr));
        cabinStateTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\272\320\260\320\261\320\270\320\275\321\213:", nullptr));
        cabinStateValueLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265", nullptr));
        doorsStateTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\264\320\262\320\265\321\200\320\265\320\271:", nullptr));
        doorsStateValueLabel->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\213", nullptr));
        targetFloorTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\320\265\320\262\320\276\320\271 \321\215\321\202\320\260\320\266:", nullptr));
        targetFloorValueLabel->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        logGroup->setTitle(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263 \321\201\320\276\320\261\321\213\321\202\320\270\320\271", nullptr));
        clearLogButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\273\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
