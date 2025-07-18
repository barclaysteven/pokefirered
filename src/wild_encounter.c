#include "global.h"
#include "random.h"
#include "wild_encounter.h"
#include "event_data.h"
#include "fieldmap.h"
#include "random.h"
#include "roamer.h"
#include "field_player_avatar.h"
#include "battle_setup.h"
#include "overworld.h"
#include "metatile_behavior.h"
#include "event_scripts.h"
#include "script.h"
#include "link.h"
#include "quest_log.h"
#include "constants/maps.h"
#include "constants/abilities.h"
#include "constants/items.h"

#define MAX_ENCOUNTER_RATE 1600

#define HEADER_NONE 0xFFFF

struct WildEncounterData
{
    u32 rngState;
    u16 prevMetatileBehavior;
    u16 encounterRateBuff;
    u8 stepsSinceLastEncounter;
    u8 abilityEffect;
    u16 leadMonHeldItem;
};

static EWRAM_DATA struct WildEncounterData sWildEncounterData = {};
static EWRAM_DATA bool8 sWildEncountersDisabled = FALSE;


// Forward declarations for functions used before definition
static bool8 UnlockedTanobyOrAreNotInTanoby(void);
static u32 GenerateUnownPersonalityByLetter(u8 letter);
static bool8 IsWildLevelAllowedByRepel(u8 level);
static void ApplyFluteEncounterRateMod(u32 *rate);
static u8 GetFluteEncounterRateModType(void);
static void ApplyCleanseTagEncounterRateMod(u32 *rate);
static bool8 IsLeadMonHoldingCleanseTag(void);
static u16 WildEncounterRandom(void);
static void AddToWildEncounterRateBuff(u8 encouterRate);
// Removed static declarations for ChooseWildMonIndex_Land, ChooseWildMonIndex_WaterRock, ChooseWildMonIndex_Fishing to match external linkage

// Structure to map numerical map IDs to string names
struct MapNameMapping {
    u8 mapGroup;
    u8 mapNum;
    const char *name;
};

