// Playing around with Boost Log
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

namespace foo
{
    BOOST_LOG_NAMED_SCOPE("Foo namespace");
void init()
{
   logging::add_file_log(
           keywords::file_name = "sample_%N.log",
           keywords::rotation_size = 1024,
           keywords::time_based_rotation = sinks::file::rotation_at_time_point(0,0,0),
           keywords::format = "[Timeline:: %Timeline%][%Tag%]: %Message%"
           );
    // set filtering for which types to log
    //logging::core::get()->set_filter
    //(
    //    logging::trivial::severity > logging::trivial::info
    //);

    logging::core::get()->add_global_attribute("Timeline", attrs::timer());
    logging::core::get()->add_global_attribute("Scope", attrs::named_scope());
   // logging::core::get()->add_global_attribute("Severity", attrs::timer());
}
}
namespace foo
{
    BOOST_LOG_NAMED_SCOPE("Foo namespace2");
void dostuff()
{
    BOOST_LOG_FUNCTION();
    init();
    logging::add_common_attributes();
    logging::core::get()->add_global_attribute("Scope", attrs::named_scope());

    using namespace logging::trivial;
    src::severity_logger<severity_level> log;

    BOOST_LOG_SEV(log, trace) <<"Trace log: "<<__func__ << " " << __LINE__;
    BOOST_LOG_SEV(log, debug) <<"debug log";
    BOOST_LOG_SEV(log, info) << "Info log";
    BOOST_LOG_NAMED_SCOPE("Second half");
    BOOST_LOG_SEV(log, warning) << "warning log";
    BOOST_LOG_SEV(log, error) <<  "error log";
    BOOST_LOG_SEV(log, fatal) << "fatal log";
}

}
int main()
{
    foo::dostuff();
}
