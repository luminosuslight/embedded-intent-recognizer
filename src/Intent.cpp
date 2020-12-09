#include "Intent.h"

#include <iostream>

Intent::Intent(const std::string &name, const std::vector<std::string> &patterns)
    : m_name(name)
    , m_patterns(patterns)
{
    compilePatternsToRegexes();
}

const std::string &Intent::getName() const
{
    return m_name;
}

double Intent::getScore(const std::string &phrase) const
{
    for (const auto &regexItem: m_patternRegexes) {
        const auto match = std::sregex_iterator(phrase.begin(), phrase.end(), regexItem.second);
        if (match != std::sregex_iterator()) {
            return regexItem.first;
        }
    }
    return 0.0;
}

void Intent::compilePatternsToRegexes()
{
    for (std::string pattern: m_patterns) {
        const int maxScore = pattern.length();
        // for named capturing patterns like "weather in <city:text>"
        std::regex group("<[\\w:]+>");
        std::regex namedGroup("<(\\w+):(\\w+)>");
        int groupIndex = 1;
        for (auto i = std::sregex_iterator(pattern.begin(), pattern.end(), group);
             i != std::sregex_iterator(); ++i) {
            const auto match = *i;
            const auto matchedString = match.str(0);
            const auto namedGroupMatch = std::sregex_iterator(matchedString.begin(), matchedString.end(), namedGroup);
            if (namedGroupMatch != std::sregex_iterator()) {
                pattern = pattern.replace(match.position(), match.length(), "<" + namedGroupMatch->str(2) + ">");
                m_namedGroups.insert({groupIndex, namedGroupMatch->str(1)});
            }
            ++groupIndex;
        }

        // for normal placeholders like "<text> weather <text>"
        pattern = std::regex_replace(pattern, std::regex("<text>\\s*"), "([\\w\\+\\-\\*\\\\,\\.:'äöüßÄÖÜ]+\\s*)*");
        pattern = std::regex_replace(pattern, std::regex("<word>"), "([\\w.,]*)");

        m_patternRegexes.push_back({maxScore, std::regex(pattern, std::regex_constants::icase)});
    }
    std::sort(m_patternRegexes.begin(), m_patternRegexes.end(),
              [](const auto &lhs, const auto &rhs) { return lhs.first > rhs.first; });
}
