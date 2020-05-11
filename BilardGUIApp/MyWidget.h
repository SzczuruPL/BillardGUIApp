#pragma once
#include <QtGui>
#include <QWidget>

class MyWidget :
	public QWidget
{
	void paintEvent(QPaintEvent* event);
};

