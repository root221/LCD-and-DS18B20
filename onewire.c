#include "onewire.h"

/* Init OneWire Struct with GPIO information
 * param:
 *   OneWire: struct to be initialized
 *   GPIOx: Base of the GPIO DQ used, e.g. GPIOA
 *   GPIO_Pin: The pin GPIO DQ used, e.g. 5
 */
void OneWire_Init(OneWire_t* OneWireStruct, GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
	GPIOx->PUPDR = 0;
	GPIOx->PUPDR |= 1 << (GPIO_Pin * 2); // set pull up
    GPIOx->MODER = 0;                       // set input mode
    OneWireStruct->GPIOx = GPIOx;
    OneWireStruct->GPIO_Pin = GPIO_Pin;
}

/* Send reset through OneWireStruct
 * Please implement the reset protocol
 * param:
 *   OneWireStruct: wire to send
 * retval:
 *    0 -> Reset OK
 *    1 -> Reset Failed
 */
uint8_t OneWire_Reset(OneWire_t* OneWireStruct) {
    OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down
    OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
    delay(490);
    OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    delay(60);
    while(((OneWireStruct->GPIOx->IDR >> OneWireStruct->GPIO_Pin) & 1));

    delay(410);
    return 0;
}

/* Write 1 bit through OneWireStruct
 * Please implement the send 1-bit protocol
 * param:
 *   OneWireStruct: wire to send
 *   bit: bit to send
 */
void OneWire_WriteBit(OneWire_t* OneWireStruct, uint8_t bit) {
    delay(1);
    OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    if(bit == 1){
        OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down
        OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
        delay(5);
        OneWireStruct->GPIOx->MODER = 0;    // set to input mode
        delay(55);
    }

    else{
        OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down
        OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
        delay(60);
        OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    }
}

/* Read 1 bit through OneWireStruct
 * Please implement the read 1-bit protocol
 * param:
 *   OneWireStruct: wire to read from
 */
uint8_t OneWire_ReadBit(OneWire_t* OneWireStruct) {
    int value;
    int bit;
    delay(1);
    OneWireStruct->GPIOx->MODER = 0;
    OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down
    OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
    delay(5);
    OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    value = OneWireStruct->GPIOx->IDR;
    bit = (value >> OneWireStruct->GPIO_Pin) & 1;
    delay(60);
    return bit;
}


/* A convenient API to write 1 byte through OneWireStruct
 * Please use OneWire_WriteBit to implement
 * param:
 *   OneWireStruct: wire to send
 *   byte: byte to send
 */
void OneWire_WriteByte(OneWire_t* OneWireStruct, uint8_t byte) {
    for(int i=0;i<8;i++){
    		int bit = (byte >> i) & 1;
        OneWire_WriteBit(OneWireStruct,bit);
    }

}

/* A convenient API to read 1 byte through OneWireStruct
 * Please use OneWire_ReadBit to implement
 * param:
 *   OneWireStruct: wire to read from
 */
uint8_t OneWire_ReadByte(OneWire_t* OneWireStruct) {
	uint8_t value = 0;
	for(int i=0;i<8;i++){
		value >>= 1;
		if(OneWire_ReadBit(OneWireStruct))
			value |= 0x80;
	}
	return value;
}

/* Send ROM Command, Skip ROM, through OneWireStruct
 * You can use OneWire_WriteByte to implement
 */
void OneWire_SkipROM(OneWire_t* OneWireStruct) {
	OneWire_WriteByte(OneWireStruct,0xCC);// write 0xCC
}
