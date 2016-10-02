#ifndef QGRAPHDESIGNER_H
#define QGRAPHDESIGNER_H

#include <QWidget>
#include <QToolButton>
#include <QMap>
#include <QVector>
#include <QLineEdit>
//class qreal;

class QgraphDesigner : public QWidget
{
    Q_OBJECT

public:
    QgraphDesigner(QWidget *parent = 0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    ~QgraphDesigner();
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
private slots:
    void inputManager() ;
    void resetShortestPathManager() ;
    void resetAll() ;
public slots:
    void shortestPath() ;
private:
    enum { Margin = 5 , Radius = 30 , isActivated = -1 , isNotActivated = -2 , Erased = -99 , Infinity = 100000000 };
    QPoint edgeManager ;
    QPoint shortestPathManager ;
    QToolButton* drawTheShortestPath ;
    QToolButton* reset ;
    QLineEdit* reader ;
    QMap< int,QVector<int> > matrix ;
    QMap< int,QVector<int> > weight ;
    QMap< int,QVector<qreal> > angles ;
    QVector<QPointF> positions ;
    QVector<int> path ;
    
};

#endif // QGRAPHDESIGNER_H
