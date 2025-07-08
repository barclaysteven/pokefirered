// Enum for encounter types
typedef enum {
    ENCOUNTER_LAND,
    ENCOUNTER_WATER,
    ENCOUNTER_FISHING
} EncounterType;
// Combined Water and Ice type group (no duplicates)
// NOTE: Make sure to include the correct headers for species constants
#include "constants/species.h"

// Structure to associate a type group with a map location
typedef struct {
    const char *map;
    EncounterType encounterType;
    const u16 *typeGroup;
    u32 typeGroupSize;
} TypeGroupEncounter;


// Arrays grouping Pokémon by their primary type (first type in species_info.h)
#include "gba/types.h"
#include "constants/species.h"


// Kanto Pokémon grouped by their primary type
const u16 gTypeGroup_Normal[] = {
    SPECIES_PIDGEY,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_JIGGLYPUFF,
    SPECIES_MEOWTH,
    SPECIES_FARFETCHD,
    SPECIES_DODUO,
    SPECIES_CHANSEY,
    SPECIES_KANGASKHAN,
    SPECIES_TAUROS,
    SPECIES_DITTO,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_SNORLAX,
};

const u16 gTypeGroup_Fire[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_Water[] = {
    SPECIES_SQUIRTLE,
    SPECIES_PSYDUCK,
    SPECIES_POLIWAG,
    SPECIES_TENTACOOL,
    SPECIES_SLOWPOKE,
    SPECIES_SEEL,
    SPECIES_SHELLDER,
    SPECIES_KRABBY,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
};

const u16 gTypeGroup_Grass[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_Electric[] = {
    SPECIES_PIKACHU,
    SPECIES_MAGNEMITE,
    SPECIES_VOLTORB,
    SPECIES_ELECTABUZZ,
    SPECIES_ZAPDOS,
};

const u16 gTypeGroup_Ice[] = {
    SPECIES_JYNX,
    SPECIES_LAPRAS,
    SPECIES_ARTICUNO,
};

const u16 gTypeGroup_Fighting[] = {
    SPECIES_MANKEY,
    SPECIES_MACHOP,
    SPECIES_HITMONLEE,
    SPECIES_HITMONCHAN,
};

const u16 gTypeGroup_Poison[] = {
    SPECIES_BULBASAUR,
    SPECIES_EKANS,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_VENONAT,
    SPECIES_BELLSPROUT,
    SPECIES_GRIMER,
    SPECIES_KOFFING,
};

const u16 gTypeGroup_Ground[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_Flying[] = {
    SPECIES_PIDGEY,
    SPECIES_SPEAROW,
    SPECIES_ZUBAT,
    SPECIES_FARFETCHD,
    SPECIES_DODUO,
    SPECIES_SCYTHER,
    SPECIES_AERODACTYL,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_DRATINI,
};

const u16 gTypeGroup_Psychic[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_Bug[] = {
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
};

const u16 gTypeGroup_Rock[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
};

const u16 gTypeGroup_Ghost[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_Dragon[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_Steel[] = {
    SPECIES_MAGNEMITE,
};

const u16 gTypeGroup_Starter[] = {
    // Starters grouped by their primary type
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
};

const u16 gTypeGroup_WaterIce[] = {
    // Water types
    SPECIES_SQUIRTLE,
    SPECIES_PSYDUCK,
    SPECIES_POLIWAG,
    SPECIES_TENTACOOL,
    SPECIES_SLOWPOKE,
    SPECIES_SEEL,
    SPECIES_SHELLDER,
    SPECIES_KRABBY,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    // Ice types (add only if not already present)
    SPECIES_JYNX,
    SPECIES_ARTICUNO,
};



// Example associations (add more as needed)
static const TypeGroupEncounter gTypeGroupEncounters[] = {
    // Associations for all maps in wild_encounters.json
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_VIRIDIAN_FOREST", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_MOON_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_MOON_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_MOON_B2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SSANNE_EXTERIOR", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SSANNE_EXTERIOR", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_DIGLETTS_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROCK_TUNNEL_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROCK_TUNNEL_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_4F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_5F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_6F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_7F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_POWER_PLANT", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_EXTERIOR", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B2F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B3F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B1F_STAIRS", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B2F_STAIRS", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_PATTERN_BUSH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM1", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM2", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM3", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM4", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM5", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM6", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM7", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM8", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM9", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM10", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM11", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM12", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM13", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM14", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_THREE_ISLAND_PORT", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_RESORT_GORGEOUS", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_RESORT_GORGEOUS", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_WATER_LABYRINTH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_WATER_LABYRINTH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_OUTCAST_ISLAND", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_OUTCAST_ISLAND", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_GREEN_PATH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_GREEN_PATH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TRAINER_TOWER", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TRAINER_TOWER", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_SEVAULT_CANYON", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE1", ENCOUNTER_LAND, gTypeGroup_Starter, sizeof(gTypeGroup_Starter)/sizeof(u16)},
    {"MAP_ROUTE2", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE3", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE5", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE7", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE8", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE9", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE14", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE15", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE16", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE17", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE18", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE19", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE19", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE20", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE20", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_PALLET_TOWN", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_PALLET_TOWN", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_VIRIDIAN_CITY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_VIRIDIAN_CITY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CITY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CERULEAN_CITY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_VERMILION_CITY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_VERMILION_CITY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CELADON_CITY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CELADON_CITY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FUCHSIA_CITY", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FUCHSIA_CITY", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CINNABAR_ISLAND", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_CINNABAR_ISLAND", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ONE_ISLAND", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_ONE_ISLAND", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FOUR_ISLAND", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND", ENCOUNTER_WATER, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_FIVE_ISLAND", ENCOUNTER_FISHING, gTypeGroup_WaterIce, sizeof(gTypeGroup_WaterIce)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_Normal, sizeof(gTypeGroup_Normal)/sizeof(u16)},
    // ... Add all other maps from wild_encounters.json here, associating with the most relevant type group and encounter type ...
};