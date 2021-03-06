/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'GameLogic'
*/

#include <string>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <functional>

struct IActor;
struct IPlayer;
struct Vector3;
struct Rotation;
struct IItem;
struct IItemVtbl;
struct IUE4ActorVtbl;
struct ILocalPlayer;
struct IInventory;
struct IInventoryVtbl;
struct IQuest;
struct IQuestState;
struct IQuestStateVtbl;
struct IQuestVtbl;
struct IFastTravel;
struct IFastTravelVtbl;
struct IAchievement;
struct IAchievementVtbl;
struct IPlayerVtbl;
struct ItemAndCount;
struct PlayerQuestState;
struct IActorVtbl;
struct TimerSet;
struct AIZoneListenerVtbl;
struct AIZoneListener;
struct AIZone;
struct Actor;
template <typename T> struct ActorRef;
struct Spawner;
struct NPCStateTransition;
struct NPCState;
struct NPC;
struct Socket;
struct SocketVtbl;
struct WriteStream;
struct Player;
struct WorldVtbl;


/* 681 */
struct  World
{
  WorldVtbl *vfptr;
  std::set<ActorRef<IPlayer>,std::less<ActorRef<IPlayer> >,std::allocator<ActorRef<IPlayer> > > m_players;
  std::set<ActorRef<IActor>,std::less<ActorRef<IActor> >,std::allocator<ActorRef<IActor> > > m_actors;
  std::map<unsigned int,ActorRef<IActor>,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,ActorRef<IActor> > > > m_actorsById;
  ILocalPlayer *m_localPlayer;
  unsigned int m_nextId;
  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,AIZone *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,AIZone *> > > m_aiZones;
};