// Map name lookup table
static const struct MapNameMapping sMapNameTable[] = {
    // Tanoby Ruins chambers
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER"},
    {MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER), MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER), "MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER"},
    
    // Main areas from gTypeGroupEncounters
    {MAP_GROUP(MAP_VIRIDIAN_FOREST), MAP_NUM(MAP_VIRIDIAN_FOREST), "MAP_VIRIDIAN_FOREST"},
    {MAP_GROUP(MAP_MT_MOON_1F), MAP_NUM(MAP_MT_MOON_1F), "MAP_MT_MOON_1F"},
    {MAP_GROUP(MAP_MT_MOON_B1F), MAP_NUM(MAP_MT_MOON_B1F), "MAP_MT_MOON_B1F"},
    {MAP_GROUP(MAP_MT_MOON_B2F), MAP_NUM(MAP_MT_MOON_B2F), "MAP_MT_MOON_B2F"},
    {MAP_GROUP(MAP_SSANNE_EXTERIOR), MAP_NUM(MAP_SSANNE_EXTERIOR), "MAP_SSANNE_EXTERIOR"},
    {MAP_GROUP(MAP_DIGLETTS_CAVE_B1F), MAP_NUM(MAP_DIGLETTS_CAVE_B1F), "MAP_DIGLETTS_CAVE_B1F"},
    {MAP_GROUP(MAP_VICTORY_ROAD_1F), MAP_NUM(MAP_VICTORY_ROAD_1F), "MAP_VICTORY_ROAD_1F"},
    {MAP_GROUP(MAP_VICTORY_ROAD_2F), MAP_NUM(MAP_VICTORY_ROAD_2F), "MAP_VICTORY_ROAD_2F"},
    {MAP_GROUP(MAP_VICTORY_ROAD_3F), MAP_NUM(MAP_VICTORY_ROAD_3F), "MAP_VICTORY_ROAD_3F"},
    {MAP_GROUP(MAP_POKEMON_MANSION_1F), MAP_NUM(MAP_POKEMON_MANSION_1F), "MAP_POKEMON_MANSION_1F"},
    {MAP_GROUP(MAP_POKEMON_MANSION_2F), MAP_NUM(MAP_POKEMON_MANSION_2F), "MAP_POKEMON_MANSION_2F"},
    {MAP_GROUP(MAP_POKEMON_MANSION_3F), MAP_NUM(MAP_POKEMON_MANSION_3F), "MAP_POKEMON_MANSION_3F"},
    {MAP_GROUP(MAP_POKEMON_MANSION_B1F), MAP_NUM(MAP_POKEMON_MANSION_B1F), "MAP_POKEMON_MANSION_B1F"},
    {MAP_GROUP(MAP_SAFARI_ZONE_CENTER), MAP_NUM(MAP_SAFARI_ZONE_CENTER), "MAP_SAFARI_ZONE_CENTER"},
    {MAP_GROUP(MAP_SAFARI_ZONE_EAST), MAP_NUM(MAP_SAFARI_ZONE_EAST), "MAP_SAFARI_ZONE_EAST"},
    {MAP_GROUP(MAP_SAFARI_ZONE_NORTH), MAP_NUM(MAP_SAFARI_ZONE_NORTH), "MAP_SAFARI_ZONE_NORTH"},
    {MAP_GROUP(MAP_SAFARI_ZONE_WEST), MAP_NUM(MAP_SAFARI_ZONE_WEST), "MAP_SAFARI_ZONE_WEST"},
    {MAP_GROUP(MAP_CERULEAN_CAVE_1F), MAP_NUM(MAP_CERULEAN_CAVE_1F), "MAP_CERULEAN_CAVE_1F"},
    {MAP_GROUP(MAP_CERULEAN_CAVE_2F), MAP_NUM(MAP_CERULEAN_CAVE_2F), "MAP_CERULEAN_CAVE_2F"},
    {MAP_GROUP(MAP_CERULEAN_CAVE_B1F), MAP_NUM(MAP_CERULEAN_CAVE_B1F), "MAP_CERULEAN_CAVE_B1F"},
    {MAP_GROUP(MAP_ROCK_TUNNEL_1F), MAP_NUM(MAP_ROCK_TUNNEL_1F), "MAP_ROCK_TUNNEL_1F"},
    {MAP_GROUP(MAP_ROCK_TUNNEL_B1F), MAP_NUM(MAP_ROCK_TUNNEL_B1F), "MAP_ROCK_TUNNEL_B1F"},
    {MAP_GROUP(MAP_SEAFOAM_ISLANDS_1F), MAP_NUM(MAP_SEAFOAM_ISLANDS_1F), "MAP_SEAFOAM_ISLANDS_1F"},
    {MAP_GROUP(MAP_SEAFOAM_ISLANDS_B1F), MAP_NUM(MAP_SEAFOAM_ISLANDS_B1F), "MAP_SEAFOAM_ISLANDS_B1F"},
    {MAP_GROUP(MAP_SEAFOAM_ISLANDS_B2F), MAP_NUM(MAP_SEAFOAM_ISLANDS_B2F), "MAP_SEAFOAM_ISLANDS_B2F"},
    {MAP_GROUP(MAP_SEAFOAM_ISLANDS_B3F), MAP_NUM(MAP_SEAFOAM_ISLANDS_B3F), "MAP_SEAFOAM_ISLANDS_B3F"},
    {MAP_GROUP(MAP_SEAFOAM_ISLANDS_B4F), MAP_NUM(MAP_SEAFOAM_ISLANDS_B4F), "MAP_SEAFOAM_ISLANDS_B4F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_1F), MAP_NUM(MAP_POKEMON_TOWER_1F), "MAP_POKEMON_TOWER_1F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_2F), MAP_NUM(MAP_POKEMON_TOWER_2F), "MAP_POKEMON_TOWER_2F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_3F), MAP_NUM(MAP_POKEMON_TOWER_3F), "MAP_POKEMON_TOWER_3F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_4F), MAP_NUM(MAP_POKEMON_TOWER_4F), "MAP_POKEMON_TOWER_4F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_5F), MAP_NUM(MAP_POKEMON_TOWER_5F), "MAP_POKEMON_TOWER_5F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_6F), MAP_NUM(MAP_POKEMON_TOWER_6F), "MAP_POKEMON_TOWER_6F"},
    {MAP_GROUP(MAP_POKEMON_TOWER_7F), MAP_NUM(MAP_POKEMON_TOWER_7F), "MAP_POKEMON_TOWER_7F"},
    {MAP_GROUP(MAP_POWER_PLANT), MAP_NUM(MAP_POWER_PLANT), "MAP_POWER_PLANT"},
    
    // Towns and routes
    {MAP_GROUP(MAP_PALLET_TOWN), MAP_NUM(MAP_PALLET_TOWN), "MAP_PALLET_TOWN"},
    {MAP_GROUP(MAP_VIRIDIAN_CITY), MAP_NUM(MAP_VIRIDIAN_CITY), "MAP_VIRIDIAN_CITY"},
    {MAP_GROUP(MAP_PEWTER_CITY), MAP_NUM(MAP_PEWTER_CITY), "MAP_PEWTER_CITY"},
    {MAP_GROUP(MAP_CERULEAN_CITY), MAP_NUM(MAP_CERULEAN_CITY), "MAP_CERULEAN_CITY"},
    {MAP_GROUP(MAP_LAVENDER_TOWN), MAP_NUM(MAP_LAVENDER_TOWN), "MAP_LAVENDER_TOWN"},
    {MAP_GROUP(MAP_VERMILION_CITY), MAP_NUM(MAP_VERMILION_CITY), "MAP_VERMILION_CITY"},
    {MAP_GROUP(MAP_CELADON_CITY), MAP_NUM(MAP_CELADON_CITY), "MAP_CELADON_CITY"},
    {MAP_GROUP(MAP_FUCHSIA_CITY), MAP_NUM(MAP_FUCHSIA_CITY), "MAP_FUCHSIA_CITY"},
    {MAP_GROUP(MAP_CINNABAR_ISLAND), MAP_NUM(MAP_CINNABAR_ISLAND), "MAP_CINNABAR_ISLAND"},
    {MAP_GROUP(MAP_SAFFRON_CITY), MAP_NUM(MAP_SAFFRON_CITY), "MAP_SAFFRON_CITY"},
    
    // Routes
    {MAP_GROUP(MAP_ROUTE1), MAP_NUM(MAP_ROUTE1), "MAP_ROUTE1"},
    {MAP_GROUP(MAP_ROUTE2), MAP_NUM(MAP_ROUTE2), "MAP_ROUTE2"},
    {MAP_GROUP(MAP_ROUTE3), MAP_NUM(MAP_ROUTE3), "MAP_ROUTE3"},
    {MAP_GROUP(MAP_ROUTE4), MAP_NUM(MAP_ROUTE4), "MAP_ROUTE4"},
    {MAP_GROUP(MAP_ROUTE5), MAP_NUM(MAP_ROUTE5), "MAP_ROUTE5"},
    {MAP_GROUP(MAP_ROUTE6), MAP_NUM(MAP_ROUTE6), "MAP_ROUTE6"},
    {MAP_GROUP(MAP_ROUTE7), MAP_NUM(MAP_ROUTE7), "MAP_ROUTE7"},
    {MAP_GROUP(MAP_ROUTE8), MAP_NUM(MAP_ROUTE8), "MAP_ROUTE8"},
    {MAP_GROUP(MAP_ROUTE9), MAP_NUM(MAP_ROUTE9), "MAP_ROUTE9"},
    {MAP_GROUP(MAP_ROUTE10), MAP_NUM(MAP_ROUTE10), "MAP_ROUTE10"},
    {MAP_GROUP(MAP_ROUTE11), MAP_NUM(MAP_ROUTE11), "MAP_ROUTE11"},
    {MAP_GROUP(MAP_ROUTE12), MAP_NUM(MAP_ROUTE12), "MAP_ROUTE12"},
    {MAP_GROUP(MAP_ROUTE13), MAP_NUM(MAP_ROUTE13), "MAP_ROUTE13"},
    {MAP_GROUP(MAP_ROUTE14), MAP_NUM(MAP_ROUTE14), "MAP_ROUTE14"},
    {MAP_GROUP(MAP_ROUTE15), MAP_NUM(MAP_ROUTE15), "MAP_ROUTE15"},
    {MAP_GROUP(MAP_ROUTE16), MAP_NUM(MAP_ROUTE16), "MAP_ROUTE16"},
    {MAP_GROUP(MAP_ROUTE17), MAP_NUM(MAP_ROUTE17), "MAP_ROUTE17"},
    {MAP_GROUP(MAP_ROUTE18), MAP_NUM(MAP_ROUTE18), "MAP_ROUTE18"},
    {MAP_GROUP(MAP_ROUTE19), MAP_NUM(MAP_ROUTE19), "MAP_ROUTE19"},
    {MAP_GROUP(MAP_ROUTE20), MAP_NUM(MAP_ROUTE20), "MAP_ROUTE20"},
    {MAP_GROUP(MAP_ROUTE21_NORTH), MAP_NUM(MAP_ROUTE21_NORTH), "MAP_ROUTE21_NORTH"},
    {MAP_GROUP(MAP_ROUTE21_SOUTH), MAP_NUM(MAP_ROUTE21_SOUTH), "MAP_ROUTE21_SOUTH"},
    {MAP_GROUP(MAP_ROUTE22), MAP_NUM(MAP_ROUTE22), "MAP_ROUTE22"},
    {MAP_GROUP(MAP_ROUTE23), MAP_NUM(MAP_ROUTE23), "MAP_ROUTE23"},
    {MAP_GROUP(MAP_ROUTE24), MAP_NUM(MAP_ROUTE24), "MAP_ROUTE24"},
    {MAP_GROUP(MAP_ROUTE25), MAP_NUM(MAP_ROUTE25), "MAP_ROUTE25"},
    
    // Add terminator
    {0xFF, 0xFF, NULL}
};

