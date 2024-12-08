#pragma once
#include <iostream>
#include <Windows.h>
#include "Player.h"

#define FIELDSIZE_X 20
#define FIELDSIZE_Y 20

class Game
{
private:
	bool bGameOver = false;
	char GameField[FIELDSIZE_X][FIELDSIZE_Y];

	Player* PlayerShip;

	void InitializeField();
	void UpdateField();
	void RenderField();

	void ClearDyingBullets();

public:
	void BeginPlay();
	void Tick();

	bool GetGameOver();
	void SetGameOver(bool newGameOver);
};