# CAFKA

> Kafkaesque: having a nightmarishly complex, bizarre, or illogical quality

CAFKA is a template built around the Common Application Framework of the
nRF Connect SDK, that allows you to enable modules without manually enabling
their dependencies or configurations.

#### Disclaimer
CAFKA is still experimental so you may run into some issues.
You may post them under this repository and you will receive advice.

### Modules

The following modules are available, with more to come:

- CAKFA_BLE_STATE: Bluetooth LE state module ([docs][ble_state])
- CAFKA_BLE_ADV: Bluetooth LE advertising module ([docs][ble_adv])
- CAFKA_BLE_BOND: Bluetooth LE bond module ([docs][ble_bond])
- CAFKA_POWER_MANAGER: Power manager module ([docs][power_mgr])
- CAFKA_SETTINGS_LOADER: Settings loader module ([docs][settings])
- CAFKA_LEDS: LED module ([docs][leds])

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


## Example Modules

The following modules are included as placeholders that are supposed to react to different events:

- app_state_example.c: Barebones module that listens to app_state_event.
- ble_state_example.c: Listens to BLE peer_state_event.


If you are using this repository as a template, you will want to either overwrite these
or delete them, as well as their usages in `src/modules/CMakeLists.txt`, and their respective
Kconfig files under `src/modules/`.


### Configuration

To fine tune the configuration of any module, modify the corresponding
`Kconfig.[module].default` file located under `src/modules`.

You should of course also be able to directly set them in `prj.conf`.


## Licence

This template is currently under the GNU General Public License v2.
If you are interested in using this project under a different licence, simply raise an issue.


<!-- MODULES -->
[ble_state]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_state.html
[ble_adv]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_adv.html
[ble_bond]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_bond.html
[power_mgr]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/power_manager.html
[settings]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/settings_loader.html
[leds]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/leds.html