const char *GetCurrentMapName(void)
{
    u8 currentMapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 currentMapNum = gSaveBlock1Ptr->location.mapNum;
    u32 i;
    
    for (i = 0; sMapNameTable[i].name != NULL; i++)
    {
        if (sMapNameTable[i].mapGroup == currentMapGroup && sMapNameTable[i].mapNum == currentMapNum)
        {
            return sMapNameTable[i].name;
        }
    }
    
    // Return NULL if map not found
    return NULL;
}

#include "data/pokemon/type_groups.h"
#include "data/wild_encounters.h"

static const u8 sUnownLetterSlots[][LAND_WILD_COUNT] = {
  //  A   A   A   A   A   A   A   A   A   A   A   ?
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 27},
  //  C   C   C   D   D   D   H   H   H   U   U   O
    { 2,  2,  2,  3,  3,  3,  7,  7,  7, 20, 20, 14},
  //  N   N   N   N   S   S   S   S   I   I   E   E
    {13, 13, 13, 13, 18, 18, 18, 18,  8,  8,  4,  4},
  //  P   P   L   L   J   J   R   R   R   Q   Q   Q
    {15, 15, 11, 11,  9,  9, 17, 17, 17, 16, 16, 16},
  //  Y   Y   T   T   G   G   G   F   F   F   K   K
    {24, 24, 19, 19,  6,  6,  6,  5,  5,  5, 10, 10},
  //  V   V   V   W   W   W   X   X   M   M   B   B
    {21, 21, 21, 22, 22, 22, 23, 23, 12, 12,  1,  1},
  //  Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   Z   !
    {25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 26},
};

