#include "Bullet.h"

Bullet::Bullet(int iPosX, int iPosY, int iDirection)
{
	PosX = iPosX;
	PosY = iPosY;
	Direction = iDirection;
}

void Bullet::Tick()
{
	if (PosY <= 0 || PosY >= 20)
	{
		bDestroy = true;
	}
	else
	{
		PosY += (-1) * (Direction);
	}
	
}

Bullet* Bullet::GetBullet()
{
	return this;
}

char Bullet::GetAvatar()
{
	return Avatar;
}

int Bullet::GetPosX()
{
	return PosX;
}

int Bullet::GetPosY()
{
	return PosY;
}

void Bullet::Destroy()
{
	this->Remove();
}