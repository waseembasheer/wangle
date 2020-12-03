/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>
#include <glog/logging.h>
#include <folly/ssl/OpenSSLPtrTypes.h>

namespace wangle {

std::vector<std::pair<SSL_SESSION*, size_t>> getSessions();

std::pair<SSL_SESSION*, size_t> getSessionWithTicket();

folly::ssl::SSLSessionUniquePtr createPersistentTestSession(
    std::pair<SSL_SESSION*, size_t> session);

std::string getSessionData(SSL_SESSION* s, size_t expectedLength);

bool isSameSession(
    std::pair<SSL_SESSION*, size_t> lhs,
    std::pair<SSL_SESSION*, size_t> rhs);

}
