#include "pieces.h"

Pieces::Pieces(QObject *parent) : QObject(parent)
{

}
Pieces::Pieces(PiecesTypes type, Color color)
{

    this->type = type;
    this->clr = color;
    switch (type) {

        case Pawn :
            if(color == White){
                piecePixmap.load(":/images/pawn_white.png");
            }else{
                piecePixmap.load(":/images/pawn_black.png");
            }
        break;
        case Rook :
            if(color == White){
                piecePixmap.load(":/images/rook_white.png");
            }else{
                piecePixmap.load(":/images/rook_black.png");
            }
        break;
        case Knight :
            if(color == White){
                piecePixmap.load(":/images/knight_white.png");
            }else{
                piecePixmap.load(":/images/knight_black.png");
            }
        break;
        case Bishop :
            if(color == White){
                piecePixmap.load(":/images/bishop_white.png");
            }else{
                piecePixmap.load(":/images/bishop_black.png");
            }
        break;
        case Queen :
            if(color == White){
                piecePixmap.load(":/images/queen_white.png");
            }else{
                piecePixmap.load(":/images/queen_black.png");
            }
        break;
        case King :
            if(color == White){
                piecePixmap.load(":/images/king_white.png");
            }else{
                piecePixmap.load(":/images/king_black.png");
            }
        break;
        case Empty :
            if(color == White){

            }else{

            }
        break;


    }
}
void Pieces::setPieceType(PiecesTypes type,Color color)
{
    switch (type) {

        case Pawn :
            if(color == White){
                piecePixmap.load(":/images/pawn_white.png");
            }else{
                piecePixmap.load(":/images/pawn_black.png");
            }
        break;
        case Rook :
            if(color == White){
                piecePixmap.load(":/images/rook_white.png");
            }else{
                piecePixmap.load(":/images/rook_black.png");
            }
        break;
        case Knight :
            if(color == White){
                piecePixmap.load(":/images/knight_white.png");
            }else{
                piecePixmap.load(":/images/knight_black.png");
            }
        break;
        case Bishop :
            if(color == White){
                piecePixmap.load(":/images/bishop_white.png");
            }else{
                piecePixmap.load(":/images/bishop_black.png");
            }
        break;
        case Queen :
            if(color == White){
                piecePixmap.load(":/images/queen_white.png");
            }else{
                piecePixmap.load(":/images/queen_black.png");
            }
        break;
        case King :
            if(color == White){
                piecePixmap.load(":/images/king_white.png");
            }else{
                piecePixmap.load(":/images/king_black.png");
            }
        break;
        case Empty :
            qDebug() << "hakan";
            if(color == White){
                piecePixmap.load(":/images/king_black.png");
            }else{
                piecePixmap.load(":/images/king_black.png");
            }
        break;


    }
}
Movement Pieces::getPossibleMoves(PiecesTypes type){

    Movement movement;

    switch (type) {
        case Empty:
            movement.x.clear();
            movement.y.clear();
        break;
        case Pawn:
        //1,2 to forward, if available 1,-1 to diagonal
            movement.x.clear();
            movement.y.clear();
            movement.x.push_back(1);
            movement.x.push_back(2);
            movement.y.push_back(0);
            movement.y.push_back(1);
            movement.y.push_back(-1);
        break;

    }

    return movement;
}
