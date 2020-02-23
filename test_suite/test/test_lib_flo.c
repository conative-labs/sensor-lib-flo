/*
  Copyright (C) 2020 Conative Labs
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include "unity.h"
#include "lib_flo.h"

#include "mock_lib_flo_config_test.h"

#define MAGIC_NUMBER_DEFAULT 0x67


void setUP(void)
{
}

void tearDown(void)
{
}

void test_lib_flo_init_withMagicNumberAlreadySet(void)
{
  lib_flo_params_t params;

  params.flow_factor = 13221;
  params.magic_number = MAGIC_NUMBER_DEFAULT; // mock the magic number 
  lib_flo_init(&params);

  TEST_ASSERT_EQUAL_FLOAT(13221, params.flow_factor);
}

void test_lib_flo_init_withoutMagicNumberAlreadySet(void)
{
  lib_flo_params_t params;

  params.flow_factor = 13221;
  lib_flo_init(&params);

  TEST_ASSERT_EQUAL_FLOAT(4.5, params.flow_factor);
}

void test_lib_flo_cmd_Read(void)
{
  lib_flo_params_t params;
  lib_flo_reading_t reading;
  pulses_counter = 450;
  start_pulses_interrupt_Expect();
  get_current_time_mili_ExpectAndReturn(0);
  mili_delay_Expect(1000);
  stop_pulses_interrupt_Expect();
  get_current_time_mili_ExpectAndReturn(1000);
  lib_flo_init(&params);

  lib_flo_cmd(flo_read, &reading);

  TEST_ASSERT_EQUAL_FLOAT(100, reading);
}

void test_lib_flo_cmd_ReadZero(void)
{
  lib_flo_params_t params;
  lib_flo_reading_t reading;
  pulses_counter = 0;
  start_pulses_interrupt_Expect();
  get_current_time_mili_ExpectAndReturn(0);
  mili_delay_Expect(1000);
  stop_pulses_interrupt_Expect();
  get_current_time_mili_ExpectAndReturn(1000);
  lib_flo_init(&params);

  lib_flo_cmd(flo_read, &reading);

  TEST_ASSERT_EQUAL_FLOAT(0, reading);
}

void test_lib_flo_cmd_FloCal(void)
{
  lib_flo_params_t params;
  lib_flo_factor_t temp = 60;
  lib_flo_init(&params);

  lib_flo_cmd(flo_cal_factor, &temp);

  TEST_ASSERT_EQUAL_FLOAT(temp, params.flow_factor);
}


void test_lib_flo_cmd_FloCalGetNotCalib(void)
{
  lib_flo_params_t params;
  char temp;
  lib_flo_init(&params);

  lib_flo_cmd(flo_cal_get, &temp);

  TEST_ASSERT_EQUAL_INT(0, temp);
}

void test_lib_flo_cmd_FloCalGetCalib(void)
{
  lib_flo_params_t params;
  char temp;
  lib_flo_init(&params);
  params.flow_factor = 12; // any number than default
  lib_flo_cmd(flo_cal_get, &temp);

  TEST_ASSERT_EQUAL_INT(1, temp);
}

void test_lib_flo_cmd_Clear(void)
{
  lib_flo_params_t params;

  lib_flo_init(&params);
  params.flow_factor = 13221;
  params.magic_number = 0x50;
  lib_flo_cmd(flo_cal_clear, NULL);

  TEST_ASSERT_EQUAL(0x50, params.magic_number);
  TEST_ASSERT_EQUAL_FLOAT(4.5, params.flow_factor);
}

void test_lib_flo_cmd_Reset(void)
{
  lib_flo_params_t params;

  lib_flo_init(&params);
  params.flow_factor = 13221;
  params.magic_number = 0x50;
  lib_flo_cmd(flo_reset, NULL);

  TEST_ASSERT_EQUAL(MAGIC_NUMBER_DEFAULT, params.magic_number);
  TEST_ASSERT_EQUAL_FLOAT(4.5, params.flow_factor);
}
