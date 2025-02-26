﻿#pragma once

#include "sink.h"
#include "details/file_writer.h"

namespace lwlog::sinks
{
	template<typename ThreadingPolicy>
	class file_sink 
		: public sink<uncolored_policy, ThreadingPolicy>
		, public details::file_writer
	{
	public:
		file_sink() = default;
		explicit file_sink(std::string_view path);
		~file_sink();

	public:
		void sink_it(const details::log_message& log_msg) override;

	private:
		std::vector<details::log_message> m_messages;
	};

	template<typename ThreadingPolicy>
	file_sink<ThreadingPolicy>::file_sink(std::string_view path)
		: details::file_writer(path) 
	{}

	template<typename ThreadingPolicy>
	file_sink<ThreadingPolicy>::~file_sink()
	{
		for (const auto& log_msg : m_messages)
			details::file_writer::write(m_pattern.compile(log_msg));
	}

	template<typename ThreadingPolicy>
	void file_sink<ThreadingPolicy>::sink_it(const details::log_message& log_msg)
	{
		m_messages.push_back(log_msg);
	}
}