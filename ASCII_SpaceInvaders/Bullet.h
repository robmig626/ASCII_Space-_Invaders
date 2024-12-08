#pragma once
#include "Node.h"

class Bullet : public Node
{
private:
	char m_Avatar = '|';
	int m_PosX, m_PosY;
	int m_Direction; //1 is up -1 is down
public:
	bool bDestroy = false;
	Bullet(int iPosX, int iPosY, int iDirection);

	void Tick();

	Bullet* GetBullet();
	char GetAvatar();
	int GetPosX();
	int GetPosY();

	void Destroy();
};