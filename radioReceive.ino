// Send data via nrf24l01+ to another nrf24l01+
//
// Using a blue pill stm32
// Using the STM32F103C8T6
//


#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>

// Pins connected to the nRF24L01+ and STM32
// Enable the transmitter or receiver mode (CE pin) 
const int nrf24_ce_pin = 9; 
// Chip select (CSN pin) 
const int nrf24_csn_pin = 10;
const int stm32_ce_pin = 8;
const int stm32_csn_pin = 7;

// Constants for the nRF24L01+
const int nrf24_payload_size = 32;
const int nrf24_channel = 90;
// Data rate (NRF24_1MBPS, NRF24_2MBPS, NRF24_250KBPS)
const int nrf24_data_rate = NRF24_1MBPS;
// Output power (NRF24_TXPOW_0DBM, NRF24_TXPOW_N6DBM, NRF24_TXPOW_N12DBM, NRF24_TXPOW_N18DBM)
const int nrf24_tx_power = NRF24_TXPOW_0DBM;
// Enable ack payloads (0 = disabled, 1 = enabled)
const int nrf24_ack_payload_en = 1;
// Enable dynamic payloads (0 = disabled, 1 = enabled)
const int nrf24_dynamic_payloads_en = 1;
// Address width (3-5)
const int nrf24_addr_width = 5;

// // Wiring between radio and stm32
// const int stm32_spi_speed = 8000000;
// const int stm32_spi_mode = SPI_MODE3;
// const int stm32_spi_bit_order = MSBFIRST;
// const int stm32_spi_data_mode = SPI_MODE0;


// Variable string for data sent to the nRF24L01+
char nrf24_data[nrf24_payload_size];

void setup(){
    // Initialise the nRF24L01+
    nRF24L01.init();
    nRF24L01.setChannel(nrf24_channel);
    nRF24L01.setDataRate(nrf24_data_rate);
    nRF24L01.setTxPower(nrf24_tx_power);
    nRF24L01.setCRCScheme(nRF24_CRC_2byte);
    nRF24L01.setPAddrWidth(nrf24_addr_width);
    nRF24L01.setPAAddr(nRF24_ADDR_P0, nRF24_ADDR_P0_SIZE, nRF24_ADDR_P0_VALUE);

    // Initialise the STM32
    pinMode(stm32_ce_pin, OUTPUT);
    pinMode(stm32_csn_pin, OUTPUT);
    digitalWrite(stm32_ce_pin, LOW);
    digitalWrite(stm32_csn_pin, HIGH);
    
    // // Initialise the SPI
    // SPI.begin();
    // SPI.setBitOrder(stm32_spi_bit_order);
    // SPI.setDataMode(stm32_spi_data_mode);
    // SPI.setClockDivider(stm32_spi_speed);

}

void loop(){
    // If data available from the nRF24L01+
    if(nRF24L01.dataReady()){
        // Read the data
        nRF24L01.read(nrf24_data, nrf24_payload_size);
        // Send the data to the STM32
        digitalWrite(stm32_ce_pin, HIGH);
        digitalWrite(stm32_csn_pin, LOW);
        SPI.transfer(nrf24_data, nrf24_payload_size);
        digitalWrite(stm32_csn_pin, HIGH);
        digitalWrite(stm32_ce_pin, LOW);
    } else {

    }

    // delay program to save power
    delay(100);
}