void DisableWildEncounters(bool8 state)
{
    sWildEncountersDisabled = state;
}

static u8 ChooseWildMonIndex_Land(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_LAND_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_3)
        return 3;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_3 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_4)
        return 4;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_4 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_5)
        return 5;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_5 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_6)
        return 6;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_6 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_7)
        return 7;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_7 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_8)
        return 8;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_8 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_9)
        return 9;
    else if (rand >= ENCOUNTER_CHANCE_LAND_MONS_SLOT_9 && rand < ENCOUNTER_CHANCE_LAND_MONS_SLOT_10)
        return 10;
    else
        return 11;
}

static u8 ChooseWildMonIndex_WaterRock(void)
{
    u8 rand = Random() % ENCOUNTER_CHANCE_WATER_MONS_TOTAL;

    if (rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_0)
        return 0;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_0 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_1)
        return 1;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_1 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_2)
        return 2;
    else if (rand >= ENCOUNTER_CHANCE_WATER_MONS_SLOT_2 && rand < ENCOUNTER_CHANCE_WATER_MONS_SLOT_3)
        return 3;
    else
        return 4;
}

static u8 ChooseWildMonIndex_Fishing(u8 rod)
{
    u8 wildMonIndex = 0;
    u8 rand = Random() % max(max(ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_TOTAL, ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_TOTAL),
                             ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_TOTAL);

    switch (rod)
    {
    case OLD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_OLD_ROD_SLOT_0)
            wildMonIndex = 0;
        else
            wildMonIndex = 1;
        break;
    case GOOD_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2)
            wildMonIndex = 2;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_2 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3)
            wildMonIndex = 3;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_3 && rand < ENCOUNTER_CHANCE_FISHING_MONS_GOOD_ROD_SLOT_4)
            wildMonIndex = 4;
        break;
    case SUPER_ROD:
        if (rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5)
            wildMonIndex = 5;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_5 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6)
            wildMonIndex = 6;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_6 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7)
            wildMonIndex = 7;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_7 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8)
            wildMonIndex = 8;
        if (rand >= ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_8 && rand < ENCOUNTER_CHANCE_FISHING_MONS_SUPER_ROD_SLOT_9)
            wildMonIndex = 9;
        break;
    }
    return wildMonIndex;
}

static u8 ChooseWildMonLevel(const struct WildPokemon * info)
{
    u8 lo;
    u8 hi;
    u8 mod;
    u8 res;
    if (info->maxLevel >= info->minLevel)
    {
        lo = info->minLevel;
        hi = info->maxLevel;
    }
    else
    {
        lo = info->maxLevel;
        hi = info->minLevel;
    }
    mod = hi - lo + 1;
    res = Random() % mod;
    return lo + res;
}

static u16 GetCurrentMapWildMonHeaderId(void)
{
    u16 i;

    for (i = 0; ; i++)
    {
        const struct WildPokemonHeader * wildHeader = &gWildMonHeaders[i];
        if (wildHeader->mapGroup == MAP_GROUP(MAP_UNDEFINED))
            break;

        if (gWildMonHeaders[i].mapGroup == gSaveBlock1Ptr->location.mapGroup &&
            gWildMonHeaders[i].mapNum == gSaveBlock1Ptr->location.mapNum)
        {
            if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_SIX_ISLAND_ALTERING_CAVE) &&
                gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SIX_ISLAND_ALTERING_CAVE))
            {
                u16 alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
                if (alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
                    alteringCaveId = 0;

                i += alteringCaveId;
            }

            if (!UnlockedTanobyOrAreNotInTanoby())
                break;
            return i;
        }
    }

    return HEADER_NONE;
}

static bool8 UnlockedTanobyOrAreNotInTanoby(void)
{
    if (FlagGet(FLAG_SYS_UNLOCKED_TANOBY_RUINS))
        return TRUE;
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER))
        return TRUE;
    if (!(gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER)
    ||  gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER)
    ))
        return TRUE;
    return FALSE;
}

