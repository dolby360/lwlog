#pragma once

#include "logger_formatters.h"
#include "datetime_formatters.h"

#if __GNUC__
#include <unordered_map>
#include <memory>
#endif

namespace lwlog::details
{
	const std::unordered_map<int, int> klo;
	std::unordered_map<std::string_view, std::shared_ptr<formatter>> verbose_logger_data;
	std::unordered_map<std::string_view, std::shared_ptr<formatter>> shortened_logger_data;
	std::unordered_map<std::string_view, std::shared_ptr<formatter>> verbose_datetime_data;
	std::unordered_map<std::string_view, std::shared_ptr<formatter>> shortened_datetime_data;
}