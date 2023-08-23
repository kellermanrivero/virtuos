// Copyright (c) 2023., Kellerman Rivero <krsloco@gmail.com>
//
// SPDX-License-Identifier: MIT

#include <limits.h>
#include <kernel/klibc/stdlib.h>
#include <kernel/dtb/dtb.h>
#include <kernel/kmalloc.h>

extern const volatile unsigned int dtb;

void __kos_main() {
  struct fdt_header *header = (struct fdt_header *) &dtb;
  debug_msg("Welcome to K OS!");
  debug_msg("By Kellerman Rivero");
  debug_msg("Running in a %d bit processor", (sizeof(uintptr_t) / sizeof(char)) * CHAR_BIT);
  parse_device_tree(header);
  kmalloc_init();
}