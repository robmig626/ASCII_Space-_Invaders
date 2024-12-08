#pragma once
#include <Windows.h>
#include "Bullet.h"

class Player 
{
private:
	char Avatar = 'A';
	int PosX, PosY;
	Bullet* BulletHead = nullptr;
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