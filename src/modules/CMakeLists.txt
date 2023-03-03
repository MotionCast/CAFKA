#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

target_sources_ifdef(CONFIG_CAFT_APP_STATE_TEST_ENABLE
	app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/app_state_test.c)
