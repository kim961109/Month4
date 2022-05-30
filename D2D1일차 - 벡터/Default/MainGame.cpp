#include "stdafx.h"
#include "MainGame.h"
#include "Monster.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr), m_pMonster(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	/*if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}*/

	//dynamic_cast<CMonster*>(m_pMonster)->Set_Player(m_pPlayer);


#ifdef _DEBUG

	if (::AllocConsole() == TRUE)
	{
		FILE* nfp[3];
		freopen_s(nfp + 0, "CONOUT$", "rb", stdin);
		freopen_s(nfp + 1, "CONOUT$", "wb", stdout);
		freopen_s(nfp + 2, "CONOUT$", "wb", stderr);
		std::ios::sync_with_stdio();
	}

#endif // _DEBUG
}

void CMainGame::Update(void)
{
	m_pPlayer->Update();
	//m_pMonster->Update();
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_hDC);
	//m_pMonster->Render(m_hDC);
}

void CMainGame::Release(void)
{
#ifdef _DEBUG

	FreeConsole();

#endif // _DEBUG

	//Safe_Delete<CObj*>(m_pMonster);
	Safe_Delete<CObj*>(m_pPlayer);

	ReleaseDC(g_hWnd, m_hDC);	
}

// 1. w,a,s,d Ű�� ���� 4���� �Ѿ˽��
// 2. ���� ���ΰ� 100�� ���� ��Ʈ�� ����� �簢�� ������ ����� �̻����� �����϶