#include "window.h"

int main()
{
    Window* window = new Window();
    string commandInput;

    while (commandInput != "close")
    {
        cout << "Input command: ";
        cin >> commandInput;
        window->stateControl(commandInput);
    }

    delete window;
}
