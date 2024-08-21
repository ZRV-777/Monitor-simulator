#include <iostream>
#include <vector>

using namespace std;

class Window
{
    class Monitor
    {
        int monitorHeight = 50;
        int monitorWidth = 80;

    public:
        int getMonitorHeight();
        int getMonitorWidth();
    };

    class Monitor* monitor = new Monitor();

    enum command
    {
        move,
        resize,
        display,
        close,
        standby
    };

    command inputCommand;
    vector<int> leftUpperCorner = {{0, 0}};

    int windowHeight = 1;
    int windowWidth = 1;

public:
    int getWinHeight();
    int getWinWidth();
    void setWinHeigth();
    void setWinWidth();
    void stateControl(string user_command);
    vector<int> getLeftUpperCorner();
    int getWindowHeigth();
    int getWindnowWidth();
    void moveWindow();
    void resizeWindow();
    void displayWindow();
    void closeWindow();
};