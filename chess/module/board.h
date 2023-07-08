#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

class board : public QWidget
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//paint the chess board

signals:

};

#endif // BOARD_H
