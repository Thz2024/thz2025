void* PlayerWeaponOnHand(void* Player){
    void*(*WeaponOnHand)(void*) = (void*(*)(void*))getRealOffset(ENCRYPTOFFSET("0x104EB3E60"));
    return WeaponOnHand(Player);
}

Vector3 CameraPosition(void*Player){ 
	Vector3 Position = Vector3::zero();
    void(*PositionInjected)(void*,Vector3*) = (void(*)(void*,Vector3*))getRealOffset(ENCRYPTOFFSET("0x105BB82D0"));
    PositionInjected(*(void**)((uintptr_t) Player + 0x1C8),&Position);
    return Position;
}

void* PlayerTakeDamage(void* Player,void* DamageInfo,void* DamagerWeaponDynamicInfo,void* CheckParams,uint DamagerVehicleID){
    void*(*TakeDamage)(void*,void*,void*,void*,uint) = (void*(*)(void*,void*,void*,void*,uint))getRealOffset(ENCRYPTOFFSET("0x104EFE1F0"));
    return TakeDamage(Player,DamageInfo,DamagerWeaponDynamicInfo,CheckParams,DamagerVehicleID);
}

void PlayerNetworkStartWholeBodyFiring(void* Player,void* WeaponOnHand){
    void(*StartWholeBodyFiring)(void*,void*) = (void(*)(void*,void*))getRealOffset(ENCRYPTOFFSET("0x104FD84D4"));
    return StartWholeBodyFiring(Player,WeaponOnHand);
}

void PlayerNetworkStopFire(void* Player,void* WeaponOnHand){
    void(*StopFire)(void*,void*) = (void(*)(void*,void*))getRealOffset(ENCRYPTOFFSET("0x104FD8B4C"));
    return StopFire(Player,WeaponOnHand);
}

void* GameFacadeCurrentLocalPlayer(){
    void*(*CurrentLocalPlayer) (void*) = (void*(*)(void*))getRealOffset(ENCRYPTOFFSET("0x1022A0C80"));
    return CurrentLocalPlayer(NULL);
}

Vector3 PlayerHeadPosition(void* Player){
    void*(*HeadPosition)(void*) = (void*(*)(void*))getRealOffset(ENCRYPTOFFSET("0x104F13D30"));
	Vector3 Position = Vector3::zero();
    void(*PositionInjected)(void*,Vector3*) = (void(*)(void*,Vector3*))getRealOffset(ENCRYPTOFFSET("0x105BB82D0"));
    PositionInjected(HeadPosition(Player),&Position);
    return Position;
}


// AimKill
namespace Save {
	void* DamageInfo;
	clock_t AimDelay;
int AimFPS = (1000000 / 15);
		
}

void (*DamageInfo)(void*);
void DamageInfoHook(void* Player){
	Save::DamageInfo=Player;
}

void PlayerTakeDamage(void* ClosestEnemy){
    void* CurrentMatch = CurentMatch();
    void* LocalPlayer = GameFacadeCurrentLocalPlayer();
    if (!Camera_main() || !CurrentMatch || CurrentMatch == nullptr || LocalPlayer == nullptr || get_IsDieing(LocalPlayer) || !get_isLiving(LocalPlayer)) return;
	if (Save::DamageInfo != NULL && clock() > Save::AimDelay){
		Save::AimDelay = clock() + Save::AimFPS;
		
		void* WeaponOnHand = PlayerWeaponOnHand(LocalPlayer);
        if (WeaponOnHand != NULL) {
		*(void**)((uintptr_t) Save::DamageInfo + 0x28) = *(void**)((uintptr_t) LocalPlayer + 0x1E8);
		*(void**)((uintptr_t) Save::DamageInfo + 0x40) = WeaponOnHand;
		*(Vector3*)((uintptr_t) Save::DamageInfo + 0x4C) = CameraPosition(LocalPlayer);
		*(Vector3*)((uintptr_t) Save::DamageInfo + 0x58) = PlayerHeadPosition(ClosestEnemy);
		PlayerNetworkStartWholeBodyFiring(LocalPlayer,WeaponOnHand);
		PlayerTakeDamage(ClosestEnemy,Save::DamageInfo,NULL,*(void**)((uintptr_t) ClosestEnemy + 0xCD0),0);
		PlayerNetworkStopFire(LocalPlayer,WeaponOnHand);
    }
	}
}