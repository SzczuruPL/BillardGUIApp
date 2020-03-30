#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BilardGUIApp.h"

class BilardGUIApp : public QMainWindow
{
	Q_OBJECT

public:
	BilardGUIApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::BilardGUIAppClass ui;
};
