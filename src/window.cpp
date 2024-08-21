#include "window.h"

int Window::getWinHeight()
{
    return windowHeight;
}

int Window::getWinWidth()
{
    return windowWidth;
}

void Window::setWinHeigth()
{
    cout << "Set window height: ";
    cin >> windowHeight;

    if (windowHeight < 0 || windowHeight > monitor->getMonitorHeight())
    {
        cerr << "Wrong input. Try again." << endl;
        setWinHeigth();
    }
}

void Window::setWinWidth()
{
    cout << "Set window height: ";
    cin >> windowWidth;
    if (windowWidth < 0 || windowWidth > monitor->getMonitorWidth())
    {
        cerr << "Wrong input. Try again." << endl;
        setWinWidth();
    }
}

vector<int> Window::getLeftUpperCorner()
{
    return leftUpperCorner;
}

void Window::stateControl(string user_command)
{
    if (user_command == "move")
        inputCommand = Window::move;
    else if (user_command == "resize")
        inputCommand = Window::resize;
    else if (user_command == "display")
        inputCommand = Window::display;
    else if (user_command == "close")
        inputCommand = Window::close;
    else
    {
        cerr << "Wrong command!" << endl;
        inputCommand = Window::standby;
    }

    if (inputCommand == Window::move)
        moveWindow();
    else if (inputCommand == Window::resize)
        resizeWindow();
    else if (inputCommand == Window::display)
        displayWindow();
    else if (inputCommand == Window::close)
        closeWindow();
}

int Window::getWindowHeigth()
{
    return windowHeight;
}

int Window::getWindnowWidth()
{
    return windowWidth;
}

void Window::moveWindow()
{
    int x = 0;
    int y = 0;
    cout << "Input coordinate x: ";
    cin >> x;
    cout << "Input coordinate y: ";
    cin >> y;

    if (x < 0 || y < 0 || x > monitor->getMonitorWidth() || y > monitor->getMonitorHeight())
    {
        cerr << "Wrong input. Try again." << endl;
        moveWindow();
    }
    else
    {
        leftUpperCorner[0] = x;
        leftUpperCorner[1] = y;
        cout << "Window moved to " << leftUpperCorner[0] << " " << leftUpperCorner[1] << endl;
    }
}

void Window::resizeWindow()
{
    cout << "Input new window size: ";
    setWinHeigth();
    setWinWidth();

    cout << "Window resized to " << getWinHeight() << "x" << getWinWidth() << endl;
}

void Window::displayWindow()
{
    cout << "Show monitor:" << endl;
    for (int i = 0; i < monitor->getMonitorHeight(); i++)
    {
        for (int j = 0; j < monitor->getMonitorWidth(); j++)
        {
            if (i >= leftUpperCorner[1] && i < leftUpperCorner[1] + windowHeight &&
                j >= leftUpperCorner[0] && j < leftUpperCorner[0] + windowWidth)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Window::closeWindow()
{
    cout << "Goodbye!";
    delete monitor;
}

int Window::Monitor::getMonitorHeight()
{
    return monitorHeight;
}

int Window::Monitor::getMonitorWidth()
{
    return monitorWidth;
}