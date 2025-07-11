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
    SPECIES_EEVEE,
    SPECIES_PIKACHU,
};

const u16 gTypeGroup_Fossil[] = {
    // Fossil Pokémon grouped by their primary type
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
};

const u16 gTypeGroup_Legendary[] = {
    // Legendary Pokémon grouped by their primary type
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_Surf[] = {
    SPECIES_SQUIRTLE,
    SPECIES_PSYDUCK,
    SPECIES_POLIWAG,
    SPECIES_SLOWPOKE,
    SPECIES_SEEL,
    SPECIES_LAPRAS,
};

const u16 gTypeGroup_Fishing[] = {
    SPECIES_TENTACOOL,
    SPECIES_SHELLDER,
    SPECIES_KRABBY,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MAGIKARP,
};

// Map-specific type groups for land encounters
const u16 gTypeGroup_SevenIslandTanobyRuinsMoneanChamber[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_SevenIslandTanobyRuinsLiptooChamber[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_SevenIslandTanobyRuinsWeepthChamber[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_SevenIslandTanobyRuinsDilfordChamber[] = {
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

const u16 gTypeGroup_SevenIslandTanobyRuinsScufibChamber[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_SevenIslandTanobyRuinsRixyChamber[] = {
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

const u16 gTypeGroup_SevenIslandTanobyRuinsViapoisChamber[] = {
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

const u16 gTypeGroup_ViridianForest[] = {
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
};

const u16 gTypeGroup_MtMoon1F[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_MtMoonB1F[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_MtMoonB2F[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_DiglettsCaveB1F[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_VictoryRoad1F[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_VictoryRoad2F[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_VictoryRoad3F[] = {
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_PokemonMansion1F[] = {
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

const u16 gTypeGroup_PokemonMansion2F[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_PokemonMansion3F[] = {
    SPECIES_PIKACHU,
    SPECIES_MAGNEMITE,
    SPECIES_VOLTORB,
    SPECIES_ELECTABUZZ,
    SPECIES_ZAPDOS,
};

const u16 gTypeGroup_PokemonMansionB1F[] = {
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_SafariZoneCenter[] = {
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

const u16 gTypeGroup_SafariZoneEast[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_SafariZoneNorth[] = {
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

const u16 gTypeGroup_SafariZoneWest[] = {
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
};

const u16 gTypeGroup_CeruleanCave1F[] = {
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

const u16 gTypeGroup_CeruleanCave2F[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_CeruleanCaveB1F[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_RockTunnel1F[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_RockTunnelB1F[] = {
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_SeafoamIslands1F[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_SeafoamIslandsB1F[] = {
    SPECIES_MANKEY,
    SPECIES_MACHOP,
    SPECIES_HITMONLEE,
    SPECIES_HITMONCHAN,
};

const u16 gTypeGroup_SeafoamIslandsB2F[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_SeafoamIslandsB3F[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_SeafoamIslandsB4F[] = {
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_PokemonTower3F[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_PokemonTower4F[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_PokemonTower5F[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_PokemonTower6F[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_PokemonTower7F[] = {
    SPECIES_GASTLY,
};

const u16 gTypeGroup_PowerPlant[] = {
    SPECIES_PIKACHU,
    SPECIES_MAGNEMITE,
    SPECIES_VOLTORB,
    SPECIES_ELECTABUZZ,
    SPECIES_ZAPDOS,
};

const u16 gTypeGroup_MtEmberExterior[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberSummitPath1F[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberSummitPath2F[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberSummitPath3F[] = {
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_MtEmberRubyPath1F[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_MtEmberRubyPathB1F[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberRubyPathB2F[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberRubyPathB3F[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_MtEmberRubyPathB1FStairs[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_MtEmberRubyPathB2FStairs[] = {
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

const u16 gTypeGroup_ThreeIslandBerryForest[] = {
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

const u16 gTypeGroup_FourIslandIcefallCaveEntrance[] = {
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

const u16 gTypeGroup_FourIslandIcefallCave1F[] = {
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

const u16 gTypeGroup_FourIslandIcefallCaveB1F[] = {
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

const u16 gTypeGroup_FourIslandIcefallCaveBack[] = {
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

const u16 gTypeGroup_SixIslandPatternBush[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom1[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom2[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom3[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom4[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom5[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom6[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom7[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom8[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom9[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom10[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom11[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom12[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom13[] = {
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

const u16 gTypeGroup_FiveIslandLostCaveRoom14[] = {
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

const u16 gTypeGroup_OneIslandKindleRoad[] = {
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

const u16 gTypeGroup_OneIslandTreasureBeach[] = {
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

const u16 gTypeGroup_TwoIslandCapeBrink[] = {
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

const u16 gTypeGroup_ThreeIslandBondBridge[] = {
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

const u16 gTypeGroup_ThreeIslandPort[] = {
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

const u16 gTypeGroup_FiveIslandMeadow[] = {
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

const u16 gTypeGroup_FiveIslandMemorialPillar[] = {
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

const u16 gTypeGroup_SixIslandWaterPath[] = {
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

const u16 gTypeGroup_SixIslandRuinValley[] = {
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

const u16 gTypeGroup_SevenIslandSevaultCanyonEntrance[] = {
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

const u16 gTypeGroup_SevenIslandSevaultCanyon[] = {
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

const u16 gTypeGroup_Route1[] = {
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_EEVEE,
    SPECIES_PIKACHU,
};

const u16 gTypeGroup_Route2[] = {
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

const u16 gTypeGroup_Route3[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_Route4[] = {
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

const u16 gTypeGroup_Route5[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_Route6[] = {
    SPECIES_PIKACHU,
    SPECIES_MAGNEMITE,
    SPECIES_VOLTORB,
    SPECIES_ELECTABUZZ,
    SPECIES_ZAPDOS,
};

const u16 gTypeGroup_Route7[] = {
    SPECIES_CHARMANDER,
    SPECIES_VULPIX,
    SPECIES_GROWLITHE,
    SPECIES_PONYTA,
    SPECIES_MAGMAR,
    SPECIES_MOLTRES,
};

const u16 gTypeGroup_Route8[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_Route9[] = {
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

const u16 gTypeGroup_Route10[] = {
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

const u16 gTypeGroup_Route11[] = {
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
};

const u16 gTypeGroup_Route12[] = {
    SPECIES_PIKACHU,
    SPECIES_MAGNEMITE,
    SPECIES_VOLTORB,
    SPECIES_ELECTABUZZ,
    SPECIES_ZAPDOS,
};

const u16 gTypeGroup_Route13[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_Route14[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_Route15[] = {
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

const u16 gTypeGroup_Route16[] = {
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

const u16 gTypeGroup_Route17[] = {
    SPECIES_SANDSHREW,
    SPECIES_DIGLETT,
    SPECIES_GEODUDE,
    SPECIES_ONIX,
    SPECIES_CUBONE,
    SPECIES_RHYHORN,
};

const u16 gTypeGroup_Route18[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_Route21North[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_Route21South[] = {
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

const u16 gTypeGroup_Route22[] = {
    SPECIES_MANKEY,
    SPECIES_MACHOP,
    SPECIES_HITMONLEE,
    SPECIES_HITMONCHAN,
};

const u16 gTypeGroup_Route23[] = {
    SPECIES_DRATINI,
};

const u16 gTypeGroup_Route24[] = {
    SPECIES_ABRA,
    SPECIES_DROWZEE,
    SPECIES_EXEGGCUTE,
    SPECIES_MR_MIME,
    SPECIES_JYNX,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

const u16 gTypeGroup_Route25[] = {
    SPECIES_BULBASAUR,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_BELLSPROUT,
    SPECIES_EXEGGCUTE,
    SPECIES_TANGELA,
};

const u16 gTypeGroup_SixIslandAlteringCave[] = {
    SPECIES_DRAGONITE,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_MEWTWO,
    SPECIES_MEW,
};

// Example associations (add more as needed)
static const TypeGroupEncounter gTypeGroupEncounters[] = {
    // Seven Island Tanoby Ruins Chambers
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsMoneanChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsMoneanChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_LIPTOO_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsLiptooChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsLiptooChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_WEEPTH_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsWeepthChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsWeepthChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_DILFORD_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsDilfordChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsDilfordChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_SCUFIB_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsScufibChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsScufibChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_RIXY_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsRixyChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsRixyChamber)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS_VIAPOIS_CHAMBER", ENCOUNTER_LAND, gTypeGroup_SevenIslandTanobyRuinsViapoisChamber, sizeof(gTypeGroup_SevenIslandTanobyRuinsViapoisChamber)/sizeof(u16)},

    // Forests, Caves, and Special Locations
    // Land Encounters
    {"MAP_VIRIDIAN_FOREST", ENCOUNTER_LAND, gTypeGroup_ViridianForest, sizeof(gTypeGroup_ViridianForest)/sizeof(u16)},
    {"MAP_MT_MOON_1F", ENCOUNTER_LAND, gTypeGroup_MtMoon1F, sizeof(gTypeGroup_MtMoon1F)/sizeof(u16)},
    {"MAP_MT_MOON_B1F", ENCOUNTER_LAND, gTypeGroup_MtMoonB1F, sizeof(gTypeGroup_MtMoonB1F)/sizeof(u16)},
    {"MAP_MT_MOON_B2F", ENCOUNTER_LAND, gTypeGroup_MtMoonB2F, sizeof(gTypeGroup_MtMoonB2F)/sizeof(u16)},
    {"MAP_DIGLETTS_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_DiglettsCaveB1F, sizeof(gTypeGroup_DiglettsCaveB1F)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_1F", ENCOUNTER_LAND, gTypeGroup_VictoryRoad1F, sizeof(gTypeGroup_VictoryRoad1F)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_2F", ENCOUNTER_LAND, gTypeGroup_VictoryRoad2F, sizeof(gTypeGroup_VictoryRoad2F)/sizeof(u16)},
    {"MAP_VICTORY_ROAD_3F", ENCOUNTER_LAND, gTypeGroup_VictoryRoad3F, sizeof(gTypeGroup_VictoryRoad3F)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_1F", ENCOUNTER_LAND, gTypeGroup_PokemonMansion1F, sizeof(gTypeGroup_PokemonMansion1F)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_2F", ENCOUNTER_LAND, gTypeGroup_PokemonMansion2F, sizeof(gTypeGroup_PokemonMansion2F)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_3F", ENCOUNTER_LAND, gTypeGroup_PokemonMansion3F, sizeof(gTypeGroup_PokemonMansion3F)/sizeof(u16)},
    {"MAP_POKEMON_MANSION_B1F", ENCOUNTER_LAND, gTypeGroup_PokemonMansionB1F, sizeof(gTypeGroup_PokemonMansionB1F)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_LAND, gTypeGroup_SafariZoneCenter, sizeof(gTypeGroup_SafariZoneCenter)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_LAND, gTypeGroup_SafariZoneEast, sizeof(gTypeGroup_SafariZoneEast)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_LAND, gTypeGroup_SafariZoneNorth, sizeof(gTypeGroup_SafariZoneNorth)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_LAND, gTypeGroup_SafariZoneWest, sizeof(gTypeGroup_SafariZoneWest)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_LAND, gTypeGroup_CeruleanCave1F, sizeof(gTypeGroup_CeruleanCave1F)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_2F", ENCOUNTER_LAND, gTypeGroup_CeruleanCave2F, sizeof(gTypeGroup_CeruleanCave2F)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_CeruleanCaveB1F, sizeof(gTypeGroup_CeruleanCaveB1F)/sizeof(u16)},
    {"MAP_ROCK_TUNNEL_1F", ENCOUNTER_LAND, gTypeGroup_RockTunnel1F, sizeof(gTypeGroup_RockTunnel1F)/sizeof(u16)},
    {"MAP_ROCK_TUNNEL_B1F", ENCOUNTER_LAND, gTypeGroup_RockTunnelB1F, sizeof(gTypeGroup_RockTunnelB1F)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_1F", ENCOUNTER_LAND, gTypeGroup_SeafoamIslands1F, sizeof(gTypeGroup_SeafoamIslands1F)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B1F", ENCOUNTER_LAND, gTypeGroup_SeafoamIslandsB1F, sizeof(gTypeGroup_SeafoamIslandsB1F)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B2F", ENCOUNTER_LAND, gTypeGroup_SeafoamIslandsB2F, sizeof(gTypeGroup_SeafoamIslandsB2F)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_LAND, gTypeGroup_SeafoamIslandsB3F, sizeof(gTypeGroup_SeafoamIslandsB3F)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_LAND, gTypeGroup_SeafoamIslandsB4F, sizeof(gTypeGroup_SeafoamIslandsB4F)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_3F", ENCOUNTER_LAND, gTypeGroup_PokemonTower3F, sizeof(gTypeGroup_PokemonTower3F)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_4F", ENCOUNTER_LAND, gTypeGroup_PokemonTower4F, sizeof(gTypeGroup_PokemonTower4F)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_5F", ENCOUNTER_LAND, gTypeGroup_PokemonTower5F, sizeof(gTypeGroup_PokemonTower5F)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_6F", ENCOUNTER_LAND, gTypeGroup_PokemonTower6F, sizeof(gTypeGroup_PokemonTower6F)/sizeof(u16)},
    {"MAP_POKEMON_TOWER_7F", ENCOUNTER_LAND, gTypeGroup_PokemonTower7F, sizeof(gTypeGroup_PokemonTower7F)/sizeof(u16)},
    {"MAP_POWER_PLANT", ENCOUNTER_LAND, gTypeGroup_PowerPlant, sizeof(gTypeGroup_PowerPlant)/sizeof(u16)},
    {"MAP_MT_EMBER_EXTERIOR", ENCOUNTER_LAND, gTypeGroup_MtEmberExterior, sizeof(gTypeGroup_MtEmberExterior)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_1F", ENCOUNTER_LAND, gTypeGroup_MtEmberSummitPath1F, sizeof(gTypeGroup_MtEmberSummitPath1F)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_2F", ENCOUNTER_LAND, gTypeGroup_MtEmberSummitPath2F, sizeof(gTypeGroup_MtEmberSummitPath2F)/sizeof(u16)},
    {"MAP_MT_EMBER_SUMMIT_PATH_3F", ENCOUNTER_LAND, gTypeGroup_MtEmberSummitPath3F, sizeof(gTypeGroup_MtEmberSummitPath3F)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_1F", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPath1F, sizeof(gTypeGroup_MtEmberRubyPath1F)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B1F", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPathB1F, sizeof(gTypeGroup_MtEmberRubyPathB1F)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B2F", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPathB2F, sizeof(gTypeGroup_MtEmberRubyPathB2F)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B3F", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPathB3F, sizeof(gTypeGroup_MtEmberRubyPathB3F)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B1F_STAIRS", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPathB1FStairs, sizeof(gTypeGroup_MtEmberRubyPathB1FStairs)/sizeof(u16)},
    {"MAP_MT_EMBER_RUBY_PATH_B2F_STAIRS", ENCOUNTER_LAND, gTypeGroup_MtEmberRubyPathB2FStairs, sizeof(gTypeGroup_MtEmberRubyPathB2FStairs)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_LAND, gTypeGroup_ThreeIslandBerryForest, sizeof(gTypeGroup_ThreeIslandBerryForest)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_LAND, gTypeGroup_FourIslandIcefallCaveEntrance, sizeof(gTypeGroup_FourIslandIcefallCaveEntrance)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_1F", ENCOUNTER_LAND, gTypeGroup_FourIslandIcefallCave1F, sizeof(gTypeGroup_FourIslandIcefallCave1F)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_B1F", ENCOUNTER_LAND, gTypeGroup_FourIslandIcefallCaveB1F, sizeof(gTypeGroup_FourIslandIcefallCaveB1F)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_LAND, gTypeGroup_FourIslandIcefallCaveBack, sizeof(gTypeGroup_FourIslandIcefallCaveBack)/sizeof(u16)},
    {"MAP_SIX_ISLAND_PATTERN_BUSH", ENCOUNTER_LAND, gTypeGroup_SixIslandPatternBush, sizeof(gTypeGroup_SixIslandPatternBush)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM1", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom1, sizeof(gTypeGroup_FiveIslandLostCaveRoom1)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM2", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom2, sizeof(gTypeGroup_FiveIslandLostCaveRoom2)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM3", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom3, sizeof(gTypeGroup_FiveIslandLostCaveRoom3)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM4", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom4, sizeof(gTypeGroup_FiveIslandLostCaveRoom4)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM5", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom5, sizeof(gTypeGroup_FiveIslandLostCaveRoom5)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM6", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom6, sizeof(gTypeGroup_FiveIslandLostCaveRoom6)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM7", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom7, sizeof(gTypeGroup_FiveIslandLostCaveRoom7)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM8", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom8, sizeof(gTypeGroup_FiveIslandLostCaveRoom8)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM9", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom9, sizeof(gTypeGroup_FiveIslandLostCaveRoom9)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM10", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom10, sizeof(gTypeGroup_FiveIslandLostCaveRoom10)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM11", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom11, sizeof(gTypeGroup_FiveIslandLostCaveRoom11)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM12", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom12, sizeof(gTypeGroup_FiveIslandLostCaveRoom12)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM13", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom13, sizeof(gTypeGroup_FiveIslandLostCaveRoom13)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_LOST_CAVE_ROOM14", ENCOUNTER_LAND, gTypeGroup_FiveIslandLostCaveRoom14, sizeof(gTypeGroup_FiveIslandLostCaveRoom14)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_LAND, gTypeGroup_OneIslandKindleRoad, sizeof(gTypeGroup_OneIslandKindleRoad)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_LAND, gTypeGroup_OneIslandTreasureBeach, sizeof(gTypeGroup_OneIslandTreasureBeach)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_LAND, gTypeGroup_TwoIslandCapeBrink, sizeof(gTypeGroup_TwoIslandCapeBrink)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_LAND, gTypeGroup_ThreeIslandBondBridge, sizeof(gTypeGroup_ThreeIslandBondBridge)/sizeof(u16)},
    {"MAP_THREE_ISLAND_PORT", ENCOUNTER_LAND, gTypeGroup_ThreeIslandPort, sizeof(gTypeGroup_ThreeIslandPort)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_LAND, gTypeGroup_FiveIslandMeadow, sizeof(gTypeGroup_FiveIslandMeadow)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_LAND, gTypeGroup_FiveIslandMemorialPillar, sizeof(gTypeGroup_FiveIslandMemorialPillar)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_LAND, gTypeGroup_SixIslandWaterPath, sizeof(gTypeGroup_SixIslandWaterPath)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_LAND, gTypeGroup_SixIslandRuinValley, sizeof(gTypeGroup_SixIslandRuinValley)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_SEVAULT_CANYON_ENTRANCE", ENCOUNTER_LAND, gTypeGroup_SevenIslandSevaultCanyonEntrance, sizeof(gTypeGroup_SevenIslandSevaultCanyonEntrance)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_SEVAULT_CANYON", ENCOUNTER_LAND, gTypeGroup_SevenIslandSevaultCanyon, sizeof(gTypeGroup_SevenIslandSevaultCanyon)/sizeof(u16)},
    // Fishing Encounters
    {"MAP_SSANNE_EXTERIOR", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_RESORT_GORGEOUS", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_WATER_LABYRINTH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SIX_ISLAND_OUTCAST_ISLAND", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SIX_ISLAND_GREEN_PATH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TRAINER_TOWER", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    // Water Encounters
    {"MAP_SSANNE_EXTERIOR", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_CENTER", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_EAST", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_NORTH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SAFARI_ZONE_WEST", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_1F", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_CERULEAN_CAVE_B1F", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B3F", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SEAFOAM_ISLANDS_B4F", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BERRY_FOREST", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FOUR_ISLAND_ICEFALL_CAVE_BACK", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ONE_ISLAND_KINDLE_ROAD", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ONE_ISLAND_TREASURE_BEACH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_TWO_ISLAND_CAPE_BRINK", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_THREE_ISLAND_BOND_BRIDGE", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_RESORT_GORGEOUS", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_WATER_LABYRINTH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEADOW", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FIVE_ISLAND_MEMORIAL_PILLAR", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SIX_ISLAND_OUTCAST_ISLAND", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SIX_ISLAND_GREEN_PATH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SIX_ISLAND_WATER_PATH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SIX_ISLAND_RUIN_VALLEY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TRAINER_TOWER", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_SEVEN_ISLAND_TANOBY_RUINS", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},

    // Routes - Land encounters
    {"MAP_ROUTE1", ENCOUNTER_LAND, gTypeGroup_Route1, sizeof(gTypeGroup_Route1)/sizeof(u16)},
    {"MAP_ROUTE2", ENCOUNTER_LAND, gTypeGroup_Route2, sizeof(gTypeGroup_Route2)/sizeof(u16)},
    {"MAP_ROUTE3", ENCOUNTER_LAND, gTypeGroup_Route3, sizeof(gTypeGroup_Route3)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_LAND, gTypeGroup_Route4, sizeof(gTypeGroup_Route4)/sizeof(u16)},
    {"MAP_ROUTE5", ENCOUNTER_LAND, gTypeGroup_Route5, sizeof(gTypeGroup_Route5)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_LAND, gTypeGroup_Route6, sizeof(gTypeGroup_Route6)/sizeof(u16)},
    {"MAP_ROUTE7", ENCOUNTER_LAND, gTypeGroup_Route7, sizeof(gTypeGroup_Route7)/sizeof(u16)},
    {"MAP_ROUTE8", ENCOUNTER_LAND, gTypeGroup_Route8, sizeof(gTypeGroup_Route8)/sizeof(u16)},
    {"MAP_ROUTE9", ENCOUNTER_LAND, gTypeGroup_Route9, sizeof(gTypeGroup_Route9)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_LAND, gTypeGroup_Route10, sizeof(gTypeGroup_Route10)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_LAND, gTypeGroup_Route11, sizeof(gTypeGroup_Route11)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_LAND, gTypeGroup_Route12, sizeof(gTypeGroup_Route12)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_LAND, gTypeGroup_Route13, sizeof(gTypeGroup_Route13)/sizeof(u16)},
    {"MAP_ROUTE14", ENCOUNTER_LAND, gTypeGroup_Route14, sizeof(gTypeGroup_Route14)/sizeof(u16)},
    {"MAP_ROUTE15", ENCOUNTER_LAND, gTypeGroup_Route15, sizeof(gTypeGroup_Route15)/sizeof(u16)},
    {"MAP_ROUTE16", ENCOUNTER_LAND, gTypeGroup_Route16, sizeof(gTypeGroup_Route16)/sizeof(u16)},
    {"MAP_ROUTE17", ENCOUNTER_LAND, gTypeGroup_Route17, sizeof(gTypeGroup_Route17)/sizeof(u16)},
    {"MAP_ROUTE18", ENCOUNTER_LAND, gTypeGroup_Route18, sizeof(gTypeGroup_Route18)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_LAND, gTypeGroup_Route21North, sizeof(gTypeGroup_Route21North)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_LAND, gTypeGroup_Route21South, sizeof(gTypeGroup_Route21South)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_LAND, gTypeGroup_Route22, sizeof(gTypeGroup_Route22)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_LAND, gTypeGroup_Route23, sizeof(gTypeGroup_Route23)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_LAND, gTypeGroup_Route24, sizeof(gTypeGroup_Route24)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_LAND, gTypeGroup_Route25, sizeof(gTypeGroup_Route25)/sizeof(u16)},
    
    // Routes - Water encounters
    {"MAP_ROUTE1", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE19", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE20", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    
    // Routes - Fishing encounters
    {"MAP_ROUTE1", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE4", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE6", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE10", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE11", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE12", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE13", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE19", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE20", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE21_NORTH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE21_SOUTH", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE22", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE23", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE24", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ROUTE25", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},

    // Cities and Towns
    // Cities and Towns -- Fishing Encounters
    {"MAP_PALLET_TOWN", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_VIRIDIAN_CITY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_CERULEAN_CITY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_VERMILION_CITY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_CELADON_CITY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FUCHSIA_CITY", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_CINNABAR_ISLAND", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_ONE_ISLAND", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FOUR_ISLAND", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    {"MAP_FIVE_ISLAND", ENCOUNTER_FISHING, gTypeGroup_Fishing, sizeof(gTypeGroup_Fishing)/sizeof(u16)},
    // Cities and Towns -- Water Encounters
    {"MAP_PALLET_TOWN", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_VIRIDIAN_CITY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_CERULEAN_CITY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_VERMILION_CITY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_CELADON_CITY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FUCHSIA_CITY", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_CINNABAR_ISLAND", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_ONE_ISLAND", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FOUR_ISLAND", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},
    {"MAP_FIVE_ISLAND", ENCOUNTER_WATER, gTypeGroup_Surf, sizeof(gTypeGroup_Surf)/sizeof(u16)},

    // Six Island Altering Cave
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    {"MAP_SIX_ISLAND_ALTERING_CAVE", ENCOUNTER_LAND, gTypeGroup_SixIslandAlteringCave, sizeof(gTypeGroup_SixIslandAlteringCave)/sizeof(u16)},
    // ... Add all other maps from wild_encounters.json here, associating with the most relevant type group and encounter type ...
};