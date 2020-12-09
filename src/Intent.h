#ifndef INTENT_H
#define INTENT_H

#include <map>
#include <regex>
#include <string>
#include <vector>


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
    std::vector<std::pair<int, std::regex>> m_patternRegexes;
    std::map<int, std::string> m_namedGroups;
};

#endif // INTENT_H
