#include "MyWidget.h"

void MyWidget::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);
	QPainterPath path;
	path.addRoundedRect(QRectF(10, 10, 100, 50), 5, 100);
	QPen pen(Qt::black, 1);
	p.setPen(pen);
	p.fillPath(path, Qt::red);
	p.drawPath(path);
}
