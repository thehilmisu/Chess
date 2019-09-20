#ifndef PIECES_H
#define PIECES_H

#include <QObject>
#include <QPixmap>
#include <QVector>
#include <QDebug>

enum PiecesTypes{
    Empty = 0,
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King,

};
enum Color{
    White=0,
    Black,
};

struct Movement{
    QVector<int> x;
    QVector<int> y;
};

class Pieces : public QObject
{
    Q_OBJECT
public:
    explicit Pieces(QObject *parent = nullptr);
    Pieces(PiecesTypes type, Color color);
    Movement getPossibleMoves(PiecesTypes type);
    void setPieceType(PiecesTypes type,Color color);
    QPixmap getPixmap(){
        return this->piecePixmap;
    }
    PiecesTypes getPieceType(){
        return this->type;
    }
    Color getColor(){
        return this->clr;
    }

private:
    QPixmap piecePixmap;
    PiecesTypes type;
    Color clr;


signals:

public slots:
};

#endif // PIECES_H
