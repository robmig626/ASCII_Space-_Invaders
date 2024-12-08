#include "Game.h"

void Game::InitializeField()
{
	for (int j = 0; j < FIELDSIZE_Y; j++)
	{
		for (int i = 0; i < FIELDSIZE_X; i++)
		{
			GameField[i][j] = ' ';
		}
	}
}

void Game::UpdateField()
{
	InitializeField();

	//Draw Player
	GameField[PlayerShip->GetPosX()][PlayerShip->GetPosY()] = PlayerShip->GetAvatar();

	//Draw Bullets
	if (PlayerShip->GetBullets())
	{
		Bullet* nextBullet = PlayerShip->GetBullets();
		while (nextBullet != nullptr)
		{
			GameField[nextBullet->GetPosX()][nextBullet->GetPosY()] = nextBullet->GetAvatar();
			nextBullet = (Bullet*)nextBullet->next;
		}
	}
}

void Game::RenderField()
{
	for (int j = 0; j < FIELDSIZE_Y; j++)
	{
		for (int i = 0; i < FIELDSIZE_X; i++)
		{
			std::cout << GameField[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Game::ClearDyingBullets()
{
	Bullet* nextBullet = PlayerShip->GetBullets();
	Bullet* DyingBullet = nullptr;
	while (nextBullet != nullptr)
	{
		if (nextBullet->bDestroy)
		{
			DyingBullet = nextBullet;
			if (nextBullet == PlayerShip->GetBullets() && nextBullet->next == nullptr)
			{
				PlayerShip->SetBulletsNull();
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

void Game::BeginPlay()
{
	//Get Handle On Cursor for printing over last field to eliminate flickering
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &info);

	PlayerShip = new Player;
	PlayerShip->BeginPlay();

	InitializeField();
}

void Game::Tick()
{
	//Set curor to beginning and print over current field
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0,0 };
	SetConsoleCursorPosition(hConsole, pos);

	if (!PlayerShip) { return; }
	PlayerShip->Tick();

	if (PlayerShip->GetBullets())
	{
		Bullet* nextBullet = PlayerShip->GetBullets();
		while (nextBullet != nullptr)
		{
			nextBullet->Tick();
			nextBullet = (Bullet*)nextBullet->next;
		}
	}

	//Handle the printing of the game field
	ClearDyingBullets();
	UpdateField();
	RenderField();
}

bool Game::GetGameOver()
{
	return bGameOver;
}

void Game::SetGameOver(bool newGameOver)
{
	bGameOver = newGameOver;
}