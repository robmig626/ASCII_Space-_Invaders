#pragma once
#include <iostream>
#include <Windows.h>

#define FIELDSIZE_X 20
#define FIELDSIZE_Y 20

class Game
{
private:
	bool m_bGameOver = false;
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

	void LoadLevel(int Level);
	void SpawnEnemy(int X, int Y, char Avatar);

public:
	void BeginPlay();
	void Tick();

	bool GetGameOver();
	void SetGameOver(bool newGameOver);
};