#pragma once
#include <Windows.h>
#include "Bullet.h"

class Player 
{
private:
	char m_Avatar = 'A';
	int m_PosX, m_PosY;
	Bullet* m_BulletHead = nullptr;
public:
	void BeginPlay();
	void Tick();

	void MoveLeft();
	void MoveRight();
	void Shoot();

	char GetAvatar();
	int GetPosX();
	void SetPosX(int newPosX);
	int GetPosY();
	void SetPosY(int newPosY);
	Bullet* GetBullets();
	void SetBulletsNull();
};