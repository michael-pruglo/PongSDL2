#ifndef PONG_CONFIG_HPP
#define PONG_CONFIG_HPP

namespace config
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_CENTER_X = SCREEN_WIDTH/2;
    const int SCREEN_CENTER_Y = SCREEN_HEIGHT/2;

    const int PADDLE_WIDTH = 10;
    const int PADDLE_HEIGHT = 80;
    const int PADDLE_X = 80;
    const double PADDLE_SPEED = 15.0;

    const int BALL_SIZE = 15;
    const double BALL_SPEED = 1.7;
    const double BALL_ACCELERATION = 1.05;

    const double PLAYER_GAP_PERCENT = 0.05;

    const int FPS = 60;
}

#endif //PONG_CONFIG_HPP
