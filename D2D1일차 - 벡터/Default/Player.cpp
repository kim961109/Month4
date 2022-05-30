#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };

	m_fSpeed = 3.f;
	m_fAngleLook = 0.f;//시작할때 바라보는 디그리각도.

	vPos1 = { -50.f, -50.f,0.f };
	vPos2 = { -50.f,50.f,0.f };
	vPos3 = { 50.f,50.f,0.f };
	vPos4 = { 50.f,-50.f,0.f };
}

void CPlayer::Update(void)
{
	Key_Input();

	vPos1 = { -50.f, -50.f,0.f };
	vPos2 = { -50.f,50.f,0.f };
	vPos3 = { 50.f,50.f,0.f };
	vPos4 = { 50.f,-50.f,0.f };

	m_tInfo.vDir = { 1.f, 0.f, 0.f }; //??????????????????????????????????????

	Change_Matrix();


#ifdef _DEBUG

	//system("cls");
	cout << "플레이어 DIR좌표 : " << m_tInfo.vDir.x << "\t" << m_tInfo.vDir.y << "\t" << m_tInfo.vDir.z << endl;
	cout << "플레이어 POS좌표 : " << m_tInfo.vPos.x << "\t" << m_tInfo.vPos.y << "\t" << m_tInfo.vPos.z << endl;

#endif // _DEBUG
}

void CPlayer::Render(HDC hDC)
{
	//MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	//LineTo(hDC, m_tInfo.vPos.x + cosf(m_fAngleLook) * 100.f, m_tInfo.vPos.y + 100 * sinf(m_fAngleLook));//포신

	//MoveToEx(hDC, m_tInfo.vPos.x + cosf(PI / 4 + m_fAngleLook) * 50.f, m_tInfo.vPos.y + 50 * sinf(PI / 4 + m_fAngleLook), nullptr);//몸체
	//LineTo(hDC, m_tInfo.vPos.x + cosf(3 * PI / 4 + m_fAngleLook) * 50.f, m_tInfo.vPos.y + 50 * sinf(3 * PI / 4 + m_fAngleLook));//몸체
	//LineTo(hDC, m_tInfo.vPos.x + cosf(5 * PI / 4 + m_fAngleLook) * 50.f, m_tInfo.vPos.y + 50 * sinf(5 * PI / 4 + m_fAngleLook));//몸체
	//LineTo(hDC, m_tInfo.vPos.x + cosf(7 * PI / 4 + m_fAngleLook) * 50.f, m_tInfo.vPos.y + 50 * sinf(7 * PI / 4 + m_fAngleLook));//몸체
	//LineTo(hDC, m_tInfo.vPos.x + cosf(PI / 4 + m_fAngleLook) * 50.f, m_tInfo.vPos.y + 50 * sinf(PI / 4 + m_fAngleLook));//몸체

	MoveToEx(hDC, vPos1.x, vPos1.y, nullptr);
	LineTo(hDC, vPos2.x, vPos2.y);
	LineTo(hDC, vPos3.x, vPos3.y);
	LineTo(hDC, vPos4.x, vPos4.y);
	LineTo(hDC, vPos1.x, vPos1.y);

	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + 100 * m_tInfo.vDir.x, m_tInfo.vPos.y + 100 * m_tInfo.vDir.y);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	// GetKeyState
	if (GetAsyncKeyState(VK_A))
	{
		m_fAngleLook -= 0.1f;
		//m_fAngleLook -= 3.f;
/*
		float m_x = m_tInfo.vDir.x * cosf(m_fAngleLook) - m_tInfo.vDir.y * sinf(m_fAngleLook);
		float m_y = m_tInfo.vDir.x * sinf(m_fAngleLook) + m_tInfo.vDir.y * cosf(m_fAngleLook);
		
		m_tInfo.vDir.x = m_x;+
		m_tInfo.vDir.y = m_y;
		m_tInfo.vDir.z = 0.f;*/
		/*if (m_fAngleLook < 0)
		{
			m_fAngleLook += 2 * PI;
		}*/
	}

	if (GetAsyncKeyState(VK_D))
	{
		m_fAngleLook += 0.1f;
		//m_fAngleLook += 3.f;

	/*	float m_x = m_tInfo.vDir.x * cosf(m_fAngleLook) - m_tInfo.vDir.y * sinf(m_fAngleLook);
		float m_y = m_tInfo.vDir.x * sinf(m_fAngleLook) + m_tInfo.vDir.y * cosf(m_fAngleLook);

		m_tInfo.vDir.x = m_x;
		m_tInfo.vDir.y = m_y;
		m_tInfo.vDir.z = 0.f;
*/
		/*if (m_fAngleLook > 2 * PI)
		{
			m_fAngleLook -= 2 * PI;
		}*/
	}

	if (GetAsyncKeyState(VK_W))
	{
		m_tInfo.vPos.x += m_fSpeed * m_tInfo.vDir.x;
		m_tInfo.vPos.y += m_fSpeed * m_tInfo.vDir.y;
	}
}

void CPlayer::Change_Matrix(void)
{
	//m_tInfo.vDir.x = m_tInfo.vDir.x * cosf(m_fAngleLook) - m_tInfo.vDir.y * sinf(m_fAngleLook);
	//m_tInfo.vDir.y = m_tInfo.vDir.x * sinf(m_fAngleLook) + m_tInfo.vDir.y * cosf(m_fAngleLook);

	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx에서 제공하는 행렬 함수는 매개 변수로 넣어주는 행렬을 먼저 항등 행렬로 초기화 한 후, 값 적용을 수행한다.

	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	// z축 회전 행렬 생성 함수
	//D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngleLook));//디그리를 라디안으로 바꿔줌.
	D3DXMatrixRotationZ(&matRotZ, m_fAngleLook);
	// 이동 행렬 생성 함수
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	// matScale * * matTrans  matRotZ * 
	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	// 위치 벡터와 행렬을 곱셈하여 최종적인 위치 벡터를 반환하는 함수
	D3DXVec3TransformCoord(&vPos1, &vPos1, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vPos2, &vPos2, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vPos3, &vPos3, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vPos4, &vPos4, &m_tInfo.matWorld);
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
}
