# CAFKA

> Kafkaesque: having a nightmarishly complex, bizarre, or illogical quality

CAFKA is a template built around the Common Application Framework of the
nRF Connect SDK, that allows you to enable modules without manually enabling
their dependencies or configurations.


### Modules

The following modules are available, with more to come:

- CAKFA_BLE_STATE: Bluetooth LE state module
- CAFKA_BLE_ADV: Bluetooth LE advertising module


### Enabling Modules

To enable them, simply add the corresponding line to your prj.conf file.
For instance:

```
# prj.conf
CAFKA_BLE_STATE=y
```

Or better yet, add them as a dependency of your module:

```Kconfig
# src/modules/Kconfig.my_ble_module
menu "My BLE State Module"

config MY_BLE_STATE_MODULE_ENABLE
	bool "Enable custom ble state module"
	# select FEATURE
	select CAFKA_BLE_STATE
	help
	  My custom module that reacts to BLE state events.

endmenu

```

Then, add the your module to your prj.conf.

```
# prj.conf
MY_BLE_STATE_MODULE_ENABLE=y
```

### Configuration

To fine tune the configuration of any module, modify the corresponding
`Kconfig.[module].default` file located under `src/modules`.


<!-- MODULES -->
[ble_state]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_state.html
[ble_adv]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_adv.html
