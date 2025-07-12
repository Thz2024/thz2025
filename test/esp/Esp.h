#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / IM_PI) )
#define DEG2RAD( x ) ( (float)(x) * (float)(IM_PI / 180.f) )


static inline ImVec2  operator*(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x * rhs, lhs.y * rhs); }
static inline ImVec2  operator/(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x / rhs, lhs.y / rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x + rhs, lhs.y + rhs); }
static inline ImVec2  operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }
static inline ImVec2  operator-(const ImVec2& lhs, const float rhs) { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec2  operator*(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x * rhs.x, lhs.y * rhs.y); }
static inline ImVec2  operator/(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x / rhs.x, lhs.y / rhs.y); }
static inline ImVec2& operator*=(ImVec2& lhs, const float rhs) { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const float rhs) { lhs.x /= rhs; lhs.y /= rhs; return lhs; }
static inline ImVec2& operator+=(ImVec2& lhs, const ImVec2& rhs) { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
static inline ImVec2& operator-=(ImVec2& lhs, const ImVec2& rhs) { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }
static inline ImVec2& operator*=(ImVec2& lhs, const ImVec2& rhs) { lhs.x *= rhs.x; lhs.y *= rhs.y; return lhs; }
static inline ImVec2& operator/=(ImVec2& lhs, const ImVec2& rhs) { lhs.x /= rhs.x; lhs.y /= rhs.y; return lhs; }
static inline ImVec4  operator+(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
static inline ImVec4  operator-(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
static inline ImVec4  operator*(const ImVec4& lhs, const ImVec4& rhs) { return ImVec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }


template <typename T>
inline T clamp(const T& n, const T& lower, const T& upper) {
  return std::max(lower, std::min(n, upper));
}

inline float lerp(float a, float b, float f) {
	return clamp<float>(a + f * (b - a),a > b ? b : a,a > b ? a : b);
}

#pragma once

#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

float Rainbow() {
	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;
	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	} else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	} else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	} else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	} else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	} else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}
	x+= 0.25f; 
	if (x >= 255.0f)
		x = 0.0f;
	y+= 0.25f;
	if (y > 1530.0f)
		y = 0.0f;
	return ARGB(255, (int)r, (int)g, (int)b);
}


ImColor GetHealthColor (float health, float maxHp = 100.0f)
{
    float r = std::min(519 * (maxHp - health) / maxHp, 255.0f);
    float g = std::min(510 * health / maxHp, 255.0f); 
    return ImVec4(r/ 255.0f, g / 255.0f, 0.f, 1.0f);
}

bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

Vector3 add(Vector3 v1, Vector3 v2) {
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    
    if (Pos.y < 0) {
        y = -offset;
    }
    
    if (Pos.x > screen.x) {
        x = (int) screen.x + offset;
    }
    
    if (Pos.y > screen.y) {
        y = (int) screen.y + offset;
    }
    
    if (Pos.x < 0) {
        x = -offset;
    }
    return ImVec2(x, y);
}

void DrawBox(float X, float Y, float W, float H, ImColor Color, float curve, float thickness)
{
	ImDrawList* draw_list = ImGui::GetForegroundDrawList();
	draw_list->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), Color);
	draw_list->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, curve, thickness);
}

void drawRectFilledWithPos(ImVec2 pos, ImVec2 size, ImColor color)
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), color, 0, 0);
}

void DrawText2(ImFont * _espFont, float fontSize, ImVec2 position, ImColor Color, const char *text, ImColor colorFilled)
{
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x-3,position.y-3), ImVec2(position.x + _espFont->CalcTextSizeA(fontSize, MAXFLOAT, 0.0f, text).x + 3, position.y + 12), colorFilled, 0, 0);
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    draw_list->AddText(NULL, fontSize, position, Color, text);
}

