#include "Benchmark.h"

#include "lwlog/lwlog.h"
#include "lwlog/logger.h"
#include "lwlog/sinks/stdout_color_sink.h"

#include <iostream>

int main()
{
	auto console = std::make_shared<
		lwlog::logger<
			lwlog::default_storage_policy,
			lwlog::single_threaded_policy,
			lwlog::sinks::stdout_color_sink
		>
	>("CONSOLE");

	console->add_pattern_attribute({ "{ATTR}", "%*", "NEW_ATTRIBUTE" });
	console->set_level_filter(lwlog::level::info | lwlog::level::debug | lwlog::level::critical);
	console->set_pattern("^br_red^[%T] [%n]^reset^ ^green^[%l]^reset^: ^br_cyan^%v^reset^ {ATTR}");

	{
		Timer timer("timer");
		console->critical("First critical message");
	}

	return 0;
}
