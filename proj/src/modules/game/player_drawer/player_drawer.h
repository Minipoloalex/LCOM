#pragma once

// TODO: incldues
#include "../../../model/player/player.h"
#include "../../../model/brush/brush.h"

struct PlayerDrawer;
typedef struct PlayerDrawer player_drawer_t;


/**
 * @brief 
 * 
 */
player_drawer_t *(create_player_drawer)(player_type_t player_type);

/**
 * @brief 
 * 
 */
void (destroy_player_drawer)(player_drawer_t *player_drawer);

/**
 * @brief 
 * 
 * @return brush_t* 
 */
brush_t *player_drawer_get_brush(player_drawer_t *player_drawer);

/**
 * @brief 
 * 
 */
player_type_t (player_drawer_get_state)(player_drawer_t *player_drawer);

/**
 * @brief 
 * 
 */
player_t *(player_drawer_get_player)(player_drawer_t *player_drawer);
