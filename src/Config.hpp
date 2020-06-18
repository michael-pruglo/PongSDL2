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
    const int SCORELINE_X = 20;
    const int LEFT_PADDLE_X = SCORELINE_X+60,
              RIGHT_PADDLE_X = SCREEN_WIDTH - LEFT_PADDLE_X - PADDLE_WIDTH,
              PADDLE_START_Y = SCREEN_CENTER_Y - PADDLE_HEIGHT/2;  //middle of the screen
    const double PADDLE_SPEED = 11.0;

    const int BALL_SIZE = 10;
    const double BALL_SPEED = 3.7;
    const double BALL_ACCELERATION = 1.05;

    const double PLAYER_GAP_PERCENT = 0.05;

    const std::string FONT_FILENAME = "assets\\fonts\\arial.ttf";

    const int FPS = 60;
}

#endif //PONG_CONFIG_HPP
