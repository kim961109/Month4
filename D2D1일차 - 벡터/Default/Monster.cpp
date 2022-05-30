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

	//float		fRadian = acosf(fWidth / fDiagonal);	// acos������ ���� �� �ִ� ������ ������ 0~180�� ���� ���� �ش��Ѵ�.

	//													/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//													fRadian = (2 * PI) - fRadian;*/

	//													//	// ���� ���� ��׸��� ġȯ
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

	float fDot = m_tInfo.vDir.x * 1.f;// ���⼭ ����.(1,0,0)�� ����.

	float		fRadian = acosf(fDot);// �κ����� ���̿� x���� �������� ���̿� ���ΰ�.
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

// ���� ���� : ũ�Ⱑ 1�� ����
// ������ ����ȭ : ���� ���͸� ����� ����

// ������ ������ ���� : �ݵ�� �� ���� ����(���� ����)�� ���� ����

// ���� : ��Į�� ��(����� ����� �߻�), ��ȣ�� A �� B, ������ ��� : x*x` + y*y`+ z*z`
// ���� : ���� ��(����� ���Ͱ� �߻�), ��ȣ�� A X B, ������ ��� 

/*
X		Y		Z

X`      Y`      Z`

(Y * Z` - Z * Y`, X * Z` - Z * X`, X * Y` - Y * X`);*/


// 1. ������ ������ �̿��Ͽ� �÷��̾ ����ٴϴ� ���͸� �����϶�.