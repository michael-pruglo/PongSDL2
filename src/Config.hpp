#ifndef PONG_CONFIG_HPP
#define PONG_CONFIG_HPP

namespace config
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    const int PADDLE_WIDTH = 10;
    const int PADDLE_HEIGHT = 80;
    const int PADDLE_X = 80;
    const double PADDLE_SPEED = 0.08;

    const int BALL_SIZE = 20;
    const double BALL_SPEED = 0.05;
    const double BALL_ACCELERATION = 1.05;

    const double PLAYER_GAP_PERCENT = 0.05;

    const int FPS = 60;
}

#endif //PONG_CONFIG_HPP
