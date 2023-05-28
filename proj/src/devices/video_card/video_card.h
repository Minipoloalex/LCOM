#include <lcom/lcf.h>
#include <stdint.h>
#include <math.h>
#include "../controllers/vbe.h"
#include "../../modules/resources/font.h"
#include "../../model/button/button.h"
#include "../../model/position/position.h"
#include "../../modules/game/player_drawer/player_drawer.h"
#include "../../model/brush/brush.h"
#include "../../model/guess/guess.h"
#include "../../model/sprite/sprite.h"

// guess word
#define GUESS_POS_X 30
#define GUESS_POS_Y 800

// guess box
#define GUESS_BOX_X 15
#define GUESS_BOX_Y 780
#define GUESS_BOX_WIDTH 1024-30 //hres-30
#define GUESS_BOX_HEIGHT 40+FONT_HEIGHT

// round timer
#define ROUND_TIMER_X 900
#define ROUND_TIMER_Y 800

// colors
#define TRANSPARENT 0x000001
#define BLACK 0X000000
#define WHITE 0XFFFFFF

/**
 * @brief 
 * 
 */
bool (buffers_need_update)();
/**
 * @brief 
 * 
 */
void (set_needs_update)(bool value);
/**
 * @brief calls the functions to enter in graphics mode and map the physical memory to the virtual address space of the process
 * 
 * @param mode submode to enter in
 * 
 */
int (setup_video_mode)(uint16_t mode);
/**
 * @brief Draws a rectangle on a specified area of the screen with a specified color
 * 
 * @return returns 0 upon success, 1 otherwise
 */
int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
/**
 * @brief Draws a rectangle with a specified color in a specified area of the buffer
 * 
 */
int (vg_draw_rectangle_to_buffer)(uint8_t *buffer, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
/**
 * @brief Draws a circle on a specified area of the screen with a specified color
 * 
 */
int (vg_draw_circle)(uint16_t x, uint16_t y, uint16_t radius, uint32_t color);
/**
 * @brief Draws a circle with a specified color in a specified area of the buffer
 * 
 */
int (vg_draw_circle_to_buffer)(uint8_t *buffer, uint16_t x, uint16_t y, uint16_t radius, uint32_t color);

/**
 * @brief Draws a sprite to a specified position
 * 
 */
int (vg_draw_sprite)(Sprite *sprite, uint16_t x, uint16_t y);

/**
 * @brief Draws a string to the screen
 * 
 * @param string string to be drawn
 * @param x x position of the string
 * @param y y position of the string
 * @param font font to be used
 */
int (vg_draw_text)(char *string, uint16_t x, uint16_t y, Sprite* font[]);

/**
 * @brief Draws the guess word to the screen
 * 
 * @param gwt guess word to be drawn
 * @param x x position of the guess word
 * @param y y position of the guess word
 * @param font font to be used
 * @return int returns 0 upon success, 1 otherwise
 */
int (vg_draw_guess)(guess_word_t *gwt, uint16_t x, uint16_t y, Sprite* font[]);

/**
 * @brief Draws a array of buttons to the screen
 * 
 * @param buttons array of buttons to be drawn
 * @param font font to be used, for the button's text
 * @param icons icons to be used, for the button's icon
 * 
 * @return returns 0 upon success, 1 otherwise
 */
int (vg_draw_buttons)(buttons_array_t *buttons, Sprite* font[], Sprite* icons[]);

/**
 * @brief 
 * 
 */
int (vg_buffer_flip)();
/**
 * @brief 
 * 
 */
int (vg_clear_buffer)(uint8_t buffer);

/**
 * @brief 
 * 
 */
int (vg_draw_buffer)(uint8_t * buffer);
/**
 * @brief 
 * 
 */
int (vg_clear_buffers)();

/**
 * @brief returns the size of the VRAM
 * 
 */
unsigned (get_vram_size)();
/**
 * @brief returns the vertical resolution of the video mode used
 * 
 */
uint16_t (get_v_res)();
/**
 * @brief returns the horizontal resolution of the video mode used
 * 
 */
uint16_t (get_h_res)();
/**
 * @brief returns the number of bytes per pixel of the video mode used
 * 
 */
uint8_t (get_bytes_per_pixel)();
