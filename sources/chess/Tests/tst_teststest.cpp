#include <QString>
#include <QtTest>
#include "boardLogic.h"
#include "API.h"


class myTests : public QObject
{
    Q_OBJECT

public:
    myTests();

private Q_SLOTS:
    void testSelectFigure();
    void testMoveFigure();
    void testGetFigure();
    void testSetColor();
    void testSetPosition();
};

myTests::myTests()
{
}

void myTests::testSelectFigure()
{
    BoardLogic *b = new BoardLogic();
    myCell pos(6,6);
    b->selectMyFigure(&pos);
    Pawn *p = new Pawn(1,pos);
    QCOMPARE(b->getSelectedFigure()->getFigColor(),p->getFigColor());
    QCOMPARE(b->getSelectedFigure()->getFigPosition()->getXval(),p->getFigPosition()->getXval());
    QCOMPARE(b->getSelectedFigure()->getFigPosition()->getYval(),p->getFigPosition()->getYval());
    delete b;
}

void myTests::testMoveFigure()
{

    BoardLogic *b = new BoardLogic();
    myCell pos(6,6);
    myCell pos2(4,4);
    b->selectMyFigure(&pos);
    b->changeMyFigPosition(&pos2);
    Pawn *p = new Pawn(1,pos2);
    QCOMPARE(b->getMyFigure(&pos2)->getFigColor(),p->getFigColor());
    QCOMPARE(b->getMyFigure(&pos2)->getFigPosition()->getXval(),p->getFigPosition()->getXval());
    QCOMPARE(b->getMyFigure(&pos2)->getFigPosition()->getYval(),p->getFigPosition()->getYval());
    delete b;
    delete p;
}

void myTests::testGetFigure()
{
    BoardLogic *b = new BoardLogic();
    myCell pos(6,6);
    Pawn *p = new Pawn(1,pos);
    QCOMPARE(b->getMyFigure(&pos)->getFigColor(),p->getFigColor());
    QCOMPARE(b->getMyFigure(&pos)->getFigPosition()->getXval(),p->getFigPosition()->getXval());
    QCOMPARE(b->getMyFigure(&pos)->getFigPosition()->getYval(),p->getFigPosition()->getYval());
    delete b;
    delete p;
}

void myTests::testSetColor()
{
    myCell pos(1,1);
    Pawn p1(1,pos);
    p1.setFigColor(0);
    QCOMPARE(p1.getFigColor(),0);
}

void myTests::testSetPosition()
{
    myCell pos(1,1);
    myCell pos2(2,2);
    Pawn p1(1,pos);
    p1.setFigPosition(pos2);
    QCOMPARE(p1.getFigPosition()->getXval(),2);
    QCOMPARE(p1.getFigPosition()->getYval(),2);
}

QTEST_APPLESS_MAIN(myTests)

#include "tst_teststest.moc"
