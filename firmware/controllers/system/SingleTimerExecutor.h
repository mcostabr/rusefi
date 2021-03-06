/**
 * @file SingleTimerExecutor.h
 *
 * @date: Apr 18, 2014
 * @author Andrey Belomutskiy, (c) 2012-2016
 */

#ifndef SINGLETIMEREXECUTOR_H_
#define SINGLETIMEREXECUTOR_H_

#include "scheduler.h"
#include "event_queue.h"

class Executor {
public:
	Executor();
	void schedule(scheduling_s *scheduling, efitime_t nowUs, int delayUs, schfunc_t callback, void *param);
	void scheduleByTime(scheduling_s *scheduling, efitimeus_t timeUs, schfunc_t callback, void *param);
	void onTimerCallback();
private:
	EventQueue queue;
	bool reentrantFlag;
	void doExecute();
	void scheduleTimerCallback();
};

void initSignalExecutorImpl(void);

#endif /* SINGLETIMEREXECUTOR_H_ */