/* 710 */
struct WorldVtbl
{
  void *(__thiscall *__vecDelDtor)(World *self, unsigned int);
  char gap4[32];
  void (__thiscall *Activate)(World *self, Player *, IItem *);
  void (__thiscall *Reload)(World *self, Player *);
  void (__thiscall *Jump)(World *self, bool);
  void (__thiscall *Sprint)(World *self, bool);
  void (__thiscall *FireRequest)(World *self, bool);
  void (__thiscall *TransitionToNPCState)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *BuyItem)(World *self, Player *, Actor *, IItem *, unsigned int);
  void (__thiscall *SellItem)(World *self, Player *, Actor *, IItem *, unsigned int);
  void (__thiscall *Respawn)(World *self, Player *);
  void (__thiscall *Teleport)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *Chat)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *FastTravel)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SetPvPDesired)(World *self, Player *, bool);
  void (__thiscall *SubmitDLCKey)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SetCircuitInputs)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, unsigned int);
  void (__thiscall *SendAddItemEvent)(World *self, Player *, IItem *, unsigned int);
  void (__thiscall *SendRemoveItemEvent)(World *self, Player *, IItem *, unsigned int);
  void (__thiscall *SendLoadedAmmoEvent)(World *self, Player *, IItem *, unsigned int);
  void (__thiscall *SendPickedUpEvent)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *EquipItem)(World *self, Player *, char, IItem *);
  void (__thiscall *SetCurrentSlot)(World *self, Player *, char);
  void (__thiscall *SendEquipItemEvent)(World *self, Player *, char, IItem *);
  void (__thiscall *SendCurrentSlotEvent)(World *self, Player *, char);
  void (__thiscall *SetCurrentQuest)(World *self, Player *, IQuest *);
  void (__thiscall *SendSetCurrentQuestEvent)(World *self, Player *, IQuest *);
  void (__thiscall *SendStartQuestEvent)(World *self, Player *, IQuest *);
  void (__thiscall *SendAdvanceQuestToStateEvent)(World *self, Player *, IQuest *, IQuestState *);
  void (__thiscall *SendCompleteQuestEvent)(World *self, Player *, IQuest *);
  void (__thiscall *SendHealthUpdateEvent)(World *self, Actor *, int);
  void (__thiscall *SendManaUpdateEvent)(World *self, Player *, int);
  void (__thiscall *SendCountdownUpdateEvent)(World *self, Player *, int);
  void (__thiscall *SendPvPCountdownUpdateEvent)(World *self, Player *, bool, int);
  void (__thiscall *SendPvPEnableEvent)(World *self, Player *, bool);
  void (__thiscall *SendStateEvent)(World *self, Actor *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, bool);
  void (__thiscall *SendTriggerEvent)(World *self, Actor *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, Actor *, bool);
  void (__thiscall *SendFireBulletsEvent)(World *self, Actor *, IItem *, Vector3 *, unsigned int, float);
  void (__thiscall *SendDisplayEvent)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SendNPCConversationStateEvent)(World *self, Player *, Actor *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SendNPCConversationEndEvent)(World *self, Player *);
  void (__thiscall *SendNPCShopEvent)(World *self, Player *, Actor *);
  void (__thiscall *SendRespawnEvent)(World *self, Player *, Vector3 *, Rotation *);
  void (__thiscall *SendTeleportEvent)(World *self, Actor *, Vector3 *, Rotation *);
  void (__thiscall *SendRelativeTeleportEvent)(World *self, Actor *, Vector3 *);
  void (__thiscall *SendReloadEvent)(World *self, Player *, IItem *, IItem *, unsigned int);
  void (__thiscall *SendPlayerJoinedEvent)(World *self, Player *);
  void (__thiscall *SendPlayerLeftEvent)(World *self, Player *);
  void (__thiscall *SendPlayerItemEvent)(World *self, Player *);
  void (__thiscall *SendActorSpawnEvent)(World *self, Actor *);
  void (__thiscall *SendActorDestroyEvent)(World *self, Actor *);
  void (__thiscall *SendExistingPlayerEvent)(World *self, Player *, Player *);
  void (__thiscall *SendExistingActorEvent)(World *self, Player *, Actor *);
  void (__thiscall *SendChatEvent)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SendKillEvent)(World *self, Player *, Actor *, IItem *);
  void (__thiscall *SendCircuitOutputEvent)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *, unsigned int, std::vector<bool,std::allocator<bool> > *);
  void (__thiscall *SendActorPositionEvents)(World *self, Player *);
  void (__thiscall *SendRegionChangeEvent)(World *self, Player *, std::basic_string<char,std::char_traits<char>,std::allocator<char> > *);
  void (__thiscall *SendLastHitByItemEvent)(World *self, Player *, IItem *);
};

/* 233 */
template<typename T>
struct  ActorRef
{
  T *m_object;
};


/* 108 */
struct  IUE4Actor
{
  IUE4ActorVtbl *vfptr;
};

/* 114 */
struct  ILocalPlayer : IUE4Actor
{
};


/* 106 */
struct  IActor
{
  IActorVtbl *vfptr;
};



/* 109 */
struct Vector3
{
  float x;
  float y;
  float z;
};

/* 110 */
struct Rotation
{
  float pitch;
  float yaw;
  float roll;
};

/* 166 */
struct  Actor : IActor
{
  unsigned int m_refs;
  unsigned int m_id;
  IUE4Actor *m_target;
  TimerSet *m_timers;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_blueprintName;
  ActorRef<IActor> m_owner;
  int m_health;
  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,bool,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,bool> > > m_states;
  float m_forwardMovementFraction;
  float m_strafeMovementFraction;
  Vector3 m_remotePosition;
  Vector3 m_remoteVelocity;
  Rotation m_remoteRotation;
  float m_remoteLocationBlendFactor;
  Spawner *m_spawner;
};

/* 107 */
struct  IPlayer
{
  IPlayerVtbl *vfptr;
};



