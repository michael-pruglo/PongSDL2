#ifndef PONG_CONFIG_HPP
#define PONG_CONFIG_HPP

namespace config
{
    struct Color {uint8_t r,g,b,a;};

    //screen
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_CENTER_X = SCREEN_WIDTH/2;
    const int SCREEN_CENTER_Y = SCREEN_HEIGHT/2;
    const Color BACKGROUND_COLOR = {55, 63, 81, 255};


    //moving objects
    const int PADDLE_WIDTH = 10;
    const int PADDLE_HEIGHT = 80;
    const int SCORELINE_X = 20;
    const int LEFT_PADDLE_X = SCORELINE_X+60,
              RIGHT_PADDLE_X = SCREEN_WIDTH - LEFT_PADDLE_X - PADDLE_WIDTH,
              PADDLE_START_Y = SCREEN_CENTER_Y - PADDLE_HEIGHT/2;
    const double PADDLE_SPEED = 11.0;
    const Color PADDLE_COLOR = {205, 134, 121, 255};

    const int BALL_SIZE = 10;
    const double BALL_SPEED_INIT = 5.0;
    const double BALL_SPEED_MAX = 25.0;
    const double BALL_ACCELERATION_DELTA = 0.3;
    const int MAX_BALL_ANGLE = 70;
    const Color BALL_COLOR = {238, 215, 210, 255};


    //text
    const std::string FONT_FILENAME = "assets\\fonts\\arial.ttf";
    const int NAME_FONT_SIZE = 20;
    const int LEFT_NAME_X = LEFT_PADDLE_X+PADDLE_WIDTH + 100;
    const int RIGHT_NAME_X = RIGHT_PADDLE_X - 110 - NAME_FONT_SIZE*4;
    const int NAME_Y = 5;
    const int SCORE_FONT_SIZE = 40;
    const Color NAME_COLOR = {85, 107, 76, 255};
    const Color SCORE_COLOR = {203, 219, 176, 255};


    //misc
    const int FPS = 60;
}

#endif //PONG_CONFIG_HPP
