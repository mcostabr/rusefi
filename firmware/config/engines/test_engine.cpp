/**
 * @file	test_engine.cpp
 *
 * set_engine_type 26
 *
 * @date Nov 14, 2014
 * @author Andrey Belomutskiy, (c) 2012-2016
 */

#include "engine.h"
#include "test_engine.h"

EXTERN_ENGINE;

void setTestEngineConfiguration(DECLARE_ENGINE_PARAMETER_F) {
//	setOperationMode(engineConfiguration, FOUR_STROKE_CRANK_SENSOR);
//	engineConfiguration->trigger.type = TT_TOOTHED_WHEEL;

	setOperationMode(engineConfiguration, FOUR_STROKE_CAM_SENSOR);
	engineConfiguration->trigger.type = TT_ONE_PLUS_ONE;

	trigger_config_s *triggerConfig = &engineConfiguration->trigger;
	triggerConfig->customTotalToothCount = 60;
	triggerConfig->customSkippedToothCount = 0;
	engineConfiguration->useOnlyRisingEdgeForTrigger = true;

	engineConfiguration->mafAdcChannel = EFI_ADC_NONE;
	engineConfiguration->vbattAdcChannel = EFI_ADC_NONE;

	setWholeIatCorrTimingTable(0 PASS_ENGINE_PARAMETER);

	engineConfiguration->ignitionMode = IM_ONE_COIL;
	setConstantDwell(3 PASS_ENGINE_PARAMETER); // 50% duty cycle @ 5000 rpm

	board_configuration_s *bc = &engineConfiguration->bc;
	bc->malfunctionIndicatorPin = GPIO_UNASSIGNED;

	boardConfiguration->ignitionPins[0] = GPIOC_7; // #1
	boardConfiguration->ignitionPins[1] = GPIO_UNASSIGNED; // #2
	boardConfiguration->ignitionPins[2] = GPIO_UNASSIGNED; // #3
	boardConfiguration->ignitionPins[3] = GPIO_UNASSIGNED; // #4
	boardConfiguration->ignitionPins[4] = GPIO_UNASSIGNED; // #5
	boardConfiguration->ignitionPins[5] = GPIO_UNASSIGNED; // #6

	boardConfiguration->logicAnalyzerPins[0] = GPIO_UNASSIGNED;
	boardConfiguration->logicAnalyzerPins[1] = GPIO_UNASSIGNED;
	boardConfiguration->logicAnalyzerPins[2] = GPIO_UNASSIGNED;
	boardConfiguration->logicAnalyzerPins[3] = GPIO_UNASSIGNED;

	engineConfiguration->hasCltSensor = false;
	engineConfiguration->hasIatSensor = false;

}
