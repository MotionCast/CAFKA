#include <zephyr/kernel.h>

#define MODULE app_state

#include <caf/events/module_state_event.h>

#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

static bool app_event_handler(const struct app_event_header *aeh)
{
	printk("App Event Handler has been called :) Have a nice day.\n");

	/* Event not handled but subscribed. */
	//__ASSERT_NO_MSG(false);

	return false;
}

APP_EVENT_LISTENER(MODULE, app_event_handler);
APP_EVENT_SUBSCRIBE(MODULE, module_state_event);
