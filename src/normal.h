/*
 * normal.h
 * Functions for handling idevices in normal mode
 *
 * Copyright (c) 2010 Joshua Hill. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef IDEVICERESTORE_NORMAL_H
#define IDEVICERESTORE_NORMAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <libimobiledevice/lockdown.h>
#include <libimobiledevice/libimobiledevice.h>

struct normal_client_t {
	idevice_t device;
	lockdownd_client_t client;
	const char* ipsw;
	plist_t tss;
};


int normal_check_mode(const char* uuid);
int normal_check_device(const char* uuid);
int normal_client_new(struct idevicerestore_client_t* client);
void normal_client_free(struct idevicerestore_client_t* client);
int normal_open_with_timeout(struct idevicerestore_client_t* client);
int normal_enter_recovery(struct idevicerestore_client_t* client);
int normal_get_cpid(const char* uuid, uint32_t* cpid);
int normal_get_bdid(const char* uuid, uint32_t* cpid);
int normal_get_ecid(const char* uuid, uint64_t* ecid);

#ifdef __cplusplus
}
#endif

#endif