static void GenerateWildMon(u16 species, u8 level, u8 slot)
{
    u32 personality;
    s8 chamber;
    ZeroEnemyPartyMons();
    if (species != SPECIES_UNOWN)
    {
        CreateMonWithNature(&gEnemyParty[0], species, level, USE_RANDOM_IVS, Random() % NUM_NATURES);
    }
    else
    {
        chamber = gSaveBlock1Ptr->location.mapNum - MAP_NUM(MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER);
        personality = GenerateUnownPersonalityByLetter(sUnownLetterSlots[chamber][slot]);
        CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, TRUE, personality, FALSE, 0);
    }
}

static u32 GenerateUnownPersonalityByLetter(u8 letter)
{
    u32 personality;
    do
    {
        personality = (Random() << 16) | Random();
    } while (GetUnownLetterByPersonalityLoByte(personality) != letter);
    return personality;
}

u8 GetUnownLetterByPersonalityLoByte(u32 personality)
{
    return GET_UNOWN_LETTER(personality);
}

enum
{
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING,
};

#define WILD_CHECK_REPEL    0x1
#define WILD_CHECK_KEEN_EYE 0x2

static bool8 TryGenerateWildMon(const struct WildPokemonInfo * info, u8 area, u8 flags)
{
    u8 slot = 0;
    u8 level;
    switch (area)
    {
    case WILD_AREA_LAND:
        slot = ChooseWildMonIndex_Land();
        break;
    case WILD_AREA_WATER:
        slot = ChooseWildMonIndex_WaterRock();
        break;
    case WILD_AREA_ROCKS:
        slot = ChooseWildMonIndex_WaterRock();
        break;
    }
    level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    if (flags == WILD_CHECK_REPEL && !IsWildLevelAllowedByRepel(level))
    {
        return FALSE;
    }
    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return TRUE;
}

static u16 GenerateFishingEncounter(const struct WildPokemonInfo * info, u8 rod)
{
    u8 slot = ChooseWildMonIndex_Fishing(rod);
    u8 level = ChooseWildMonLevel(&info->wildPokemon[slot]);
    GenerateWildMon(info->wildPokemon[slot].species, level, slot);
    return info->wildPokemon[slot].species;
}

static bool8 DoWildEncounterRateDiceRoll(u16 encounterRate)
{
    if (WildEncounterRandom() % MAX_ENCOUNTER_RATE < encounterRate)
        return TRUE;
    return FALSE;
}

static bool8 DoWildEncounterRateTest(u32 encounterRate, bool8 ignoreAbility)
{
    encounterRate *= 16;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        encounterRate = encounterRate * 80 / 100;
    encounterRate += sWildEncounterData.encounterRateBuff * 16 / 200;
    ApplyFluteEncounterRateMod(&encounterRate);
    ApplyCleanseTagEncounterRateMod(&encounterRate);
    if (!ignoreAbility)
    {
        switch (sWildEncounterData.abilityEffect)
        {
        case 1:
            encounterRate /= 2;
            break;
        case 2:
            encounterRate *= 2;
            break;
        }
    }
    if (encounterRate > MAX_ENCOUNTER_RATE)
        encounterRate = MAX_ENCOUNTER_RATE;
    return DoWildEncounterRateDiceRoll(encounterRate);
}

static u8 GetAbilityEncounterRateModType(void)
{
    sWildEncounterData.abilityEffect = 0;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
    {
        u8 ability = GetMonAbility(&gPlayerParty[0]);
        if (ability == ABILITY_STENCH)
            sWildEncounterData.abilityEffect = 1;
        else if (ability == ABILITY_ILLUMINATE)
            sWildEncounterData.abilityEffect = 2;
    }
    return sWildEncounterData.abilityEffect;
}

static bool8 DoGlobalWildEncounterDiceRoll(void)
{
    if ((Random() % 100) >= 60)
        return FALSE;
    return TRUE;
}

// Helper to find the type group encounter for a given map and encounter type
static const TypeGroupEncounter *FindTypeGroupEncounter(const char *map, EncounterType encounterType) {
    unsigned int i;
    for (i = 0; i < sizeof(gTypeGroupEncounters)/sizeof(gTypeGroupEncounters[0]); ++i) {
        if (strcmp(gTypeGroupEncounters[i].map, map) == 0 && gTypeGroupEncounters[i].encounterType == encounterType) {
            return &gTypeGroupEncounters[i];
        }
    }
    return NULL;
}

