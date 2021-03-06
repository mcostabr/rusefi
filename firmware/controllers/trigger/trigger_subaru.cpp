/**
 * @file	trigger_subaru.cpp
 *
 * @date Sep 10, 2015
 * @author Andrey Belomutskiy, (c) 2012-2016
 */

#include "trigger_subaru.h"

/**
 * This trigger is also used by Nissan and Mazda
 */
void initialize36_2_2_2(TriggerShape *s) {
	s->initialize(FOUR_STROKE_CAM_SENSOR, true);

	float wide = 30 * 2;
	float narrow = 10 * 2;

	s->isSynchronizationNeeded = true;
	s->setTriggerSynchronizationGap(0.5);
	s->setSecondTriggerSynchronizationGap(1);

	float base = 0;

	for (int i = 0; i < 12; i++) {
		s->addEvent(base + narrow / 2, T_PRIMARY, TV_RISE);
		s->addEvent(base + narrow, T_PRIMARY, TV_FALL);
		base += narrow;
	}

	s->addEvent(base + wide / 2, T_PRIMARY, TV_RISE);
	s->addEvent(base + wide, T_PRIMARY, TV_FALL);
	base += wide;

	for (int i = 0; i < 15; i++) {
		s->addEvent(base + narrow / 2, T_PRIMARY, TV_RISE);
		s->addEvent(base + narrow, T_PRIMARY, TV_FALL);
		base += narrow;
	}

	s->addEvent(720 - wide - wide / 2, T_PRIMARY, TV_RISE);
	s->addEvent(720 - wide, T_PRIMARY, TV_FALL);

	s->addEvent(720 - wide / 2, T_PRIMARY, TV_RISE);
	s->addEvent(720, T_PRIMARY, TV_FALL);
	s->useOnlyPrimaryForSync = true;
}
