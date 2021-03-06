#include "../../../../../common/stdafx.h"
#include "player_entity.h"
#include "../../../../../common/sys.h"
#include "../Components/life_comp.h"
#include "../Components/input_comp.h"
#include "../Components/render_comp.h"
#include "../Components/collision_comp.h"
//#include "../Components/linear_vel_comp.h"
#include "../Components/horizontal_movement_comp.h"
#include <assert.h>
#include "../Components/shooting_component.h"

cEPlayer::cEPlayer(const char* cSpritePath, float fRadius)
    : m_fMaxPlayerVel(8.0 * 60.0f)
{
	//Set Entity Type
	SetEntityType(EntityType::PLAYER);

	// Insert movement component.
	cHorizontalMovementComp* pVelComp = new cHorizontalMovementComp();
	assert(pVelComp != nullptr);
	pVelComp->SetPos(vmake(SCR_WIDTH / 2, 50));//CORE_FRand(0.0f, SCR_WIDTH), CORE_FRand(0.0f, SCR_HEIGHT)));
	pVelComp->SetInitialVel(vmake(m_fMaxPlayerVel, 0));
	AddComponent<cHorizontalMovementComp&>(*pVelComp);

	// Insert collision component.
	cCollisionComp* pCollComp = new cCollisionComp(fRadius * 3.0f);
	assert(pCollComp != nullptr);
	AddComponent<cCollisionComp&>(*pCollComp);

	// Insert render component.
	cRenderComp* pRenderComp = new cRenderComp(cSpritePath, vmake(fRadius * 15.0f, fRadius * 15.0f));
	assert(pRenderComp != nullptr);
	AddComponent<cRenderComp&>(*pRenderComp);

	cInputComp* pInputComp = new cInputComp();
	assert(pInputComp != nullptr);
	AddComponent<cInputComp&>(*pInputComp);

	cLifeComp* pLifeComp = new cLifeComp();
	assert(pLifeComp != nullptr);
	AddComponent<cLifeComp&>(*pLifeComp);

	cShootingComp* pShootComp = new cShootingComp();
	assert(pShootComp != nullptr);
	AddComponent<cShootingComp&>(*pShootComp);
}
