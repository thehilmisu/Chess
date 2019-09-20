#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    grid = new QGridLayout();
    central = new QWidget();
    setCentralWidget(central);
    centralWidget()->setLayout(grid);


    decorateTable();


}
void MainWindow::decorateTable()
{
    for (int i=0;i<ROW;i++) {

        for (int j=0;j<COLUMN;j++) {
            Square s;
            s.x = i;
            s.y = j;
            s.isVisited=false;
            s.label = new QLabel();
            //s.label->setStyleSheet("color:white;border:1px solid white;");
            s.label->setMinimumWidth(50);
            s.label->setMinimumHeight(50);
            s.label->setAlignment(Qt::AlignCenter);
            if((s.y % 2 == 0)){
                if(s.x % 2 == 0)
                    s.label->setStyleSheet(BLACK_CELL);
                else
                    s.label->setStyleSheet(WHITE_CELL);
            }
            else{
                if(s.x % 2 == 0)
                    s.label->setStyleSheet(WHITE_CELL);
                else
                    s.label->setStyleSheet(BLACK_CELL);

            }

            placePieces(&s);
            s.index++;

            square.append(s);

            grid->addWidget(s.getLabel(),i,j);

        }

    }
}
void MainWindow::placePieces(Square *s)
{
    if(s->x == 1){
        s->piece = new Pieces(Pawn,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if(s->x == ROW - 2){
        s->piece = new Pieces(Pawn,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == 0)){//WHITE ROOK 1
        s->piece = new Pieces(Rook,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == COLUMN-1)){//WHITE ROOK 2
        s->piece = new Pieces(Rook,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == 1)){//WHITE KNIGHT 1
        s->piece = new Pieces(Knight,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == COLUMN-2)){//WHITE KNIGHT 2
        s->piece = new Pieces(Knight,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == 2)){//WHITE BISHOP 1
        s->piece = new Pieces(Bishop,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == COLUMN-3)){//WHITE BISHOP 2
        s->piece = new Pieces(Bishop,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == 3)){//WHITE QUEEN
        s->piece = new Pieces(Queen,White);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == 0) && (s->y == 4)){//WHITE KING
        s->piece = new Pieces(King,White);
        s->label->setPixmap(s->piece->getPixmap());
    }
    //
    else if((s->x == ROW-1) && (s->y == 0)){//BLACK ROOK 1
        s->piece = new Pieces(Rook,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == COLUMN-1)){//BLACK ROOK 2
        s->piece = new Pieces(Rook,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == 1)){//BLACK KNIGHT 1
        s->piece = new Pieces(Knight,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == COLUMN-2)){//BLACK KNIGHT 2
        s->piece = new Pieces(Knight,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == 2)){//BLACK BISHOP 1
        s->piece = new Pieces(Bishop,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == COLUMN-3)){//BLACK BISHOP 2
        s->piece = new Pieces(Bishop,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == 3)){//BLACK QUEEN
        s->piece = new Pieces(Queen,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else if((s->x == ROW-1) && (s->y == 4)){//BLACK KING
        s->piece = new Pieces(King,Black);
        s->label->setPixmap(s->piece->getPixmap());
    }else{//EMPTY
        s->piece = new Pieces(Empty,White);
        s->isVisited = false;
    }


}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint p = event->pos();
    Square s;

    for(int i=0;i<square.size();i++)
    {
        s = square.at(i);
        if(s.label->geometry().contains(p,true)){

            if(s.getLabel()->styleSheet() != POSSIBLE_BLACK_CELL && s.getLabel()->styleSheet() != POSSIBLE_WHITE_CELL)
            {
                qDebug() << "fff if";
                s.isSelected = true;

                highlightMoves(&s);
                if((s.isSelected) && (s.label->styleSheet() == WHITE_CELL)){
                    s.label->setStyleSheet(SELECTED_WHITE_CELL);
                }
                else if((s.isSelected) && (s.label->styleSheet() == BLACK_CELL)){
                    s.label->setStyleSheet(SELECTED_BLACK_CELL);
                }
            }
            else
            {
                qDebug() << "first if";
                //move here
                //for (int j=0;j<square.size();j++)
                {
                    if(s.isSelected==true){
                        qDebug() << "selected";
                        //square.at(j).piece->setPieceType(Empty,s.piece->getColor());
                    }
                }
            }

            //qDebug() << s.x << " " << s.y;
        }
        else
        {
            s.isSelected = false;

            if((!s.isSelected) && (s.label->styleSheet() == SELECTED_BLACK_CELL)){
                s.label->setStyleSheet(BLACK_CELL);
            }
            else if((!s.isSelected) && (s.label->styleSheet() == SELECTED_WHITE_CELL)){
                s.label->setStyleSheet(WHITE_CELL);
            }


        }
    }


}
void MainWindow::highlightMoves(Square *s)
{
    //Only for pawn
    QVector<int> x_values = s->piece->getPossibleMoves(s->piece->getPieceType()).x;
    QVector<int> y_values = s->piece->getPossibleMoves(s->piece->getPieceType()).y;

    for(auto i : x_values){
        int new_x = 0;
        if(s->piece->getColor() == White)
        {
            new_x = s->x + i;
        }
        else//black
        {
            new_x = s->x - i;
        }

        for(int j=0;j<square.size();j++)
        {

            if((new_x == square.at(j).x) && (s->y == square.at(j).y))
            {
                if((square.at(j).label->styleSheet() == WHITE_CELL)&&(!square.at(j).isSelected)){
                    square.at(j).label->setStyleSheet(POSSIBLE_WHITE_CELL);
                }
                else if((square.at(j).label->styleSheet() == BLACK_CELL)&&(!square.at(j).isSelected)){
                   square.at(j).label->setStyleSheet(POSSIBLE_BLACK_CELL);
                }
            }
            else if(s->y != square.at(j).y)
            {
                if((!square.at(j).isSelected) && (square.at(j).label->styleSheet() == POSSIBLE_BLACK_CELL)){
                    square.at(j).label->setStyleSheet(BLACK_CELL);
                }
                else if((!square.at(j).isSelected) && (square.at(j).label->styleSheet() == POSSIBLE_WHITE_CELL)){
                    square.at(j).label->setStyleSheet(WHITE_CELL);
                }
            }

        }

    }



}
MainWindow::~MainWindow()
{
}