/* 709 */
struct  Player : Actor, IPlayer
{
  unsigned int m_characterId;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_playerName;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_teamName;
  char m_avatarIndex;
  unsigned int m_colors[4];
  std::map<IItem *,ItemAndCount,std::less<IItem *>,std::allocator<std::pair<IItem * const,ItemAndCount> > > m_inventory;
  std::set<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > m_pickups;
  std::map<IItem *,float,std::less<IItem *>,std::allocator<std::pair<IItem * const,float> > > m_cooldowns;
  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned int> > > m_circuitInputs;
  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<bool,std::allocator<bool> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,std::vector<bool,std::allocator<bool> > > > > m_circuitOutputs;
  bool m_admin;
  bool m_pvpEnabled;
  bool m_pvpDesired;
  float m_pvpChangeTimer;
  int m_pvpChangeReportedTimer;
  bool m_changingServerRegion;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_currentRegion;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_changeRegionDestination;
  std::set<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > m_aiZones;
  int m_mana;
  float m_manaRegenTimer;
  float m_healthRegenCooldown;
  float m_healthRegenTimer;
  int m_countdown;
  Vector3 m_remoteLookPosition;
  Rotation m_remoteLookRotation;
  IItem *m_equipped[10];
  unsigned int m_currentSlot;
  std::map<IQuest *,PlayerQuestState,std::less<IQuest *>,std::allocator<std::pair<IQuest * const,PlayerQuestState> > > m_questStates;
  IQuest *m_currentQuest;
  float m_walkingSpeed;
  float m_jumpSpeed;
  float m_jumpHoldTime;
  ActorRef<NPC> m_currentNPC;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_currentNPCState;
  ILocalPlayer *m_localPlayer;
  WriteStream *m_eventsToSend;
  bool m_itemsUpdated;
  float m_itemSyncTimer;
  unsigned int m_chatMessageCounter;
  float m_chatFloodDecayTimer;
  IItem *m_lastHitByItem;
  float m_lastHitItemTimeLeft;
  float m_circuitStateCooldownTimer;
};

/* 111 */
struct  IItem
{
  IItemVtbl *vfptr;
};

/* 117 */
struct  IQuest
{
  IQuestVtbl *vfptr;
};

/* 118 */
struct  IQuestState
{
  IQuestStateVtbl *vfptr;
};


/* 1 */
enum DamageType
{
  PhysicalDamage = 0x0,
  FireDamage = 0x1,
  ColdDamage = 0x2,
  ShockDamage = 0x3,
};

/* 113 */
struct IUE4ActorVtbl
{
  void *(__thiscall *GetUE4Actor)(IUE4Actor *self);
  char gap4[8];
  Rotation *(__thiscall *GetRotation)(IUE4Actor *self, Rotation *result);
  Vector3 *(__thiscall *GetProjectilePosition)(IUE4Actor *self, Vector3 *result);
  Vector3 *(__thiscall *GetCharacterVelocity)(IUE4Actor *self, Vector3 *result);
  void (__thiscall *SetPosition)(IUE4Actor *self, Vector3 *);
  void (__thiscall *SetRotation)(IUE4Actor *self, Rotation *);
  void (__thiscall *SetCharacterVelocity)(IUE4Actor *self, Vector3 *);
  void (__thiscall *SetForwardAndStrafeMovement)(IUE4Actor *self, float, float);
  void (__thiscall *InterpolatePositionAndRotation)(IUE4Actor *self, Vector3 *, Rotation *, float, float);
  bool (__thiscall *MoveToLocation)(IUE4Actor *self, Vector3 *);
  bool (__thiscall *MoveToRandomLocationInRadius)(IUE4Actor *self, float);
  bool (__thiscall *MoveToActor)(IUE4Actor *self, IActor *);
  void (__thiscall *OnUpdateState)(IUE4Actor *self, const char *, bool);
  void (__thiscall *OnTriggerEvent)(IUE4Actor *self, const char *, IActor *);
  void (__thiscall *OnUpdatePvPEnabled)(IUE4Actor *self, bool);
  IActor *(__thiscall *LineTraceTo)(IUE4Actor *self, Vector3 *);
  void (__thiscall *FireBullets)(IUE4Actor *self, IItem *, int, DamageType, Vector3 *, unsigned int, float);
  void (__thiscall *LocalRespawn)(IUE4Actor *self, Vector3 *, Rotation *);
  bool (__thiscall *IsOnGround)(IUE4Actor *self);
  void (__thiscall *OnReload)(IUE4Actor *self, unsigned int);
};

