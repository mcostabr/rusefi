/**
 * @file	efiGpio.cpp
 *
 * @date Sep 26, 2014
 * @author Andrey Belomutskiy, (c) 2012-2016
 */

#include "main.h"
#if EFI_GPIO
#include "efiGpio.h"
#include "io_pins.h"
#if EFI_PROD_CODE || defined(__DOXYGEN__)
#include "gpio_helper.h"
#endif

pin_output_mode_e OUTPUT_MODE_DEFAULT = OM_DEFAULT;

// todo: clean this mess, this should become 'static'/private
engine_pins_s enginePins;

NamedOutputPin::NamedOutputPin() : OutputPin() {
	name = NULL;
}

NamedOutputPin::NamedOutputPin(const char *name) : OutputPin() {
	this->name = name;
}

OutputPin::OutputPin() {
	modePtr = &OUTPUT_MODE_DEFAULT;
#if EFI_PROD_CODE || defined(__DOXYGEN__)
	port = NULL;
	pin = 0;
#endif
	currentLogicValue = INITIAL_PIN_STATE;
}

bool OutputPin::isInitialized() {
#if EFI_PROD_CODE || defined(__DOXYGEN__)
	return port != NULL;
#else
	return false;
#endif
}

void OutputPin::setValue(int logicValue) {
	doSetOutputPinValue2(this, logicValue);
}

bool OutputPin::getLogicValue() {
	return currentLogicValue;
}

void OutputPin::unregister() {
#if EFI_PROD_CODE || defined(__DOXYGEN__)
	port = NULL;
#endif
}

void OutputPin::setDefaultPinState(pin_output_mode_e *outputMode) {
#if EFI_GPIO || defined(__DOXYGEN__)
	pin_output_mode_e mode = *outputMode;
	assertOMode(mode);
	this->modePtr = outputMode;
#endif
	setValue(false); // initial state
}

#endif /* EFI_GPIO */
