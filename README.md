# CAFKA

> Kafkaesque: having a nightmarishly complex, bizarre, or illogical quality

CAFKA is a template built around the Common Application Framework of the
nRF Connect SDK, that allows you to enable modules without manually enabling
their dependencies or configurations.


### Features

The following modules are available:

- CAKFA_BLE_STATE: Bluetooth LE state module
- CAFKA_BLE_ADV: Bluetooth LE advertising module

More to come.


### Configuration

To fine tune the configuration of any module, modify the corresponding
`Kconfig.[module].default` file located under `src/modules`.


### Files

- Kconfig.defaults
- src/modules/Kconfig.caf_power_manager.default
- src/modules/Kconfig.caf_ble_adv.default


<!-- MODULES -->
[ble_state]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_state.html
[ble_adv]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/caf/ble_adv.html
