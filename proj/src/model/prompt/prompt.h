#include <stdlib.h>

#include <lcom/lcf.h>
#include "../../modules/resources/prompts.h"
#include "../../devices/serial_port/serial_port.h"
#include "../../devices/serial_port/serial_port.h"

/**
 * @brief Generate a prompt by picking a random one from the prompts array
 * 
 * @param prompt 
 * @return int 
 */
uint8_t (prompt_generate)(char *prompt);

/**
 * @brief Get the word from index object
 * 
 * @param index 
 * @param prompt 
 * @return int 
 */
int (get_word_from_index)(uint8_t index, char *prompt);
