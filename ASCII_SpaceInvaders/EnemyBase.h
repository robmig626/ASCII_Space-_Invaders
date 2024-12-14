#pragma once
#include "Node.h"

class EnemyBase : public Node
{
private:
	int m_PosX;
	int m_PosY;
	char m_Avatar;
	int m_Health;
	int m_Speed;
	int m_Direction;

public:

	bool bDestroy;

	EnemyBase();
	~EnemyBase();
	EnemyBase(int X, int Y, char Avatar);

	virtual void BeginPlay();
	virtual void Tick();

	void TakeDamage();
	void Destroy();

	void Move();

	int GetPosX() const;
	int GetPosY() const;
	char GetAvatar() const;
	int GetHealth() const;
	int GetDirection() const;

	void SetDirection(int NewDirection);

};