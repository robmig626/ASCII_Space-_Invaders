#include"Player.h"

void Player::BeginPlay()
{
	m_PosX = 10;
	m_PosY = 18;
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
	if (m_PosX > 0)
	{
		m_PosX--;
	}
}

void Player::MoveRight()
{
	if (m_PosX < 19)
	{
		m_PosX++;
	}
}

void Player::Shoot()
{
	Bullet* FiredBullet = new Bullet(m_PosX, m_PosY - 1, 1);
	if (m_BulletHead)
	{
		FiredBullet->InsertBefore(m_BulletHead);
		m_BulletHead = (Bullet*)m_BulletHead->previous;
	}
	else
	{
		m_BulletHead = FiredBullet;
	}
}

char Player::GetAvatar() const
{
	return m_Avatar;
}

int Player::GetPosX() const
{
	return m_PosX;
}

void Player::SetPosX(int newPosX)
{
	m_PosX = newPosX;
}

int Player::GetPosY() const
{
	return m_PosY;
}

void Player::SetPosY(int newPosY)
{
	m_PosY = newPosY;
}

Bullet* Player::GetBullets() const
{
	return m_BulletHead;
}

void Player::SetBulletsNull()
{
	m_BulletHead = nullptr;
}

int Player::GetLives() const
{
	return m_Lives;
}

void Player::TakeDamage()
{
	m_Lives--;
}
