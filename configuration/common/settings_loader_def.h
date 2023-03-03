#include <caf/events/module_state_event.h>

static inline void get_req_modules(struct module_flags *mf)
{
	module_flags_set_bit(mf, MODULE_IDX(main));
#ifdef CONFIG_CAF_BLE_ADV
	module_flags_set_bit(mf, MODULE_IDX(ble_adv));
#endif
#ifdef CONFIG_CAF_BLE_STATE
	module_flags_set_bit(mf, MODULE_IDX(ble_state));
#endif
};