/* 165 */
struct  AIZone
{
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_name;
  unsigned int m_playerCount;
  std::set<AIZoneListener *,std::less<AIZoneListener *>,std::allocator<AIZoneListener *> > m_listeners;
};

/* 127 */
struct IActorVtbl
{
  void *(__thiscall *__vecDelDtor)(IActor *self, unsigned int);
  char gap4[12];
  IPlayer *(__thiscall *GetPlayerInterface)(IActor *self);
  void (__thiscall *AddRef)(IActor *self);
  void (__thiscall *Release)(IActor *self);
  void (__thiscall *OnSpawnActor)(IActor *self, IUE4Actor *);
  void (__thiscall *OnDestroyActor)(IActor *self);
  const char *(__thiscall *GetBlueprintName)(IActor *self);
  bool (__thiscall *IsCharacter)(IActor *self);
  bool (__thiscall *CanBeDamaged)(IActor *self, IActor *);
  int (__thiscall *GetHealth)(IActor *self);
  int (__thiscall *GetMaxHealth)(IActor *self);
  void (__thiscall *Damage)(IActor *self, IActor *, IItem *, int, DamageType);
  void (__thiscall *Tick)(IActor *self, float);
  bool (__thiscall *CanUse)(IActor *self, IPlayer *);
  void (__thiscall *OnUse)(IActor *self, IPlayer *);
  void (__thiscall *OnHit)(IActor *self, IActor *, Vector3 *, Vector3 *);
  void (__thiscall *OnAIMoveComplete)(IActor *self);
  const char *(__thiscall *GetDisplayName)(IActor *self);
  bool (__thiscall *IsElite)(IActor *self);
  bool (__thiscall *IsPvPEnabled)(IActor *self);
  IItem **(__thiscall *GetShopItems)(IActor *self, unsigned int *);
  void (__thiscall *FreeShopItems)(IActor *self, IItem **);
  int (__thiscall *GetBuyPriceForItem)(IActor *self, IItem *);
  int (__thiscall *GetSellPriceForItem)(IActor *self, IItem *);
  Vector3 *(__thiscall *GetLookPosition)(IActor *self, Vector3 *result);
  Rotation *(__thiscall *GetLookRotation)(IActor *self, Rotation *result);
  IActor *(__thiscall *GetOwner)(IActor *self);
};


/* 146 */
struct  TimerSet
{

	/* 176 */
	struct  TimerEvent
	{
		float timeLeft;
		float initialTime;
		bool recurring;
		bool withContext;
		std::function<void __cdecl(void)> callback;
		std::function<void __cdecl(Actor *)> contextCallback;
	};

  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,TimerSet::TimerEvent,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,TimerSet::TimerEvent> > > m_timers;
};


/* 156 */
struct  AIZoneListener
{
  AIZoneListenerVtbl *vfptr;
  AIZone *m_zone;
};

/* 171 */
struct  Spawner : AIZoneListener
{
  std::vector<ActorRef<Actor>,std::allocator<ActorRef<Actor> > > m_actors;
  Vector3 m_position;
  Rotation m_rotation;
  unsigned int m_maxActors;
  float m_maxSpawnTimer;
  float m_currentSpawnTimer;
};

/* 121 */
struct PlayerQuestState
{
  IQuestState *state;
  unsigned int count;
};

