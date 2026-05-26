#include "jarvis.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cstring>

void Profile::openStudy() {
    system("nohup firefox > /dev/null 2>&1 &");
    system("nohup obsidian >/dev/null 2>&1 &");
}

void Profile::openGame() {
    system("nohup steam > /dev/null 2>&1 &");
    system("nohup firefox > /dev/null 2>&1 &");
}

void Profile::openMusic() {
    system("nohup firefox --new-tab https://soundcloud.com >/dev/null 2>&1 &");
    system("nohup krita >/dev/null 2>&1 &");
}

void Profile::openJarvis() {

    system("nohup kitty sh -c 'nano jarvis.cpp' >/dev/null 2>&1 &");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    system("nohup kitty sh -c 'nano jarvisUi.cpp' >/dev/null 2>&1 &");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    system("nohup kitty sh -c 'nano jarvis.hpp' >/dev/null 2>&1 &");
}

void Profile::DotaFocus() {
    system("nohup kitty --title steam sh -c 'steam steam://rungameid/570' >/dev/null 2>&1 &");    
    system("nohup obsidian >/dev/null 2>&1 &");
}

void Profile::Minecraft() {
    system("kitty --hold sh -c 'java -jar /home/aqusha/TLauncher.jar'");
}

void Profile::KillAll() {
    
    endwin();

    system("killall firefox");
    system("killall steam");
    system("killall obsidian");
    system("killall krita");

    system("nohup kitty sh -c './jarvis' >/dev/null 2>&1 &");
    system("exit");
}

void Profile::poweroff() {
    system("poweroff");
}

void Profile::update() {
    system("nohup java -jar /home/aqusha/TLauncher.jar &");
}

void drawUI() {
    clear();

    int h, w;
    getmaxyx(stdscr, h, w);

    const char* title = "JARVIS";

    mvprintw(h/2 - 8, (w - strlen(title)) / 2, "%s", title);

    mvprintw(h/2 - 6, (w - 22) / 2, "[1] Study");
    mvprintw(h/2 - 5, (w - 22) / 2, "[2] Game");
    mvprintw(h/2 - 4, (w - 22) / 2, "[3] Music");
    mvprintw(h/2 - 3, (w - 22) / 2, "[4] Edit jarvis");
    mvprintw(h/2 - 2, (w - 22) / 2, "[D] Dota");
    mvprintw(h/2 - 1, (w - 22) / 2, "[M] Minecraft");

    mvprintw(h/2 + 2, (w - 10) / 2, "[0] Exit");
    mvprintw(h/2 + 3, (w - 10) / 2, "[K] killall");
    mvprintw(h/2 + 4, (w - 10) / 2, "[P] poweroff");
    mvprintw(h/2 + 5, (w - 10) / 2, "[U] update");

   refresh();
}
