#include "EnemyBase.h"

EnemyBase::EnemyBase()
{

}

EnemyBase::EnemyBase(int X, int Y, char Avatar)
{
	m_PosX = X;
	m_PosY = Y;
	m_Avatar = Avatar;
}


void EnemyBase::BeginPlay()
{

}

void EnemyBase::Tick()
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
