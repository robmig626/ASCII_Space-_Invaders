#pragma once
#include <iostream>
#include <Windows.h>
#include "Constants.h"

class Game
{
public:
	Game();
private:
	bool m_bGameOver = false;
	bool m_bWin = false;
	char m_GameField[FIELDSIZE_X][FIELDSIZE_Y];

	class Player* m_PlayerShip;

	//Linked Lists containing bullets and enemies
	class Bullet* m_PlayerBullets;
	class EnemyBase* m_Enemies;
	class Bullet* m_EnemyBullets;

	

	void InitializeField();
	void UpdateField();
	void RenderField();

	void ClearDyingBullets();
	void ClearDyingEnemies();

	void LoadLevel(int Level);
	void SpawnEnemy(int X, int Y, char Avatar);

public:
	void BeginPlay();
	void Tick();

	bool GetGameOver();
	void SetGameOver(bool newGameOver);
};