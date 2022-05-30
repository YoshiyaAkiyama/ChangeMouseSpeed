#include <iostream>
#include <windows.h>
#include <string> 
#include <winuser.h>
#pragma comment(lib, "user32.lib")

using namespace std;

int main(int argc, char* argv[])
{
    int mouseSensitivity = 10;//Windows Default Value is 10
    int mouseSpeed = 0;
    int mouseThreshold1 = 0;
    int mouseThreshold2 = 0;
    int mouseConfig[3];//0: MouseThreshhold1
    if (argc != 5) {
        cout << "Error: Invalid Argument Count";
        return 0;
    }
    mouseSensitivity = stoi(argv[1]);
    mouseThreshold1 = stoi(argv[2]);
    mouseThreshold2 = stoi(argv[3]);
    mouseSpeed = stoi(argv[4]);
    if (!(1 <=mouseSensitivity && mouseSensitivity <=20)) {
        cout << "Error: MouseSensitivity(Argument 1) Must be between 1 and 20";
        return 0;
    }else if (mouseThreshold1 < 0 || mouseThreshold2 < 0) {
        cout << "Error: Mouse Threshold(Argument 2 and Argument 3) must be a postive number";
        return 0;
    }else if (mouseThreshold1 > mouseThreshold2) {
        cout << "Error: MouseThreshold1(Argument 2) must be less than mouseThreshold2(Argument 3)";
        return 0;
    }else if (!(mouseSpeed == 0 || mouseSpeed == 1)) {
        cout << "Error: Mousespeed(Argument 4) must be 0 (Enhanced Pointer Precision off) or 1 (Enhance Pointer Precision on)";
    }

    SystemParametersInfo(
        SPI_SETMOUSESPEED,
        0,
        (LPVOID)mouseSensitivity,
        SPIF_UPDATEINIFILE | SPIF_SENDCHANGE | SPIF_SENDWININICHANGE
    );

    mouseConfig[0] = mouseThreshold1;
    mouseConfig[1] = mouseThreshold2;
    mouseConfig[2] = mouseSpeed;
    SystemParametersInfo(
        SPI_SETMOUSE,      // set mouse information
        0,                 // not used 
        (LPVOID)mouseConfig,        // mouse information 
        SPIF_UPDATEINIFILE | SPIF_SENDCHANGE | SPIF_SENDWININICHANGE);  // update win.ini 
    return 0;
}
