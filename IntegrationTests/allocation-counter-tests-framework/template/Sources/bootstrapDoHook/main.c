//===----------------------------------------------------------------------===//
//
// This source file is part of the SwiftNIO open source project
//
// Copyright (c) 2017-2018 Apple Inc. and the SwiftNIO project authors
// Licensed under Apache License v2.0
//
// See LICENSE.txt for license information
// See CONTRIBUTORS.txt for the list of SwiftNIO project authors
//
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <atomic-counter.h>
#include <hooked-functions.h>
#include <stdlib.h>

#if !__APPLE__
void free(void *ptr) {
    replacement_free(ptr);
}
void *malloc(size_t size) {
    return replacement_malloc(size);
}
void *calloc(size_t nmemb, size_t size) {
    return replacement_calloc(nmemb, size);
}
void *realloc(void *ptr, size_t size) {
    return replacement_realloc(ptr, size);
}
void *reallocf(void *ptr, size_t size) {
    return replacement_reallocf(ptr, size);
}
void *valloc(size_t size) {
    return replacement_valloc(size);
}
int posix_memalign(void **memptr, size_t alignment, size_t size) {
    return replacement_posix_memalign(memptr, alignment, size);
}
int socket(int domain, int type, int protocol) {
    return replacement_socket(domain, type, protocol);
}
int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    return replacement_accept(socket, address, address_len);
}
int accept4(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags) {
    return replacement_accept4(sockfd, addr, addrlen, flags);
}
int close(int fildes) {
    return replacement_close(fildes);
}
#endif

void swift_main(void);

int main() {
    swift_main();
}
