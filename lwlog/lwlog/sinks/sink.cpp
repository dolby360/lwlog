#include "sink.h"
#include "details/formatter.h"

namespace lwlog::sinks
{
	void sink::set_pattern(std::string_view pattern)
	{
		m_pattern = pattern;
	}

	void sink::add_pattern_attribute(details::pattern_attribute attribute)
	{
		details::formatter::insert_pattern_data({
			{attribute.verbose, attribute.shortened, attribute.attribute }
			});
	}

	void sink::set_level_filter(std::initializer_list<sink_level> level_list)
	{
		m_levels.clear();
		m_levels = level_list;
	}

	void sink::disable_color()
	{
		m_should_color = false;
	}

	bool sink::should_sink(sink_level level) const
	{
		for (const auto& i : m_levels)
		{
			if (level == i || i == sink_level::all)
			{
				return true;
			}
		}

		return false;
	}

	bool sink::should_color() const
	{
		return m_should_color;
	}

	std::string sink::get_pattern() const
	{
		return m_pattern;
	}
}