/* 126 */
struct IPlayerVtbl
{
  IActor *(__thiscall *GetActorInterface)(IPlayer *self);
  char gap4[32];
  IInventory *(__thiscall *GetInventory)(IPlayer *self);
  unsigned int (__thiscall *GetItemCount)(IPlayer *self, IItem *);
  unsigned int (__thiscall *GetLoadedAmmo)(IPlayer *self, IItem *);
  bool (__thiscall *AddItem)(IPlayer *self, IItem *, unsigned int, bool);
  bool (__thiscall *RemoveItem)(IPlayer *self, IItem *, unsigned int);
  bool (__thiscall *AddLoadedAmmo)(IPlayer *self, IItem *, IItem *, unsigned int);
  bool (__thiscall *RemoveLoadedAmmo)(IPlayer *self, IItem *, unsigned int);
  IItem *(__thiscall *GetItemForSlot)(IPlayer *self, unsigned int);
  void (__thiscall *EquipItem)(IPlayer *self, unsigned int, IItem *);
  unsigned int (__thiscall *GetCurrentSlot)(IPlayer *self);
  void (__thiscall *SetCurrentSlot)(IPlayer *self, unsigned int);
  IItem *(__thiscall *GetCurrentItem)(IPlayer *self);
  int (__thiscall *GetMana)(IPlayer *self);
  bool (__thiscall *UseMana)(IPlayer *self, int);
  void (__thiscall *SetItemCooldown)(IPlayer *self, IItem *, float, bool);
  bool (__thiscall *IsItemOnCooldown)(IPlayer *self, IItem *);
  float (__thiscall *GetItemCooldown)(IPlayer *self, IItem *);
  bool (__thiscall *HasPickedUp)(IPlayer *self, const char *);
  void (__thiscall *MarkAsPickedUp)(IPlayer *self, const char *);
  IQuest **(__thiscall *GetQuestList)(IPlayer *self, unsigned int *);
  void (__thiscall *FreeQuestList)(IPlayer *self, IQuest **);
  IQuest *(__thiscall *GetCurrentQuest)(IPlayer *self);
  void (__thiscall *SetCurrentQuest)(IPlayer *self, IQuest *);
  PlayerQuestState (__thiscall *GetStateForQuest)(IPlayer *self, IQuest *);
  void (__thiscall *StartQuest)(IPlayer *self, IQuest *);
  void (__thiscall *AdvanceQuestToState)(IPlayer *self, IQuest *, IQuestState *);
  void (__thiscall *CompleteQuest)(IPlayer *self, IQuest *);
  bool (__thiscall *IsQuestStarted)(IPlayer *self, IQuest *);
  bool (__thiscall *IsQuestCompleted)(IPlayer *self, IQuest *);
  void (__thiscall *EnterAIZone)(IPlayer *self, const char *);
  void (__thiscall *ExitAIZone)(IPlayer *self, const char *);
  void (__thiscall *UpdateCountdown)(IPlayer *self, int);
  bool (__thiscall *CanReload)(IPlayer *self);
  void (__thiscall *RequestReload)(IPlayer *self);
  float (__thiscall *GetWalkingSpeed)(IPlayer *self);
  float (__thiscall *GetSprintMultiplier)(IPlayer *self);
  float (__thiscall *GetJumpSpeed)(IPlayer *self);
  float (__thiscall *GetJumpHoldTime)(IPlayer *self);
  bool (__thiscall *CanJump)(IPlayer *self);
  void (__thiscall *SetJumpState)(IPlayer *self, bool);
  void (__thiscall *SetSprintState)(IPlayer *self, bool);
  void (__thiscall *SetFireRequestState)(IPlayer *self, bool);
  void (__thiscall *TransitionToNPCState)(IPlayer *self, const char *);
  void (__thiscall *BuyItem)(IPlayer *self, IActor *, IItem *, unsigned int);
  void (__thiscall *SellItem)(IPlayer *self, IActor *, IItem *, unsigned int);
  void (__thiscall *EnterRegion)(IPlayer *self, const char *);
  void (__thiscall *Respawn)(IPlayer *self);
  void (__thiscall *Teleport)(IPlayer *self, const char *);
  void (__thiscall *Chat)(IPlayer *self, const char *);
  IFastTravel *(__thiscall *GetFastTravelDestinations)(IPlayer *self, const char *);
  void (__thiscall *FastTravel)(IPlayer *self, const char *, const char *);
  void (__thiscall *MarkAsAchieved)(IPlayer *self, IAchievement *);
  bool (__thiscall *HasAchieved)(IPlayer *self, IAchievement *);
  void (__thiscall *SubmitDLCKey)(IPlayer *self, const char *);
  unsigned int (__thiscall *GetCircuitInputs)(IPlayer *self, const char *);
  void (__thiscall *SetCircuitInputs)(IPlayer *self, const char *, unsigned int);
  void (__thiscall *GetCircuitOutputs)(IPlayer *self, const char *, bool *, unsigned int);
};

