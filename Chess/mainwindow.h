#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include "pieces.h"
#include <QMouseEvent>
#include "definitions.h"


class Square
{
public:
    Square(){
        this->isSelected = false;
    }
    int x;
    int y;
    int index = 0;
    bool isSelected;
    bool isVisited = true;
    Pieces *piece;
    QLabel *label;
    QLabel *getLabel(){
        return this->label;
    }
    void setSelected(bool s){
        this->isSelected=s;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGridLayout *grid;
    QWidget *central;
    QVector<Square> square;
    void decorateTable();
    void placePieces(Square *s);
    void highlightMoves(Square *s);

protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
