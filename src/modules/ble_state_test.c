#include <zephyr/kernel.h>

#define MODULE ble_state_test

#include <caf/events/module_state_event.h>
#include <caf/events/ble_common_event.h>

#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>

static bool handle_ble_peer_event(const struct ble_peer_event *evt)
{
	printk("BLE State: Event Handler has been called :) Have a nice day.\n");
	return false;
}

static bool app_event_handler(const struct app_event_header *aeh)
{

	if (is_ble_peer_event(aeh)) {
		return handle_ble_peer_event(cast_ble_peer_event(aeh));
	}

	/* Event not handled but subscribed. */
	//__ASSERT_NO_MSG(false);

	return false;
}

APP_EVENT_LISTENER(MODULE, app_event_handler);
APP_EVENT_SUBSCRIBE(MODULE, module_state_event);
APP_EVENT_SUBSCRIBE(MODULE, ble_peer_event);
