#include "EnemyBase.h"

EnemyBase::EnemyBase()
{

}

EnemyBase::~EnemyBase()
{
}

EnemyBase::EnemyBase(int X, int Y, char Avatar)
{
	m_PosX = X;
	m_PosY = Y;
	m_Avatar = Avatar;
	m_Health = 5;
}


void EnemyBase::BeginPlay()
{

}

void EnemyBase::Tick()
{
	Move();
}

void EnemyBase::TakeDamage()
{
	m_Health--;
}

void EnemyBase::Destroy()
{
	this->Remove();
}

void EnemyBase::Move()
{

}

int EnemyBase::GetPosX() const
{
	return m_PosX;
}

int EnemyBase::GetPosY() const
{
	return m_PosY;
}

char EnemyBase::GetAvatar() const
{
	return m_Avatar;
}

int EnemyBase::GetHealth() const
{
	return m_Health;
}

int EnemyBase::GetDirection() const
{
	return m_Direction;
}

void EnemyBase::SetDirection(int NewDirection)
{
	m_Direction = NewDirection;
}

