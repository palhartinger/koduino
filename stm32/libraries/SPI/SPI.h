
#ifndef SPI_h
#define SPI_h

#include "Arduino.h"


#define SPI_MODE0 0x02
#define SPI_MODE1 0x00
#define SPI_MODE2 0x03
#define SPI_MODE3 0x01

#define SPI_CLOCK_DIV2		SPI_BaudRatePrescaler_2
#define SPI_CLOCK_DIV4		SPI_BaudRatePrescaler_4
#define SPI_CLOCK_DIV8		SPI_BaudRatePrescaler_8
#define SPI_CLOCK_DIV16		SPI_BaudRatePrescaler_16
#define SPI_CLOCK_DIV32		SPI_BaudRatePrescaler_32
#define SPI_CLOCK_DIV64		SPI_BaudRatePrescaler_64
#define SPI_CLOCK_DIV128	SPI_BaudRatePrescaler_128
#define SPI_CLOCK_DIV256	SPI_BaudRatePrescaler_256

/**
 * @brief SPI library (call with global object `SPI`)
 * @details 
 */
class SPIClass {
private:
	static SPI_InitTypeDef SPI_InitStructure;

	static bool SPI_Bit_Order_Set;
	static bool SPI_Data_Mode_Set;
	static bool SPI_Clock_Divider_Set;
	static bool SPI_Enabled;

  static uint8_t SCK, MISO, MOSI;
  static uint8_t afSCK, afMISO, afMOSI;

public:
	/**
	 * @brief Change default SCK, MISO and MOSI pins
	 * @details You will need to look at the datasheet to fill in the alternate function (AF) numbers
	 * 
	 * @param SCK Default is `PA5`
	 * @param afSCK 
	 * @param MISO Default is `PB4`
	 * @param afMISO 
	 * @param MOSI Default is `PB5`
	 * @param afMOSI 
	 */
	static void setPins(uint8_t SCK, uint8_t afSCK, uint8_t MISO, uint8_t afMISO, uint8_t MOSI, uint8_t afMOSI);

	/**
	 * @brief Start SPI peripheral and configure pins
	 * @details 
	 */
	static void begin();

	/**
	 * @brief Close SPI
	 * @details 
	 */
	static void end();

	/**
	 * @brief Sets the bit-order for data
	 * @details 
	 * 
	 * @param ord One of `MSBFIRST`, `LSBFIRST`
	 */
	static void setBitOrder(uint8_t ord);

	/**
	 * @brief Sets the SPI mode
	 * @details See the [Wikipedia SPI page](http://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus) for details on these modes
	 * 
	 * @param mode One of `SPI_MODE<x>`, where `<x>` can be 0, 1, 2, 3
	 */
	static void setDataMode(uint8_t mode);

	/**
	 * @brief Sets the clock divider (with respect to the system clock)
	 * @details 
	 * 
	 * @param div One of `SPI_CLOCK_DIV<x>` where `<x>` can be 2, 4, 8, 16, 32, 64, 128, 256
	 */
	static void setClockDivider(uint8_t div);

	/**
	 * @brief Transfers one byte over the SPI bus, both sending and receiving
	 * @details Make sure you drive chip select low before calling this
	 * 
	 * @param _data Byte to send
	 * @return Returns the byte received from the slave
	 */
	static uint8_t transfer(uint8_t _data);

	static void attachInterrupt();
	static void detachInterrupt();

	static bool isEnabled(void);
};

extern SPIClass SPI;

#endif
