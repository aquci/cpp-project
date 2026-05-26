#include "jarvis.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cstring>

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    Profile mod;

    while (true) {
        drawUI();

        int ch = getch();

        switch (ch) {

            case '1':
                mod.openStudy();
                break;

            case '2':
                mod.openGame();
                break;

            case '3':
                mod.openMusic();
                break;

            case '4':
                mod.openJarvis();
                break;

            case 'd': case 'D':
                mod.DotaFocus();
                break;

            case 'm': case 'M':
                mod.Minecraft();
                break;

            case '0':
                endwin();
                return 0;

            case 'k': case 'K':
                mod.KillAll();
                return 0;

            case 'p': case 'P':
                mod.poweroff();
                return 0;

            case 'u': case 'U':
                mod.update();
                return 0;

            default:
                break;
        }
    }
}

