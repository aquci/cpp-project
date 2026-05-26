#pragma once
#include <string>

struct Profile
{
    std::string name;

    void openStudy();
    void openGame();
    void openMusic();
    void openJarvis();
    void DotaFocus();
    void Minecraft();
    void KillAll();
    void poweroff();
    void update();
};

void drawUI();
