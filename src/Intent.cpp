#include "Intent.h"

Intent::Intent(const std::string &name, const std::vector<std::string> &patterns)
    : m_name(name)
    , m_patterns(patterns)
{
    compilePatternsToRegexes();
}

double Intent::getScore(const std::string &phrase) const
{

}

void Intent::compilePatternsToRegexes()
{

}
