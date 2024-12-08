#include "Game.h"
#include "Player.h"
#include "EnemyBase.h"

void Game::InitializeField()
{
	for (int j = 0; j < FIELDSIZE_Y; j++)
	{
		for (int i = 0; i < FIELDSIZE_X; i++)
		{
			m_GameField[i][j] = ' ';
		}
	}
}

void Game::UpdateField()
{
	InitializeField();

	//Draw Player
	m_GameField[m_PlayerShip->GetPosX()][m_PlayerShip->GetPosY()] = m_PlayerShip->GetAvatar();

	//Draw Bullets
	if (m_PlayerShip->GetBullets())
	{
		Bullet* nextBullet = m_PlayerShip->GetBullets();
		while (nextBullet != nullptr)
		{
			m_GameField[nextBullet->GetPosX()][nextBullet->GetPosY()] = nextBullet->GetAvatar();
			nextBullet = (Bullet*)nextBullet->next;
		}
	}
	
	//Draw Enemies
	if (m_Enemies)
	{
		EnemyBase* nextEnemy = m_Enemies;
		while (nextEnemy != nullptr)
		{
			m_GameField[nextEnemy->GetPosX()][nextEnemy->GetPosY()] = nextEnemy->GetAvatar();
			nextEnemy = (EnemyBase*)nextEnemy->next;
		}
	}

	////Draw Enemy Bullets
	//if (m_EnemyBullets)
	//{
	//	Bullet* nextBullet = m_EnemyBullets;
	//	while (nextBullet != nullptr)
	//	{
	//		m_GameField[nextBullet->GetPosX()][nextBullet->GetPosY()] = nextBullet->GetAvatar();
	//		nextBullet = (Bullet*)nextBullet->next;
	//	}
	//}
}

void Game::RenderField()
{
	for (int j = 0; j < FIELDSIZE_Y; j++)
	{
		for (int i = 0; i < FIELDSIZE_X; i++)
		{
			std::cout << m_GameField[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Game::ClearDyingBullets()
{
	Bullet* nextBullet = m_PlayerShip->GetBullets();
	Bullet* DyingBullet = nullptr;
	while (nextBullet != nullptr)
	{
		if (nextBullet->bDestroy)
		{
			DyingBullet = nextBullet;
			if (nextBullet == m_PlayerShip->GetBullets() && nextBullet->next == nullptr)
			{
				m_PlayerShip->SetBulletsNull();
			}
			nextBullet = (Bullet*)nextBullet->next;
			DyingBullet->Destroy();
			delete(DyingBullet);
		}
		else
		{
			nextBullet = (Bullet*)nextBullet->next;
		}
	}
}

void Game::LoadLevel(int Level)
{
	switch (Level)
	{
	case 0:
		m_Enemies = new EnemyBase(1, 1, 'X');
		SpawnEnemy(5, 1, 'X');
		SpawnEnemy(10, 1, 'X');
		SpawnEnemy(15, 1, 'X');
		SpawnEnemy(20, 1, 'X');
		break;
	}
}

void Game::SpawnEnemy(int X, int Y, char Avatar)
{
	EnemyBase* NewEnemy = new EnemyBase(X, Y, Avatar);
	NewEnemy->Append(m_Enemies);
}

void Game::BeginPlay()
{
	//Get Handle On Cursor for printing over last field to eliminate flickering
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &info);

	m_PlayerShip = new Player;
	m_PlayerShip->BeginPlay();

	LoadLevel(0);

	InitializeField();
}

void Game::Tick()
{
	//Set curor to beginning and print over current field
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0,0 };
	SetConsoleCursorPosition(hConsole, pos);

	if (!m_PlayerShip) { return; }
	m_PlayerShip->Tick();

	m_PlayerBullets = m_PlayerShip->GetBullets();

	if (m_PlayerBullets)
	{
		Bullet* nextBullet = m_PlayerBullets;
		while (nextBullet != nullptr)
		{
			nextBullet->Tick();
			nextBullet = (Bullet*)nextBullet->next;
		}
	}

	if (m_Enemies)
	{
		EnemyBase* nextEnemy = m_Enemies;
		while (nextEnemy != nullptr)
		{
			nextEnemy->Tick();
			nextEnemy = (EnemyBase*)nextEnemy->next;
		}
		if (m_EnemyBullets)
		{
			Bullet* nextBullet = m_EnemyBullets;
			while (nextBullet != nullptr)
			{
				nextBullet->Tick();
				nextBullet = (Bullet*)nextBullet->next;
			}
		}
	}

	//Handle the printing of the game field
	ClearDyingBullets();
	UpdateField();
	RenderField();
}

bool Game::GetGameOver()
{
	return m_bGameOver;
}

void Game::SetGameOver(bool newGameOver)
{
	m_bGameOver = newGameOver;
}