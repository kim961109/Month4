#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.vPos	= { 100.f, 100.f, 0.f };
	m_fSpeed		= 5.f;
	m_fAngle = 0.f;
}

void CMonster::Update(void)
{
	/*m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;*/

	//float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	//float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	//float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	//float		fRadian = acosf(fWidth / fDiagonal);	// acos값으로 나올 수 있는 각도의 범위는 0~180도 사이 값에 해당한다.

	//													/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//													fRadian = (2 * PI) - fRadian;*/

	//													//	// 라디안 값을 디그리로 치환
	//m_fAngle = (fRadian * 180.f) / PI;

	//if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//	m_fAngle *= -1.f;

	//m_tInfo.fX += m_fSpeed * cosf((m_fAngle)* PI / 180.f);
	//m_tInfo.fY -= m_fSpeed * sinf((m_fAngle)* PI / 180.f);

	m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;

	float fDot = m_tInfo.vDir.x * 1.f;// 여기서 내적.(1,0,0)과 내적.

	float		fRadian = acosf(fDot);// 두벡터의 차이와 x방향 단위벡터 사이에 끼인각.
	m_fAngle = (fRadian * 180.f) / PI;

	if (m_pPlayer->Get_Info().vPos.y > m_tInfo.vPos.y)
		m_fAngle *= -1.f;

	m_tInfo.vPos.x += m_fSpeed * cosf((m_fAngle)* PI / 180.f);
	m_tInfo.vPos.y -= m_fSpeed * sinf((m_fAngle)* PI / 180.f);


}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 50.f),
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CMonster::Release(void)
{
	
}

// 단위 벡터 : 크기가 1인 벡터
// 벡터의 정규화 : 단위 벡터를 만드는 과정

// 벡터의 내적과 외적 : 반드시 두 방향 벡터(단위 벡터)를 통해 연산

// 내적 : 스칼라 곱(결과로 상수가 발생), 기호가 A ● B, 내적의 결과 : x*x` + y*y`+ z*z`
// 외적 : 벡터 곱(결과로 벡터가 발생), 기호가 A X B, 외적의 결과 

/*
X		Y		Z

X`      Y`      Z`

(Y * Z` - Z * Y`, X * Z` - Z * X`, X * Y` - Y * X`);*/


// 1. 벡터의 내적을 이용하여 플레이어를 따라다니는 몬스터를 구현하라.