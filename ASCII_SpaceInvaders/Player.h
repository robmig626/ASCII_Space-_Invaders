#pragma once
#include <Windows.h>
#include "Bullet.h"

class Player 
{
private:
	char m_Avatar = 'A';
	int m_PosX, m_PosY;
	Bullet* m_BulletHead = nullptr;
	int m_Lives;

public:
	void BeginPlay();
	void Tick();

	void MoveLeft();
	void MoveRight();
	void Shoot();

	char GetAvatar() const;
	int GetPosX() const;
	void SetPosX(int newPosX);
	int GetPosY() const;
	void SetPosY(int newPosY);
	Bullet* GetBullets() const;
	void SetBulletsNull();
	int GetLives() const;
	void TakeDamage();
};