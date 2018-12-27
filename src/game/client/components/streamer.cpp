/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */

#include <engine/shared/config.h>
#include <engine/graphics.h>
#include <engine/client.h>
#include <generated/protocol.h>
#include <game/client/render.h>
#include "streamer.h"

CStreamer::CHpInfo::CHpInfo()
{
	m_Health = -1;
	m_Armor = -1;
}

void CStreamer::RenderHp(const CNetObj_Character *pPrevChar, const CNetObj_Character *pPlayerChar, int ClientID, int Team)
{
	int Health = m_CHpInfos[ClientID].m_Health;
	int Armor = m_CHpInfos[ClientID].m_Armor;

	if(Health < 0 && Armor < 0)
		return;

	float IntraTick = Client()->IntraGameTick();

	vec2 Position = mix(vec2(pPrevChar->m_X, pPrevChar->m_Y), vec2(pPlayerChar->m_X, pPlayerChar->m_Y), IntraTick);

	float YOffset = g_Config.m_ClNameplates ? 91.0f : 53.0f;
	float TotalWidth = 150.0f;
	float Height = 10.0f;
	float HealthWidth = (TotalWidth/10.0f)*(float)Health;
	float ArmorWidth = (TotalWidth/10.0f)*(float)Armor;

	// health background
	CUIRect HealthBgRect = {Position.x-TotalWidth/2.0f-1.0f, Position.y-YOffset-1.0f,  TotalWidth+2.0f, Height+2.0f};
	RenderTools()->DrawRoundRect(&HealthBgRect, vec4(0.0f, 0.0f, 0.0f, 0.5f), 6.0f);

	// health
	if(Health > 0)
	{
		CUIRect HealthRect = {Position.x-TotalWidth/2.0f, Position.y-YOffset, HealthWidth, Height};
		RenderTools()->DrawRoundRect(&HealthRect, vec4(Team == TEAM_BLUE? 0.0f : 0.8f, 0.0f, Team == TEAM_BLUE? 0.8f : 0.0f, 0.7f), 5.0f);
	}

	YOffset -= 15.0f;

	// armor background
	CUIRect ArmorBgRect = {Position.x-TotalWidth/2.0f-1.0f, Position.y-YOffset-1.0f, TotalWidth+2.0f, Height+2.0f};
	RenderTools()->DrawRoundRect(&ArmorBgRect, vec4(0.0f, 0.0f, 0.0f, 0.5f), 6.0f);

	// armor
	if(Armor > 0)
	{
		CUIRect ArmorRect = {Position.x-TotalWidth/2.0f, Position.y-YOffset, ArmorWidth, Height};
		RenderTools()->DrawRoundRect(&ArmorRect, vec4(1.0f, 1.0f, 0.0f, 0.7f), 5.0f);
	}

	// Graphics()->QuadsEnd();
}

void CStreamer::OnStateChange(int NewState, int OldState)
{
	// send streamer message for the server to know that we can stream
	if(NewState == IClient::STATE_ONLINE)
	{
		CNetMsg_Cl_Streamer Msg;
		Client()->SendPackMsg(&Msg, MSGFLAG_VITAL);
	}
}

void CStreamer::OnRender()
{
	if ((Client()->State() != IClient::STATE_ONLINE && Client()->State() != IClient::STATE_DEMOPLAYBACK) || !m_pClient->m_Snap.m_SpecInfo.m_Active || !g_Config.m_ClHPBar)
		return;

	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		// only render active characters
		if(!m_pClient->m_Snap.m_aCharacters[i].m_Active)
			continue;

		RenderHp(&m_pClient->m_Snap.m_aCharacters[i].m_Prev, &m_pClient->m_Snap.m_aCharacters[i].m_Cur, i, m_pClient->m_aClients[i].m_Team);
	}
}

void CStreamer::OnMessage(int MsgType, void *pRawMsg)
{
	/*if(Client()->State() == IClient::STATE_DEMOPLAYBACK)		//Show hp bars in demo playback
		return;*/

	if(MsgType == NETMSGTYPE_SV_HP)
	{
		CNetMsg_Sv_Hp *pMsg = (CNetMsg_Sv_Hp *)pRawMsg;

		int ClientID = pMsg->m_ClientID;
		if(ClientID >= 0 && ClientID < MAX_CLIENTS)
		{
			m_CHpInfos[ClientID].m_Health = pMsg->m_Health;
			m_CHpInfos[ClientID].m_Armor = pMsg->m_Armor;
		}
	}
}