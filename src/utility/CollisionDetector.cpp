#include "CollisionDetector.hpp"

bool CollisionDetector::rectCollide(const Rectangle& rect1, const Rectangle& rect2)
{
    double left1 =   rect1.topLeft().getX();
    double top1 =    rect1.topLeft().getY();
    double right1 =  rect1.bottomRight().getX();
    double bottom1 = rect1.bottomRight().getY();
    double left2 =   rect2.topLeft().getX();
    double top2 =    rect2.topLeft().getY();
    double right2 =  rect2.bottomRight().getX();
    double bottom2 = rect2.bottomRight().getY();

    return left1<=right2 && right1>=left2 && top1<=bottom2 && bottom1>=top2;
}
//TODO: refactor to reuse code
bool CollisionDetector::updateAfterCollidingUp(Ball& ball, const Rectangle& wall)
{
    auto rect = ball.getRect();
    auto vec = ball.getVelocityVector();
    Position fin = ball.nextPosition();
    if (vec.angle >= M_PI || vec.angle == 0) //not moving up
        return false;

    Position crucial1 = rect.topLeft(), crucial2 = rect.topRight();
    auto[dx, dy] = rect.position().diff(fin);
    Position::value_t horLineX1 = wall.bottomLeft().getX(),
                      horLineX2 = wall.bottomRight().getX(),
                      horLineY =  wall.bottomLeft().getY();

    if (willCollideHorizontal(crucial1, crucial2, dx, dy, horLineX1, horLineX2, horLineY))
    {
        ball.moveTo(Position{fin.getX(), 2*horLineY-fin.getY()});
        ball.reflectY();
        return true;
    }
    return false;
}

bool CollisionDetector::updateAfterCollidingDown(Ball& ball, const Rectangle& wall)
{
    auto rect = ball.getRect();
    auto vec = ball.getVelocityVector();
    Position fin = ball.nextPosition();
    if (vec.angle < M_PI) //not moving down
        return false;

    Position crucial1 = rect.bottomLeft(), crucial2 = rect.bottomRight();
    auto[dx, dy] = rect.position().diff(fin);
    Position::value_t horLineX1 = wall.topLeft().getX(),
                      horLineX2 = wall.topRight().getX(),
                      horLineY =  wall.topLeft().getY();

    if (willCollideHorizontal(crucial1, crucial2, dx, dy, horLineX1, horLineX2, horLineY))
    {
        ball.moveTo(Position{fin.getX(), 2*horLineY-(crucial1.getY()+dy)-rect.height()});
        ball.reflectY();
        return true;
    }
    return false;
}

bool CollisionDetector::willCollideHorizontal(Position crucial1, Position crucial2,
                                              Position::value_t dx, Position::value_t dy,
                                              Position::value_t horLineX1, Position::value_t horLineX2,
                                              Position::value_t horLineY)
{
    if (!(crucial1.getY() >= horLineY && crucial1.getY()+dy <= horLineY
        ||crucial1.getY() <= horLineY && crucial1.getY()+dy >= horLineY))
        return false;

    Position::value_t xL = (horLineY-crucial1.getY())*dx/dy + crucial1.getX();
    Position::value_t xR = (horLineY-crucial2.getY())*dx/dy + crucial2.getX();
    return horLineX1<=xR && horLineX2>=xL;
}


bool CollisionDetector::updateAfterCollidingLeft(Ball& ball, const Rectangle& wall)
{
    auto rect = ball.getRect();
    auto vec = ball.getVelocityVector();
    Position fin = ball.nextPosition();
    if (vec.angle <= M_PI/2 || vec.angle >= 3*M_PI/2) //not moving left
        return false;

    Position crucial1 = rect.topLeft(), crucial2 = rect.bottomLeft();
    auto[dx, dy] = rect.position().diff(fin);
    Position::value_t verLineY1 = wall.topRight().getY(),
                      verLineY2 = wall.bottomRight().getY(),
                      verLineX =  wall.topRight().getX();

    if (willCollideVertical(crucial1, crucial2, dx, dy, verLineY1, verLineY2, verLineX))
    {
        ball.moveTo(Position{2*verLineX-fin.getX(), fin.getY()});
        ball.reflectX();
        return true;
    }
    return false;
}

bool CollisionDetector::updateAfterCollidingRight(Ball& ball, const Rectangle& wall)
{
    auto rect = ball.getRect();
    auto vec = ball.getVelocityVector();
    Position fin = ball.nextPosition();
    if (vec.angle >= M_PI/2 && vec.angle <= 3*M_PI/2) //not moving right
        return false;

    Position crucial1 = rect.topRight(), crucial2 = rect.bottomRight();
    auto[dx, dy] = rect.position().diff(fin);
    Position::value_t verLineY1 = wall.topLeft().getY(),
                      verLineY2 = wall.bottomLeft().getY(),
                      verLineX =  wall.topLeft().getX();

    if (willCollideVertical(crucial1, crucial2, dx, dy, verLineY1, verLineY2, verLineX))
    {
        ball.moveTo(Position{2*verLineX-(crucial1.getX()+dx)-rect.width(), fin.getY()});
        ball.reflectX();
        return true;
    }
    return false;
}

bool CollisionDetector::willCollideVertical(Position crucial1, Position crucial2,
                                            Position::value_t dx, Position::value_t dy,
                                            Position::value_t verLineY1, Position::value_t verLineY2,
                                            Position::value_t verLineX)
{
    if (!(crucial1.getX() >= verLineX && crucial1.getX()+dx <= verLineX
        ||crucial1.getX() <= verLineX && crucial1.getX()+dx >= verLineX))
        return false;

    Position::value_t yT = (verLineX-crucial1.getX())*dy/dx + crucial1.getY();
    Position::value_t yB = (verLineX-crucial2.getX())*dy/dx + crucial2.getY();
    return verLineY1<=yB && verLineY2>=yT;
}
