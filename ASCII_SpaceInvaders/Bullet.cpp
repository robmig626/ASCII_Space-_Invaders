#include "Bullet.h"

Bullet::Bullet(int iPosX, int iPosY, int iDirection)
{
	m_PosX = iPosX;
	m_PosY = iPosY;
	m_Direction = iDirection;
}

void Bullet::Tick()
{
	if (m_PosY <= 0 || m_PosY >= 20)
	{
		bDestroy = true;
	}
	else
	{
		m_PosY += (-1) * (m_Direction);
	}
	
}

Bullet* Bullet::GetBullet()
{
	return this;
}

char Bullet::GetAvatar()
{
	return m_Avatar;
}

int Bullet::GetPosX()
{
	return m_PosX;
}

int Bullet::GetPosY()
{
	return m_PosY;
}

void Bullet::Destroy()
{
	this->Remove();
}