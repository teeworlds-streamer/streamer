/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_CLIENT_COMPONENTS_STREMAER_H
#define GAME_CLIENT_COMPONENTS_STREMAER_H

#include <game/client/component.h>

class CStreamer : public CComponent
{
	void RenderHp(const CNetObj_Character *pPrevChar, const CNetObj_Character *pPlayerChar, int ClientID, int Team);

	class CHpInfo
	{
	public:
		CHpInfo();

		int m_Health;
		int m_Armor;
	} m_CHpInfos[MAX_CLIENTS];

public:
	virtual void OnStateChange(int NewState, int OldState);
	virtual void OnRender();
	virtual void OnMessage(int MsgType, void *pRawMsg);
};
#endif