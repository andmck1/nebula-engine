#include "application/application.h"

#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[])
{
    Application app;
    app.run(argc, argv);
    return 0;
}
