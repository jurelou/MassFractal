#ifndef	FRACTALWIDGET_H
#define	FRACTALWIDGET_H

#include <QPixmap>
#include <QWidget>
#include "RenderThread.h"

class FractalWidget : public QWidget
{
    Q_OBJECT

public:
    FractalWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void updatePixmap(const QImage &image, double scaleFactor);
    void zoom(double zoomFactor);

private:
    void scroll(int deltaX, int deltaY);

    RenderThread thread;
    QPixmap pixmap;
    QPoint pixmapOffset;
    QPoint lastDragPos;
    double centerX;
    double centerY;
    double pixmapScale;
    double curScale;
};
#endif // FRACTALWIDGET_H