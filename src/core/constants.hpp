#pragma once

#define WINDOW_TITLE                        "LUNA"

#define WINDOW_WIDTH                        640
#define WINDOW_HEIGHT                       480

#define SOLOUD_TIME_CORRECTION              0.0431383125
#define SOLOUD_ENGINE_SLEEP_DURATION        10

#define FILE_PATH_BEAT_MAP                  "C:/Users/jayso/Documents/Github/luna/build/map_generator/beat_map.json"
#define FILE_PATH_MUSIC_FILE                "C:/Users/jayso/Documents/Github/luna/support/kick_loop.wav"

#define TILE_COLOR_SIZE_W                   64
#define TILE_COLOR_SIZE_H                   TILE_COLOR_SIZE_W
#define TILE_SPEED                          5.0f

#define LANE_X_POS_1                        (WINDOW_WIDTH / 2) - (TILE_COLOR_SIZE_W * 2)
#define LANE_X_POS_2                        (WINDOW_WIDTH / 2) + (TILE_COLOR_SIZE_W * 2)
#define LANE_X_POS_3                        (WINDOW_WIDTH / 2) - (TILE_COLOR_SIZE_W)
#define LANE_X_POS_4                        (WINDOW_WIDTH / 2) + (TILE_COLOR_SIZE_W)