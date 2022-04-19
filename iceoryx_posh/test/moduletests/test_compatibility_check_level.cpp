// Copyright (c) 2019 by Robert Bosch GmbH. All rights reserved.
// Copyright (c) 2021 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "iceoryx_hoofs/log/logging.hpp"
#include "iceoryx_hoofs/log/logstream.hpp"
#include "iceoryx_hoofs/testing/mocks/logger_mock.hpp"
#include "iceoryx_posh/version/compatibility_check_level.hpp"

#include "test.hpp"

#include <cstdint>
#include <limits>

namespace
{
using namespace ::testing;
using namespace iox::version;

class CompatibilityCheckLevel_test : public Test
{
  public:
    void TearDown()
    {
        m_loggerMock.m_logs.clear();
    }

    Logger_Mock m_loggerMock;
};

TEST_F(CompatibilityCheckLevel_test, OffLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "a36d8dd3-1004-4000-991b-bc131d02b26e");
    auto sut = CompatibilityCheckLevel::OFF;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::OFF"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

TEST_F(CompatibilityCheckLevel_test, MajorLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "77b29d8e-0ff8-45af-8826-d391f45063df");
    auto sut = CompatibilityCheckLevel::MAJOR;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::MAJOR"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

TEST_F(CompatibilityCheckLevel_test, MinorLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "f9e7ba62-6474-4b41-91a0-725d6a6e7baf");
    auto sut = CompatibilityCheckLevel::MINOR;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::MINOR"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

TEST_F(CompatibilityCheckLevel_test, PatchLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "5f77f683-3de0-438d-af0c-424a1b24b99d");
    auto sut = CompatibilityCheckLevel::PATCH;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::PATCH"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

TEST_F(CompatibilityCheckLevel_test, CommitIdLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "55bc3dbe-9a85-4cf7-9f9e-441c72e7c895");
    auto sut = CompatibilityCheckLevel::COMMIT_ID;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::COMMIT_ID"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

TEST_F(CompatibilityCheckLevel_test, BuildDateLeadsToCorrectString)
{
    ::testing::Test::RecordProperty("TEST_ID", "c0259873-8840-48ac-8f3c-f99e8bcc7691");
    auto sut = CompatibilityCheckLevel::BUILD_DATE;

    {
        auto logstream = iox::log::LogStream(m_loggerMock);
        logstream << sut;
    }

    ASSERT_THAT(m_loggerMock.m_logs.size(), Eq(1U));
    EXPECT_THAT(m_loggerMock.m_logs[0].message, Eq("CompatibilityCheckLevel::BUILD_DATE"));
    EXPECT_THAT(m_loggerMock.m_logs[0].level, Eq(iox::log::LogLevel::kWarn));
}

} // namespace
