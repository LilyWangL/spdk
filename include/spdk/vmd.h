/*-
 *   BSD LICENSE
 *
 *   Copyright (c) Intel Corporation.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Intel Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** \file
 * VMD driver public interface
 */

#ifndef SPDK_VMD_H
#define SPDK_VMD_H

#include "spdk/stdinc.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "spdk/config.h"
#include "spdk/env.h"

/*
 * Takes an input VMD D-BDF, probes it and attaches to it. The resulting vmd
 * adapter is placed in a vmd container. If input BDF is NULL, then all VMD
 * probed is consumed in the application VMD container list.
 *
 * \param vmd_bdf VMD BDF
 *
 * \return number of VMD devices available in the system
 */
int spdk_vmd_probe(struct spdk_pci_addr *vmd_bdf);

/*
 * Returns a list of nvme devices found on the given vmd pci BDF.
 *
 * \param vmd_addr pci BDF of the vmd device to return end device list
 * \param nvme_list buffer of up to MAX_VMD_TARGET to return spdk_pci_device array.
 *
 * \return Returns count of nvme device attached to input VMD.
 */
int spdk_vmd_pci_device_list(struct spdk_pci_addr vmd_addr, struct spdk_pci_device *nvme_list);

#ifdef __cplusplus
}
#endif

#endif /* SPDK_VMD_H */