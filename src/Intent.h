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

    double getScore(const std::string &phrase) const;

private:
    void compilePatternsToRegexes();

protected:
    std::string m_name;
    std::vector<std::string> m_patterns;
    std::vector<std::pair<int, std::regex>> m_patternRegexes;
    std::map<int, std::string> m_namedGroups;
};

#endif // INTENT_H