void hpasddsfhjdjhsbsd(float hp, float maxHp, float xh, float yh) //Draw health
{
    float rate = 1.0f * hp/ maxHp;
    float width = 50 ;
    float height = 4;
    float x = xh - width * 0.5;
    float y = yh - height - 0;
    
    ImColor color = ImColor(0,255,0);

    if (rate < 0.35) {
        color = ImColor(255,0,0);
    } else if (rate < 0.75) {
        color = ImColor(255,165,0);
    }

    drawRectFilledWithPos(ImVec2(x, y), ImVec2(width * rate, height), color);
}

void RenderLine(const ImVec2& from, const ImVec2& to, ImColor Color, float thickness)
{
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    draw_list->AddLine(from, to, Color, thickness);
}



bool ESPEnable, ESPLine, ESPBox, ESPHealth, ESPDistance, ESPName, ESPArrow, Crosshair;
float colorEsp[3] = {255,255,255};
static int Box = 0;
float AimFov = 0.0f;
bool aimStart, isAimFov, AimScope, AimFire, AimDam, LuonluomAim, line, FSWitch, AimVisible;
static bool AimKill = false;
static int style_idx = 0;
static int AimWhen = 1;
static int AimType = 0;
static bool autotroca = false;
static bool sID = false;
static int tS = 0;
bool enable_circleFov = false;
int circleSizeValue = 40;
int aim_target = 0;


bool (*Team) (void*player);
int (*maxhealth)(void *player);
void* (*get_camera)();
void* (*get_transform)(void*);
Vector3 (*worldToScreen)(void *cam, Vector3 pos);
Vector3 (*WorldToViewpoint)(void*, Vector3, int);
Vector3 (*get_position)(void*);
ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);


using namespace std;

