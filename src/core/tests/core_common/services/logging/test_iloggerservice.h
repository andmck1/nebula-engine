#pragma once

#include "core_common/services/logging/iloggerservice.h"
#include <doctest/doctest.h>

namespace NC = Nebula::Core;

TEST_CASE_TEMPLATE_DEFINE(
    "ILoggerService contract", Fixture, iloggerservice_contract
)
{
    SUBCASE("Post-condition: a new logger defaults to INFO")
    {
        Fixture fixture = Fixture("TestLogger");
        CHECK(fixture.getLevel() == NC::LoggingLevel::INFO);
    }

    SUBCASE("Post-condition: set Level applies every valid level")
    {
        for (int logLevel = NC::LoggingLevel::DEBUG;
             logLevel != NC::LoggingLevel::ERROR; logLevel++)
        {
            Fixture fixture = Fixture("TestLogger");
            CAPTURE(logLevel);
            fixture.setLevel(static_cast<NC::LoggingLevel>(logLevel));
            CHECK(fixture.getLevel() == logLevel);
        }
    }
}