/* 270 */
struct ItemAndCount
{
  IItem *item;
  unsigned int count;
  unsigned int loadedAmmo;
};

/* 202 */
struct  NPC : Actor
{
  std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,NPCState,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,NPCState> > > m_states;
};

/* 708 */
struct  WriteStream
{
  Socket *m_sock;
  std::vector<unsigned char,std::allocator<unsigned char> > m_buffer;
};

/* 2 */
enum ItemRarity
{
  ResourceItem = 0x0,
  NormalItem = 0x1,
  RareItem = 0x2,
  LegendaryItem = 0x3,
  LeetItem = 0x4,
};

/* 112 */
struct IItemVtbl
{
  void *(__thiscall *__vecDelDtor)(IItem *self, unsigned int);
  const char *(__thiscall *GetDescription)(IItem *self); // __declspec(align(16));
  const char *(__thiscall *GetFlavorText)(IItem *self);
  bool (__thiscall *CanEquip)(IItem *self);
  unsigned int (__thiscall *GetMaximumCount)(IItem *self);
  bool (__thiscall *CanActivate)(IItem *self, IPlayer *);
  bool (__thiscall *CanActivateInInventory)(IItem *self);
  void (__thiscall *Activate)(IItem *self, IPlayer *);
  bool (__thiscall *ShowInInventory)(IItem *self);
  bool (__thiscall *ShowEventOnPickup)(IItem *self);
  bool (__thiscall *ShowEventOnDuplicatePickup)(IItem *self);
  bool (__thiscall *ShowNotificationOnPickup)(IItem *self);
  float (__thiscall *GetCooldownTime)(IItem *self);
  ItemRarity (__thiscall *GetItemRarity)(IItem *self);
  IItem *(__thiscall *GetAmmoType)(IItem *self);
  unsigned int (__thiscall *GetClipSize)(IItem *self);
  int (__thiscall *GetDamage)(IItem *self);
  int (__thiscall *GetDamagePerSecond)(IItem *self);
  DamageType (__thiscall *GetDamageType)(IItem *self);
  int (__thiscall *GetManaCost)(IItem *self);
  const char *(__thiscall *GetCustomCostDescription)(IItem *self);
  bool (__thiscall *IsAutoFire)(IItem *self);
  unsigned int (__thiscall *GetNumberOfProjectiles)(IItem *self);
  float (__thiscall *GetReloadTime)(IItem *self, int);
  bool (__thiscall *HasPartialReload)(IItem *self);
  float (__thiscall *GetRange)(IItem *self);
  int (__thiscall *GetTradeValue)(IItem *self);
  bool (__thiscall *IsDynamic)(IItem *self);
  bool (__thiscall *IsUpdating)(IItem *self);
};