bool8 StandardWildEncounter(u32 currMetatileAttrs, u16 previousMetatileBehavior)
{
    struct Roamer *roamer;
    const char *mapName;
    EncounterType encounterType;
    const TypeGroupEncounter *tg;
    u32 encounterRate;
    u8 slot;
    u16 species;
    u8 leadLevel;
    int minLevel;
    int maxLevel;
    u8 level;

    if (sWildEncountersDisabled == TRUE)
        return FALSE;

    // Get current map name (assume a function GetCurrentMapName() exists or use a macro/constant)
    mapName = GetCurrentMapName();
    encounterType = ENCOUNTER_LAND;
    if (ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
        encounterType = ENCOUNTER_LAND;
    else if (ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER
             || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING) && MetatileBehavior_IsBridge(ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR)) == TRUE))
        encounterType = ENCOUNTER_WATER;
    else
        return FALSE;

    tg = FindTypeGroupEncounter(mapName, encounterType);
    if (!tg)
        return FALSE;

    // Encounter rate logic (use a default or configurable value, or add to TypeGroupEncounter if needed)
    encounterRate = 30; // Example default, adjust as needed
    if (previousMetatileBehavior != ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR) && !DoGlobalWildEncounterDiceRoll())
        return FALSE;
    if (DoWildEncounterRateTest(encounterRate, FALSE) != TRUE)
    {
        AddToWildEncounterRateBuff(encounterRate);
        return FALSE;
    }

    if (TryStartRoamerEncounter() == TRUE)
    {
        roamer = &gSaveBlock1Ptr->roamer;
        if (!IsWildLevelAllowedByRepel(roamer->level))
        {
            return FALSE;
        }
        StartRoamerBattle();
        return TRUE;
    }

    // Choose a random Pokémon from the type group
    slot = Random() % tg->typeGroupSize;
    species = tg->typeGroup[slot];
    // Set level to lead Pokémon's level +/- 2, clamped to 2-100
    leadLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
    minLevel = (leadLevel - 2 < 2) ? 2 : leadLevel - 2;
    maxLevel = (leadLevel + 2 > 100) ? 100 : leadLevel + 2;
    level = minLevel + (Random() % (maxLevel - minLevel + 1));
    if (IsWildLevelAllowedByRepel(level)) {
        GenerateWildMon(species, level, slot);
        StartWildBattle();
        return TRUE;
    } else {
        AddToWildEncounterRateBuff(encounterRate);
        return FALSE;
    }
}

void RockSmashWildEncounter(void)
{
    const char *mapName = GetCurrentMapName();
    const TypeGroupEncounter *tg;
    u32 encounterRate = 30; // Default encounter rate for rock smash
    u8 slot;
    u16 species;
    u8 leadLevel;
    int minLevel;
    int maxLevel;
    u8 level;
    
    if (mapName == NULL)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    
    tg = FindTypeGroupEncounter(mapName, ENCOUNTER_LAND);
    if (tg == NULL)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    
    if (DoWildEncounterRateTest(encounterRate, TRUE) != TRUE)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    
    // Choose a random Pokémon from the type group
    slot = Random() % tg->typeGroupSize;
    species = tg->typeGroup[slot];
    
    // Set level to lead Pokémon's level +/- 2, clamped to 2-100
    leadLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
    minLevel = (leadLevel - 2 < 2) ? 2 : leadLevel - 2;
    maxLevel = (leadLevel + 2 > 100) ? 100 : leadLevel + 2;
    level = minLevel + (Random() % (maxLevel - minLevel + 1));
    
    if (IsWildLevelAllowedByRepel(level))
    {
        GenerateWildMon(species, level, slot);
        StartWildBattle();
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

bool8 SweetScentWildEncounter(void)
{
    s16 x, y;
    const char *mapName;
    const TypeGroupEncounter *tg;
    EncounterType encounterType;
    u8 slot;
    u16 species;
    u8 leadLevel;
    int minLevel;
    int maxLevel;
    u8 level;

    PlayerGetDestCoords(&x, &y);
    mapName = GetCurrentMapName();
    
    if (mapName == NULL)
        return FALSE;
    
    if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_LAND)
    {
        encounterType = ENCOUNTER_LAND;
        
        if (TryStartRoamerEncounter() == TRUE)
        {
            StartRoamerBattle();
            return TRUE;
        }

        tg = FindTypeGroupEncounter(mapName, encounterType);
        if (tg == NULL)
            return FALSE;

        // Choose a random Pokémon from the type group
        slot = Random() % tg->typeGroupSize;
        species = tg->typeGroup[slot];
        
        // Set level to lead Pokémon's level +/- 2, clamped to 2-100
        leadLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        minLevel = (leadLevel - 2 < 2) ? 2 : leadLevel - 2;
        maxLevel = (leadLevel + 2 > 100) ? 100 : leadLevel + 2;
        level = minLevel + (Random() % (maxLevel - minLevel + 1));
        
        GenerateWildMon(species, level, slot);
        StartWildBattle();
        return TRUE;
    }
    else if (MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_ENCOUNTER_TYPE) == TILE_ENCOUNTER_WATER)
    {
        encounterType = ENCOUNTER_WATER;
        
        if (TryStartRoamerEncounter() == TRUE)
        {
            StartRoamerBattle();
            return TRUE;
        }

        tg = FindTypeGroupEncounter(mapName, encounterType);
        if (tg == NULL)
            return FALSE;

        // Choose a random Pokémon from the type group
        slot = Random() % tg->typeGroupSize;
        species = tg->typeGroup[slot];
        
        // Set level to lead Pokémon's level +/- 2, clamped to 2-100
        leadLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
        minLevel = (leadLevel - 2 < 2) ? 2 : leadLevel - 2;
        maxLevel = (leadLevel + 2 > 100) ? 100 : leadLevel + 2;
        level = minLevel + (Random() % (maxLevel - minLevel + 1));
        
        GenerateWildMon(species, level, slot);
        StartWildBattle();
        return TRUE;
    }

    return FALSE;
}

