#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

target_sources_ifdef(
	CONFIG_CAFKA_APP_STATE_EXAMPLE app PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/app_state_example.c
)

target_sources_ifdef(
	CONFIG_CAFKA_BLE_STATE_EXAMPLE app PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/ble_state_example.c
)
