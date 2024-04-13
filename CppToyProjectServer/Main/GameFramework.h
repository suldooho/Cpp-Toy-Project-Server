#pragma once
class GameFramework
{
public:
    static GameFramework& getInstance();

private:
    GameFramework();

public:
    GameFramework(const GameFramework&) = delete;
    GameFramework(GameFramework&&) = delete;
};