class Vvector3 {
public:
    float x;
    float y;
    float z;
    Vvector3() : x(0), y(0), z(0) {}
    Vvector3(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
    Vvector3(const Vvector3 &v);
    ~Vvector3();
};
Vvector3::Vvector3(const Vvector3 &v) : x(v.x), y(v.y), z(v.z) {}
Vvector3::~Vvector3() {}


Vector3 getPosition(void *transform) {
    return get_position(get_transform(transform));
} 

//bool(*_ResetGuest) (void *instance);

Vector3 GetPlayerLocation(void* player) {
    Vector3 location;
    location = get_position(get_transform(player));
    return location;
}

void *(*get_transformFF)(void*inst);

static void *CurentMatch() {
    void *(*_CurentMatch) (void *instance) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1022A07B0")); 
    return _CurentMatch(NULL);
}

static Vector3 Transform_GetPosition(void *player) {
    Vector3 out = Vector3::zero();
    void (*_Transform_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(ENCRYPTOFFSET("0x105BB82D0"));
    _Transform_GetPosition(player, &out);
    return out;
}

static Vector3 Transform_INTERNAL_GetPosition(void *player) {
    Vector3 out = Vector3::zero();
    void (*_Transform_INTERNAL_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(ENCRYPTOFFSET("0x105BB82D0"));
    _Transform_INTERNAL_GetPosition(player, &out);
    return out;
}

static void Transform_INTERNAL_SetPosition(void *player, Vvector3 inn) {
    void (*_Transform_INTERNAL_SetPosition)(void *transform, Vvector3 in) = (void (*)(void *, Vvector3))getRealOffset(ENCRYPTOFFSET("0x105BB8374"));
    _Transform_INTERNAL_SetPosition(player, inn);
}



bool IsClientBot(void* _this) { return *(bool*)((uint64_t)_this + 0x278); }


static void *GetLocalPlayer(void* Match) {
    void *(*_GetLoalPlayer)(void *match) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1041A2FDC")); 
    return _GetLoalPlayer(Match);
}

static void *Current_Local_Player() {
    void *(*_Local_Player)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1022A0C80"));
    return _Local_Player(NULL);
}

static void *GetLocalPlayerOrObServer() 
{
    void *(*_GetLocalPlayerOrObServer)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1022A137C"));
    return _GetLocalPlayerOrObServer(NULL);
}

Vector3 GetHeadPosition(void* player) {
    void *HeadITF= *(void **)((uintptr_t) player + 0x420);
    void *HeadTF = get_transformFF(HeadITF);
    Vector3 Head = getPosition(HeadTF);
    return Head;
}

static void *Camera_main() {
    void *(*_Camera_main)(void *nuls) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105B7298C"));
    return _Camera_main(nullptr);
}

monoString* get_Nickname(void* player) {
    monoString* (*nickname)(void* instance) = (monoString * (*)(void*)) getRealOffset(ENCRYPTOFFSET("0x104EB45A0")); //   public string get_NickName() { }   VA *****1/18*****
    return nickname(player);  
}
std::string monoStringToStdString(monoString* mStr) {
    if (mStr == nullptr) return "";
    return std::string(mStr->toCString());
}

std::string getPlayerNickname(void* player) {
    if (player == nullptr) return "";
    monoString* mStr = get_Nickname(player);
    return monoStringToStdString(mStr);
}


Vector3 GetHipPosition(void* player) {
    void *HipITF= *(void **)((uintptr_t) player + 0x428);
    void *HipTF = get_transformFF(HipITF);
    Vector3 Hip = getPosition(HipTF);
    return Hip;
}

Vector3 GetToePosition(void* player) {
    void *ToeITF= *(void **)((uintptr_t) player + 0x460);
    void *ToeTF = get_transformFF(ToeITF);
    Vector3 Toe = getPosition(ToeTF);
    return Toe;
}

static bool get_isVisible(void *player) {
    bool (*_get_isVisible)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EBB6D0"));
    return _get_isVisible(player);
}

static void *Component_GetTransform(void *player) {
    void *(*_Component_GetTransform)(void *component) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x105B74A14"));  //   public Transform get_transform() { }
    return _Component_GetTransform(player);
}

static void SwapWeapon(void* player, int POFFNNMOOBM, bool GDKLMFLNNGM) {
    void (*_SwapWeapon)(void* player, int POFFNNMOOBM, bool GDKLMFLNNGM) = (void (*)(void *, int, bool))getRealOffset(ENCRYPTOFFSET("0x104FD8F30"));
     _SwapWeapon(player, POFFNNMOOBM, GDKLMFLNNGM);
}

typedef struct _RayCastHit {
    Vector3 m_Point;
    Vector3 m_Normal;
    int m_FaceID;
    float m_Distance;
    Vector2 m_UV;
    void * collider;
} RayCastHit;

static bool Physics_Raycast(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) {
    bool (*_Physics_Raycast)(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) = (bool(*)(Vector3, Vector3, unsigned int, void*))getRealOffset(ENCRYPTOFFSET("0x1048EA4DC"));//public static bool PLDCHDBCOBF(Vector3 OOFIJHADLNI, Vector3 CHGADBAMMOP, uint ONEDHFJBCMJ, ref MADMMIICBNN JEEIBOEGGPD) { }
    return _Physics_Raycast(camLocation, headLocation, LayerID, collider);
}

static void *Player_GetHeadCollider(void *player) {
    void *(*_Player_GetHeadCollider)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EB6F48"));//public static bool PLDCHDBCOBF(Vector3 OOFIJHADLNI, Vector3 CHGADBAMMOP, uint ONEDHFJBCMJ, ref MADMMIICBNN JEEIBOEGGPD) { }
    return _Player_GetHeadCollider(player);
}

bool IsVisible(void *enemy)  {
    if(enemy != NULL)  {
         void *hitObj = NULL;
         auto Camera = Transform_GetPosition(Component_GetTransform(Camera_main()));
         auto Target = Transform_GetPosition(Component_GetTransform(Player_GetHeadCollider(enemy)));
         return !Physics_Raycast(Camera, Target, 12, &hitObj);
    }
    return false;
}


static bool get_isLocalTeam(void *player) {
    bool (*_get_isLocalTeam)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EC76FC")); 
    return _get_isLocalTeam(player);
}

static bool get_IsDieing(void *player) {
    bool (*_get_die)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EADF4C")); 
    return _get_die(player);
}

static int GetHp(void* player) {
    int (*_GetHp)(void* players) = (int(*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EFFF0C")); 
    return _GetHp(player);
}

static bool IsPlayerDead(void* player) {
    if (GetHp(player) < 1) {
        return true;
    }
    return false;
}

static int get_MaxHP(void* enemy) {
    int (*_get_axHP)(void* player) = (int(*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EFFFB4")); 
    return _get_axHP(enemy);
}

bool get_isLiving(void* player) {
    if (GetHp(player) > 0) {
        return true;
    } else {
        return false;
    }
}

static void *IsLocal() {
    void *(*_Local_Player)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1022A0C80")); 
    return _Local_Player(NULL);
}

static void *IsLocalObServer() {
    void *(*_GetocalPlayerOrObServer)(void *players) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x1022A137C")); 
    return _GetocalPlayerOrObServer(NULL);
}

static void *get_MyFollowCamera(void *players) {
    void *(*_get_yFollowCamera) (void *player) = (void *(*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EB6B40")); 
    return _get_yFollowCamera(players);
}

static Vector3 GetAttackableCenterWS(void *player) {
    Vector3 (*_GtAttackableCenterWS)(void *players) = (Vector3 (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104F969E0")); 
    return _GtAttackableCenterWS(player);
}

Vector3 CameraMain(void* player){
    return getPosition(*(void**) ((uint64_t) player + 0x1C8));
}

static bool get_IsSighting(void *player) {
    bool (*_get_Isighting)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EAE5B4")); 
    return _get_Isighting(player);
}
static bool get_IsCrouching(void *player) {
    bool (*_get_IsCrouching)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EC9EF0")); 
    return _get_IsCrouching(player);
}
static bool get_IsFiring(void *player) {
    bool (*_get_IsFiring)(void *players) = (bool (*)(void *))getRealOffset(ENCRYPTOFFSET("0x104EAE518")); 
    return _get_IsFiring(player);
}

static Vector3 GetForward(void *player) {
    Vector3 (*_GetForward)(void *players) = (Vector3 (*)(void *))getRealOffset(ENCRYPTOFFSET("0x105BB8C50")); 
    return _GetForward(player);
}

static void set_aim(void *player, Quaternion look) {
    void (*_set_aim_nepmods)(void *players, Quaternion lock) = (void (*)(void *, Quaternion))getRealOffset(ENCRYPTOFFSET("0x104EB8554")); 
    _set_aim_nepmods(player, look);
}

bool FW(void *instance) {
    if (FSWitch) {
        return false;
	}
}


Quaternion GetRotationToLocation(Vector3 targetLocation, float y_bias, Vector3 myLoc){
    return Quaternion::LookRotation((targetLocation + Vector3(0, y_bias, 0)) - myLoc, Vector3(0, 1, 0));
}


ImVec2 world2screen_i(Vector3 pos) {
    auto cam = get_camera();
    if (!cam) return {0,0};

    Vector3 worldPoint = WorldToViewpoint(cam,pos, 2);
    Vector3 location;

    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;

    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;

    return {location.x, location.y};
}

ImVec2 world2screen_c(Vector3 pos, bool &checker) {
    auto cam = get_camera();
    if (!cam) return {0,0};
   
    Vector3 worldPoint = WorldToViewpoint(cam,pos, 2);
    Vector3 location;
 
    int ScreenWidth = ImGui::GetIO().DisplaySize.x;
    int ScreenHeight = ImGui::GetIO().DisplaySize.y;
 
    location.x = ScreenWidth * worldPoint.x;
    location.y = ScreenHeight - worldPoint.y * ScreenHeight;
    location.z = worldPoint.z;
 
    checker = location.z > 1;
 
    return {location.x, location.y};
}




void DrawEsp() {
if (Crosshair) {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    float size = ImGui::GetMainViewport()->Size.x * 0.03f; // Kích thước crosshair là 5% của chiều rộng viewport
    float halfSize = size * 0.5f;
    ImVec2 horizontalStart(center.x - halfSize, center.y);
    ImVec2 horizontalEnd(center.x + halfSize, center.y);
    ImVec2 verticalStart(center.x, center.y - halfSize);
    ImVec2 verticalEnd(center.x, center.y + halfSize);
    ImGui::GetBackgroundDrawList()->AddLine(horizontalStart, horizontalEnd, IM_COL32(255, 255, 255, 255));
    ImGui::GetBackgroundDrawList()->AddLine(verticalStart, verticalEnd, IM_COL32(255, 255, 255, 255));
}
if (ESPEnable) {
    void *current_Match = CurentMatch();
    void *local_player = GetLocalPlayer(current_Match);
    if (local_player != nullptr && current_Match != nullptr) {
        Dictionary<uint8_t *, void **> *players = *(Dictionary<uint8_t*, void **> **)((long)current_Match + 0x88);
        void *camera = Camera_main();
        if (players != nullptr && camera != nullptr) {
            for (int u = 1; u < players->getNumValues(); u++) {
                void *ClosestEnemy = players->getValues()[u];
                if (ClosestEnemy != local_player && ClosestEnemy != nullptr && get_isVisible(ClosestEnemy) && !get_isLocalTeam(ClosestEnemy) && get_MaxHP(ClosestEnemy)) {
                    ImVec2 enemyPos = world2screen_i(GetPlayerLocation(ClosestEnemy));
                    Vector3 pos = getPosition(ClosestEnemy);
                    Vector3 viewpos = getPosition(local_player);
                    float distance = Vector3::Distance(viewpos, pos);
                    int health = GetHp(ClosestEnemy); // Lấy máu hiện tại của player
                    int maxhp = get_MaxHP(ClosestEnemy);
                    if (distance > 200.0f) continue;

                    bool w2sCheck = false;

                    ImVec2 top_pos = world2screen_i(pos + Vector3(0, 1.5f, 0));
                    ImVec2 bot_pos = world2screen_i(pos + Vector3(0, -0.15f, 0)); // Chân của kẻ địch

                    // Kiểm tra xem kẻ địch có hiển thị trên màn hình không
                    world2screen_c(pos + Vector3(0, 0.75f, 0), w2sCheck);  
                    if (!w2sCheck) continue;  // Nếu kẻ địch không hiển thị, bỏ qua

                    // Tính toán kích thước hộp (bounding box)
                    float boxHeight = fabs(top_pos.y - bot_pos.y);
                    float boxWidth = boxHeight * 0.75f;

                    if (boxHeight <= 0 || boxWidth <= 0) continue;

                    // Vẽ hình chữ nhật bao quanh kẻ địch
                    ImRect rect(ImVec2(bot_pos.x - boxWidth / 2, top_pos.y), ImVec2(bot_pos.x + boxWidth / 2, bot_pos.y));

                    if (ESPLine) {
                        RenderLine(ImVec2(kWidth / 2, 0), ImVec2(top_pos.x, top_pos.y - 20), ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.9);

                        if (ESPBox) {
                            float height = abs(enemyPos.y - top_pos.y);
                            float width = height * 0.65f;
                            DrawBox(top_pos.x - (width * 0.5), top_pos.y, width, height, ImColor(colorEsp[0], colorEsp[1], colorEsp[2]), 0.9, 0.9);
                        }

                        if (ESPHealth) {
                            hpasddsfhjdjhsbsd(health, maxhp, top_pos.x, top_pos.y);
                        }

if (ESPName) { 
                            std::string nickname = IsClientBot(ClosestEnemy) ? "BOT" : getPlayerNickname(ClosestEnemy); // Lấy tên của player
                            ImVec2 nicknameWidth = _espFont->CalcTextSizeA(12.0f, MAXFLOAT, 0.0f, nickname.c_str());

                            DrawText2(_espFont, 12, ImVec2(top_pos.x - (nicknameWidth.x / 2.0f), top_pos.y - 16), ImColor(255, 255, 51), nickname.c_str(), ImColor(0, 0, 0, 190));
                        }
                    }
                }
            }
        }
    }
}
}