bool8 DoesCurrentMapHaveFishingMons(void)
{
    const char *mapName = GetCurrentMapName();
    const TypeGroupEncounter *tg;
    
    if (mapName == NULL)
        return FALSE;
    
    tg = FindTypeGroupEncounter(mapName, ENCOUNTER_FISHING);
    return (tg != NULL);
}

void FishingWildEncounter(u8 rod)
{
    const char *mapName = GetCurrentMapName();
    const TypeGroupEncounter *tg;
    u8 slot;
    u16 species;
    u8 leadLevel;
    int minLevel;
    int maxLevel;
    u8 level;
    
    if (mapName == NULL)
        return;
    
    tg = FindTypeGroupEncounter(mapName, ENCOUNTER_FISHING);
    if (tg == NULL)
        return;
    
    // Choose a random Pokémon from the type group
    slot = Random() % tg->typeGroupSize;
    species = tg->typeGroup[slot];
    
    // Set level to lead Pokémon's level +/- 2, clamped to 2-100
    leadLevel = GetMonData(&gPlayerParty[0], MON_DATA_LEVEL);
    minLevel = (leadLevel - 2 < 2) ? 2 : leadLevel - 2;
    maxLevel = (leadLevel + 2 > 100) ? 100 : leadLevel + 2;
    level = minLevel + (Random() % (maxLevel - minLevel + 1));
    
    GenerateWildMon(species, level, slot);
    IncrementGameStat(GAME_STAT_FISHING_CAPTURES);
    StartWildBattle();
}

u16 GetLocalWildMon(bool8 *isWaterMon)
{
    const char *mapName = GetCurrentMapName();
    const TypeGroupEncounter *landTg, *waterTg;
    u8 slot;

    *isWaterMon = FALSE;
    
    if (mapName == NULL)
        return SPECIES_NONE;
    
    landTg = FindTypeGroupEncounter(mapName, ENCOUNTER_LAND);
    waterTg = FindTypeGroupEncounter(mapName, ENCOUNTER_WATER);
    
    // Neither
    if (landTg == NULL && waterTg == NULL)
        return SPECIES_NONE;
    // Land Pokemon only
    else if (landTg != NULL && waterTg == NULL)
    {
        slot = Random() % landTg->typeGroupSize;
        return landTg->typeGroup[slot];
    }
    // Water Pokemon only
    else if (landTg == NULL && waterTg != NULL)
    {
        *isWaterMon = TRUE;
        slot = Random() % waterTg->typeGroupSize;
        return waterTg->typeGroup[slot];
    }
    // Either land or water Pokemon
    if ((Random() % 100) < 80)
    {
        slot = Random() % landTg->typeGroupSize;
        return landTg->typeGroup[slot];
    }
    else
    {
        *isWaterMon = TRUE;
        slot = Random() % waterTg->typeGroupSize;
        return waterTg->typeGroup[slot];
    }
}

u16 GetLocalWaterMon(void)
{
    const char *mapName = GetCurrentMapName();
    const TypeGroupEncounter *waterTg;
    u8 slot;

    if (mapName == NULL)
        return SPECIES_NONE;
    
    waterTg = FindTypeGroupEncounter(mapName, ENCOUNTER_WATER);
    
    if (waterTg != NULL)
    {
        slot = Random() % waterTg->typeGroupSize;
        return waterTg->typeGroup[slot];
    }
    
    return SPECIES_NONE;
}

bool8 UpdateRepelCounter(void)
{
    u16 steps;

    if (InUnionRoom() == TRUE)
        return FALSE;

    if (gQuestLogState == QL_STATE_PLAYBACK)
        return FALSE;

    steps = VarGet(VAR_REPEL_STEP_COUNT);

    if (steps != 0)
    {
        steps--;
        VarSet(VAR_REPEL_STEP_COUNT, steps);
        if (steps == 0)
        {
            ScriptContext_SetupScript(EventScript_RepelWoreOff);
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 IsWildLevelAllowedByRepel(u8 wildLevel)
{
    u8 i;

    if (!VarGet(VAR_REPEL_STEP_COUNT))
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            u8 ourLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);

            if (wildLevel < ourLevel)
                return FALSE;
            else
                return TRUE;
        }
    }

    return FALSE;
}

