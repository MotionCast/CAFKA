# CAFKA: CAF Kconfig Assistant

> Kafkaesque: having a nightmarishly complex, bizarre, or illogical quality

A template built around the Common Application Framework of the nRF Connect SDK,
that makes it possible to enable CAF modules with one line of configuration each,
providing sensible defaults to make your life easier.



#### Disclaimer
CAFKA is still experimental so you may run into some issues.
You may post them under this repository and you will receive advice.



## Installing

**As a Git submodule (recommended):**

```
git submodule add https://github.com/mocast/CAFKA.git src/cafka
cd src/cafka
git checkout master
```

Then, in your Kconfig, add this to include the CAFKA modules

```
menu "CAFKA"
rsource "src/cafka/Kconfig"
endmenu
```



## Modules

The following modules are available, with more to come:


| Category             | CAF Module                  | Setting               |
|----------------------|-----------------------------|-----------------------|
| Bluetooth Low Energy & LTE                                                 |
|                      | [BLE Advertising][ble_adv]  | CAKFA_BLE_ADV         |
|                      | [BLE Bond][ble_bond]        | CAKFA_BLE_BOND        |
|                      | [BLE State][ble_state]      | CAKFA_BLE_STATE       |
|                      | BLE State/Adv/Bond          | CAKFA_BLE_ALL         |
|                      | Network State               | -                     |
| Power Manager                                                              |
|                      | [Power Manager][power_mgr]  | CAFKA_POWER_MANAGER   |
|                      | BLE State                   | -                     |
|                      | Buttons KeepAlive           | -                     |
| System                                                                     |
|                      | [SMP DFU via BLE][smp]      | CAFKA_BLE_SMP         |
|                      | [Settings Loader][settings] | CAFKA_SETTINGS_LOADER |
|                      | Shell                       | -                     |
| Input/Output Devices                                                       |
|                      | [Buttons][buttons]          | CAFKA_BUTTONS         |
|                      | [Click Detector][click]     | CAFKA_CLICK_DETECTOR  |
|                      | [Sensor Manager][sensors]   | CAFKA_SENSOR_MANAGER  |
|                      | Sensor Data Agg.            | -                     |
|                      | [GPIO LEDs][leds]           | CAFKA_LEDS_GPIO       |
|                      | [PWM LEDs][leds]            | CAFKA_LEDS_PWM        |


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
`Kconfig.[module].default` file located under `modules`.

You should of course also be able to directly set them in `prj.conf`.



## Licence

This template is licensed under the 3-Clause BSD License.




<!-- MODULES -->
[ble_state]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_state.html
[ble_adv]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_adv.html
[ble_bond]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_bond.html
[power_mgr]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/power_manager.html
[settings]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/settings_loader.html
[leds]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/leds.html
[buttons]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/buttons.html
[click]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/click_detector.html
[smp]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_smp.html
[sensors]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/sensor_manager.html
