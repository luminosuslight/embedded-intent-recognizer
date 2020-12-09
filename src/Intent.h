#ifndef INTENT_H
#define INTENT_H

#include <map>
#include <regex>
#include <string>
#include <vector>

struct PatternRegex {
    int maxScore = 0;
    std::regex regex;
    std::map<int, std::string> namedGroups;
};


class Intent
{
public:
    Intent(const std::string &name, const std::vector<std::string> &patterns);

    const std::string &getName() const;

    /**
     * @brief Intent::getScore returns a score that says how well this intent suits the input phrase
     * @param phrase the input phrase
     * @return a score greater than or equal 0
     */
    double getScore(const std::string &phrase) const;

private:
    /**
     * @brief Intent::compilePatternsToRegexes compiles the domain specific language used for the patterns to
     * actual regex instances.
     */
    void compilePatternsToRegexes();

protected:
    std::string m_name;
    std::vector<std::string> m_patterns;
    std::vector<PatternRegex> m_patternRegexes;
};

#endif // INTENT_H
