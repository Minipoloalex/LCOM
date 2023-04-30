#pragma once

#include <lcom/lcf.h>
#include <stdint.h>
#include "uart.h"
#include "queue.h"
/**
 * @brief 
 * 
 */
int (ser_init)(uint16_t base_addr, uint32_t baud_rate, uint8_t word_length, uint8_t stop_bit, 
int8_t parity);
/**
 * @brief 
 * 
 */
int (ser_subscribe_int)(uint8_t *bit_no);
/**
 * @brief 
 * 
 */
int (ser_unsubscribe_int)();
/**
 * @brief 
 * 
 */
void (ser_ih_fifo)();
/**
 * @brief 
 * 
 */
int (ser_write_fifo_control_default)();
/**
 * @brief 
 * 
 */
int (ser_add_byte_to_transmitter_queue)(uint8_t c);
/**
 * @brief 
 * 
 */
int (ser_read_bytes_from_receiver_queue)();
/**
 * @brief 
 * 
 */
int (ser_write_char)(uint8_t c);
/**
 * @brief 
 * 
 */
int (ser_read_char)(uint8_t *c);
