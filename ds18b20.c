#include "ds18b20.h"

/* Send ConvT through OneWire with resolution
 * param:
 *   OneWire: send through this
 *   resolution: temperature resolution
 * retval:
 *    0 -> OK
 *    1 -> Error
 */
int DS18B20_ConvT(OneWire_t* OneWire, DS18B20_Resolution_t resolution) {
    OneWire_WriteByte(OneWire,0x44);
	return 0;
}

/* Read temperature from OneWire
 * param:
 *   OneWire: send through this
 *   destination: output temperature
 * retval:
 *    0 -> OK
 *    1 -> Error
 */
uint8_t DS18B20_Read(OneWire_t* OneWire, int *destination) {
	OneWire_WriteByte(OneWire, 0xBE);
	int lsb = OneWire_ReadByte(OneWire);
	int msb = OneWire_ReadByte(OneWire);
	*destination = (msb << 8) + lsb;
    return 0;
}

/* Set resolution of the DS18B20
 * param:
 *   OneWire: send through this
 *   resolution: set to this resolution
 * retval:
 *    0 -> OK
 *    1 -> Error
 */
uint8_t DS18B20_SetResolution(OneWire_t* OneWire, DS18B20_Resolution_t resolution) {
	int a = 0;
	switch(resolution){
	case 9:
		a = 0x1f;
		break;
	case 10:
		a = 0x3f;
		break;
	case 11:
		a = 0x5f;
		break;
	case 12:
		a = 0x7f;
		break;
	default:
		break;
	}
	OneWire_WriteByte(OneWire, 0x4E);
	OneWire_WriteByte(OneWire, 0x7F);
	OneWire_WriteByte(OneWire, 0xFF);
	OneWire_WriteByte(OneWire, a   );
	return 0;
}

/* Check if the temperature conversion is done or not
 * param:
 *   OneWire: send through this
 * retval:
 *    0 -> OK
 *    1 -> Not yet
 */
uint8_t DS18B20_Done(OneWire_t* OneWire) {
	return !OneWire_ReadBit(OneWire);

}
