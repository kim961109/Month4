#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);
	void        Change_Matrix(void);
	
private:
	float m_fAngleLook;

	D3DXVECTOR3		vPos1;
	D3DXVECTOR3		vPos2;
	D3DXVECTOR3		vPos3;
	D3DXVECTOR3		vPos4;

/*

	D3DXVECTOR3		m_vPlayerPos;	// ¿ßƒ° ∫§≈Õ
	
	D3DXVECTOR3		m_vPlayerDir;	// πÊ«‚ ∫§≈Õ
	D3DXVECTOR3		m_vPlayerLook;	// πÊ«‚ ∫§≈Õ

	D3DXVECTOR3		m_vPlayerNormal;	// π˝º± ∫§≈Õ*/
};

	