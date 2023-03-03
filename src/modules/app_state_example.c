#include <zephyr/kernel.h>

#define MODULE app_state_test

#include <caf/events/module_state_event.h>
#include <bluetooth/adv_prov.h>

#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

static bool app_event_handler(const struct app_event_header *aeh)
{
	printk("App Event Handler has been called :) Have a nice day.\n");

	// Check if app is ready
	// Start advertising

	/* Event not handled but subscribed. */
	//__ASSERT_NO_MSG(false);

	return false;
}

APP_EVENT_LISTENER(MODULE, app_event_handler);
APP_EVENT_SUBSCRIBE(MODULE, module_state_event);
