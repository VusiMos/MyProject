// A file of common things that I am notsur
#ifndef UTILS_H
#define UTILS_H
#include <vector>

using std::vector;

typedef vector<int> Position;

typedef enum
{
  LEFT,
  RIGHT,
  UP,
  DOWN
} Direction;

typedef enum
{ALIVE,
 DIVING,
  DEAD
}State;

typedef enum
{
    MENU,
    GAME,
    HELP,
    OPTIONS
}ScreenView;

#endif