/* 120 */
struct IQuestVtbl
{
  const char *(__thiscall *GetName)(IQuest *self);
  const char *(__thiscall *GetDescription)(IQuest *self);
  IQuestState *(__thiscall *GetStartingState)(IQuest *self);
  IQuestState *(__thiscall *GetStateByName)(IQuest *self, const char *);
};

/* 119 */
struct IQuestStateVtbl
{
  const char *(__thiscall *GetName)(IQuestState *self);
  const char *(__thiscall *GetDescription)(IQuestState *self);
  void (__thiscall *CheckForEarlyCompletion)(IQuestState *self, IPlayer *);
  void (__thiscall *OnItemAcquired)(IQuestState *self, IPlayer *, IItem *);
  void (__thiscall *OnItemPickupUsed)(IQuestState *self, IPlayer *, const char *);
};

/* 135 */
union __declspec(align(8)) $C6055675A2667AF7F40C7C16ABBF48CB
{
  void (__cdecl *_Pfn[3])();
  void *_Pobj[3];
  long double _Ldbl;
  char _Alias[12];
};





/* 157 */
struct AIZoneListenerVtbl
{
  void *(__thiscall *__vecDelDtor)(AIZoneListener *self, unsigned int);
  void (__thiscall *OnAIZoneActivated)(AIZoneListener *self);
  void (__thiscall *OnAIZoneDeactivated)(AIZoneListener *self);
};


/* 115 */
struct  IInventory
{
  IInventoryVtbl *vfptr;
};

/* 122 */
struct  IFastTravel
{
  IFastTravelVtbl *vfptr;
};

/* 124 */
struct  IAchievement
{
  IAchievementVtbl *vfptr;
};

/* 194 */
struct  NPCState
{
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > text;
  std::vector<NPCStateTransition,std::allocator<NPCStateTransition> > transitions;
};



/* 703 */
struct  Socket
{
  SocketVtbl *vfptr;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_lastErrorMessage;
};


/* 116 */
struct IInventoryVtbl
{
  void *(__thiscall *__vecDelDtor)(IInventory *self, unsigned int);
  unsigned int (__thiscall *GetCount)(IInventory *self);
  IItem *(__thiscall *GetItem)(IInventory *self, unsigned int);
  unsigned int (__thiscall *GetItemCount)(IInventory *self, unsigned int);
  unsigned int (__thiscall *GetItemLoadedAmmo)(IInventory *self, unsigned int);
  void (__thiscall *Destroy)(IInventory *self);
};

/* 123 */
struct IFastTravelVtbl
{
  void *(__thiscall *__vecDelDtor)(IFastTravel *self, unsigned int);
  unsigned int (__thiscall *GetCount)(IFastTravel *self);
  const char *(__thiscall *GetRegionName)(IFastTravel *self, unsigned int);
  const char *(__thiscall *GetDisplayName)(IFastTravel *self, unsigned int);
  void (__thiscall *Destroy)(IFastTravel *self);
};

/* 125 */
struct IAchievementVtbl
{
  const char *(__thiscall *GetName)(IAchievement *self);
  const char *(__thiscall *GetDisplayName)(IAchievement *self);
  const char *(__thiscall *GetDescription)(IAchievement *self);
};

/* 6 */
enum NPCStateTransitionType
{
  EndConversationTransition = 0x0,
  ContinueConversationTransition = 0x1,
  ShopTransition = 0x2,
};

/* 190 */
struct  NPCStateTransition
{
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > text;
  NPCStateTransitionType type;
  std::basic_string<char,std::char_traits<char>,std::allocator<char> > nextState;
};

/* 704 */
struct SocketVtbl
{
  void *(__thiscall *__vecDelDtor)(Socket *self, unsigned int);
  bool (__thiscall *Read)(Socket *self, void *, unsigned int);
  bool (__thiscall *Write)(Socket *self, const void *, unsigned int);
};
