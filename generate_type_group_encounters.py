import json

# Map encounter type keys to C enum names and type group
encounter_type_map = {
    "land_mons": ("ENCOUNTER_LAND", "gTypeGroup_Normal"),
    "water_mons": ("ENCOUNTER_WATER", "gTypeGroup_WaterIce"),
    "fishing_mons": ("ENCOUNTER_FISHING", "gTypeGroup_WaterIce")
}

type_group_size = {
    "gTypeGroup_Normal": "sizeof(gTypeGroup_Normal)/sizeof(u16)",
    "gTypeGroup_WaterIce": "sizeof(gTypeGroup_WaterIce)/sizeof(u16)"
}

with open("src/data/wild_encounters.json") as f:
    data = json.load(f)

print("// Example associations (add more as needed)")
print("static const TypeGroupEncounter gTypeGroupEncounters[] = {")
print("    // Associations for all maps in wild_encounters.json")

for entry in data["wild_encounter_groups"][0]["encounters"]:
    map_name = entry.get("map")
    base_label = entry.get("base_label", "")
    if not map_name or "FireRed" not in base_label:
        continue
    for key, (encounter_type, type_group) in encounter_type_map.items():
        if key in entry:
            size_str = type_group_size[type_group]
            print(f'    {{"{map_name}", {encounter_type}, {type_group}, {size_str}}},')

print("    // ... Add all other maps from wild_encounters.json here, associating with the most relevant type group and encounter type ...")
print("};")