static void ApplyFluteEncounterRateMod(u32 *encounterRate)
{
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        *encounterRate += *encounterRate / 2;
        break;
    case 2:
        *encounterRate = *encounterRate / 2;
        break;
    }
}

static u8 GetFluteEncounterRateModType(void)
{
    if (FlagGet(FLAG_SYS_WHITE_FLUTE_ACTIVE) == TRUE)
        return 1;
    else if (FlagGet(FLAG_SYS_BLACK_FLUTE_ACTIVE) == TRUE)
        return 2;
    else
        return 0;
}

static void ApplyCleanseTagEncounterRateMod(u32 *encounterRate)
{
    if (IsLeadMonHoldingCleanseTag())
        *encounterRate = *encounterRate * 2 / 3;
}

static bool8 IsLeadMonHoldingCleanseTag(void)
{
    if (sWildEncounterData.leadMonHeldItem == ITEM_CLEANSE_TAG)
        return TRUE;
    else
        return FALSE;
}

void SeedWildEncounterRng(u16 seed)
{
    sWildEncounterData.rngState = seed;
    ResetEncounterRateModifiers();
}

static u16 WildEncounterRandom(void)
{
    sWildEncounterData.rngState = ISO_RANDOMIZE2(sWildEncounterData.rngState);
    return sWildEncounterData.rngState >> 16;
}

static u8 GetMapBaseEncounterCooldown(u8 encounterType)
{
    u16 headerIdx = GetCurrentMapWildMonHeaderId();
    if (headerIdx == HEADER_NONE)
        return 0xFF;
    if (encounterType == TILE_ENCOUNTER_LAND)
    {
        if (gWildMonHeaders[headerIdx].landMonsInfo == NULL)
            return 0xFF;
        if (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate >= 80)
            return 0;
        if (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate < 10)
            return 8;
        return 8 - (gWildMonHeaders[headerIdx].landMonsInfo->encounterRate / 10);
    }
    if (encounterType == TILE_ENCOUNTER_WATER)
    {
        if (gWildMonHeaders[headerIdx].waterMonsInfo == NULL)
            return 0xFF;
        if (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate >= 80)
            return 0;
        if (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate < 10)
            return 8;
        return 8 - (gWildMonHeaders[headerIdx].waterMonsInfo->encounterRate / 10);
    }
    return 0xFF;
}

void ResetEncounterRateModifiers(void)
{
    sWildEncounterData.encounterRateBuff = 0;
    sWildEncounterData.stepsSinceLastEncounter = 0;
}

static bool8 HandleWildEncounterCooldown(u32 currMetatileAttrs)
{
    u8 encounterType = ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_ENCOUNTER_TYPE);
    u32 minSteps;
    u32 encRate;
    if (encounterType == TILE_ENCOUNTER_NONE)
        return FALSE;
    minSteps = GetMapBaseEncounterCooldown(encounterType);
    if (minSteps == 0xFF)
        return FALSE;
    minSteps *= 256;
    encRate = 5 * 256;
    switch (GetFluteEncounterRateModType())
    {
    case 1:
        minSteps -= minSteps / 2;
        encRate += encRate / 2;
        break;
    case 2:
        minSteps *= 2;
        encRate /= 2;
        break;
    }
    sWildEncounterData.leadMonHeldItem = GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM);
    if (IsLeadMonHoldingCleanseTag() == TRUE)
    {
        minSteps += minSteps / 3;
        encRate -= encRate / 3;
    }
    switch (GetAbilityEncounterRateModType())
    {
    case 1:
        minSteps *= 2;
        encRate /= 2;
        break;
    case 2:
        minSteps /= 2;
        encRate *= 2;
        break;
    }
    minSteps /= 256;
    encRate /= 256;
    if (sWildEncounterData.stepsSinceLastEncounter >= minSteps)
        return TRUE;
    sWildEncounterData.stepsSinceLastEncounter++;
    if ((Random() % 100) < encRate)
        return TRUE;
    return FALSE;
}

bool8 TryStandardWildEncounter(u32 currMetatileAttrs)
{
    if (!HandleWildEncounterCooldown(currMetatileAttrs))
    {
        sWildEncounterData.prevMetatileBehavior = ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
    else if (StandardWildEncounter(currMetatileAttrs, sWildEncounterData.prevMetatileBehavior) == TRUE)
    {
        sWildEncounterData.encounterRateBuff = 0;
        sWildEncounterData.stepsSinceLastEncounter = 0;
        sWildEncounterData.prevMetatileBehavior = ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return TRUE;
    }
    else
    {
        sWildEncounterData.prevMetatileBehavior = ExtractMetatileAttribute(currMetatileAttrs, METATILE_ATTRIBUTE_BEHAVIOR);
        return FALSE;
    }
}

static void AddToWildEncounterRateBuff(u8 encounterRate)
{
    if (VarGet(VAR_REPEL_STEP_COUNT) == 0)
        sWildEncounterData.encounterRateBuff += encounterRate;
    else
        sWildEncounterData.encounterRateBuff = 0;
}
