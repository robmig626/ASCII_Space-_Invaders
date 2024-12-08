#pragma once
#include "Node.h"

class EnemyBase : public Node
{
private:
	int m_PosX;
	int m_PosY;
	char m_Avatar;
public:

	EnemyBase();
	EnemyBase(int X, int Y, char Avatar);

	virtual void BeginPlay();
	virtual void Tick();

	int GetPosX() const;
	int GetPosY() const;
	char GetAvatar() const;

};