﻿#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>

class QGraphicsScene;
class QKeyEvent;
class Snake;
class Food;
class Wall;
class MainWindow;

class GameController : QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent=0);
    ~GameController();

    void snakeAteFood(Snake *snake, Food *food);
    void snakeHitWall(Snake *snake, Wall *wall);
    void snakeAteItself(Snake *snake);
public slots:
    void pause();
    void resume();
    void gameOver();
protected:
    bool eventFilter(QObject *object, QEvent *event);
private:
    void handleKeyPress(QKeyEvent *event);
    void addNewFood();
    void findTowRandom(int &x, int &y);

    MainWindow *parent;
    QTimer timer;
    QGraphicsScene &scene;
    Snake *snake;
};

#endif // GAMECONTROLLER_H
