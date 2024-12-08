#include"Player.h"

void Player::BeginPlay()
{
	PosX = 10;
	PosY = 18;
}

void Player::Tick()
{
	if (GetKeyState('A') & 0x8000)
	{
		MoveLeft();
	}

	if (GetKeyState('D') & 0x8000)
	{
		MoveRight();
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		Shoot();
	}
}

void Player::MoveLeft()
{
	if (PosX > 0)
	{
		PosX--;
	}
}

void Player::MoveRight()
{
	if (PosX < 19)
	{
		PosX++;
	}
}

void Player::Shoot()
{
	Bullet* FiredBullet = new Bullet(PosX, PosY - 1, 1);
	if (BulletHead)
	{
		FiredBullet->InsertBefore(BulletHead);
		BulletHead = (Bullet*)BulletHead->previous;
	}
	else
	{
		BulletHead = FiredBullet;
	}
}

char Player::GetAvatar()
{
	return Avatar;
}

int Player::GetPosX()
{
	return PosX;
}

void Player::SetPosX(int newPosX)
{
	PosX = newPosX;
}

int Player::GetPosY()
{
	return PosY;
}

void Player::SetPosY(int newPosY)
{
	PosY = newPosY;
}

Bullet* Player::GetBullets()
{
	return BulletHead;
}

void Player::SetBulletsNull()
{
	BulletHead = nullptr;
}