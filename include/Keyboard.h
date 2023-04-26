#include "include.h"

class Keyboard
{
private:
    int key;

public:
    Keyboard();
    ~Keyboard();
    void escKey();
    void upKey();
    void downKey();
    void leftKey();
    void rightKey();
    void numberKey();
    void pauseKey();
};